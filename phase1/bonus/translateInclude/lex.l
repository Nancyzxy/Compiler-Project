/* 将include的文件打印出来 */
%option noyywrap
%x IFILE

%{
struct buffstack {
  struct buffstack *prev; /* 上一个文件信息 */
  YY_BUFFER_STATE bufferstate; /* 缓冲区 */
  int lineno; /* 行号 */
  char *filename; /* 文件名 */
  FILE *f; /* 当前文件 */
} *curbstk = 0;

char *curfilename; /* 当前输入文件的名字 */
int newfile(char *fn);
int popfile(void);
%}

%%
^"#"[ \t]*include[ \t]*[\"<]   { // #include
  BEGIN(IFILE); 
}

<IFILE>[^ \t\n\">]+ { // 匹配文件名
  { 
    int c;
    while((c=input()) && c != '\n');
  }
  yylineno++;
  if(!newfile(yytext)){
    yyterminate();
  }
  printf("start read include file:%10s.\n", curbstk->filename);
  BEGIN(INITIAL); // flex本身会定义的`INITIAL`起始条件
}

<IFILE>.|\n { //  处理IFILE起始条件中错误输入的情况
  fprintf(stderr, "行号：%8d 错误的include语法\n", yylineno);
  yyterminate();
}

<<EOF>> { // <<EOF>>匹配输入文件的结束。
  printf("\nfinish reading include file:%10s.\n", curbstk->filename);
  if(!popfile()){ // 当文件结束时pop
    yyterminate();
  }
}

^. { // 打印行号
  fprintf(yyout, "%8d %s", yylineno, yytext); 
}

^\n { // 行号+1
  fprintf(yyout, "%8d %s", yylineno++, yytext);
}

\n {
  ECHO;
  yylineno++;
}

. { // ECHO会将字符原样输出到yyout
  ECHO;
}
%%
int main(int argc, char ** argv){
  if(argc < 2){
    fprintf(stderr, "need filename\n");
    return 1;
  }
  if(newfile(argv[1])) yylex();
}

int newfile(char *fn){
  FILE *f = fopen(fn, "r");
  struct buffstack *bstk = malloc(sizeof(struct buffstack));

  /* 异常处理 文件打不开*/
  if(!f) {
    perror(fn);
    return 0;
  }
  /* 空间不够 */
  if(!bstk){
    perror("malloc");
    exit(1);
  }

  /* 当前状态 */
  if(curbstk){
    curbstk->lineno = yylineno;
    bstk->prev = curbstk;
  }

  /* cur_info */
  bstk->bufferstate = yy_create_buffer(f, YY_BUF_SIZE);
  bstk->f = f;
  bstk->filename = fn;
  yy_switch_to_buffer(bstk->bufferstate);
  curbstk = bstk;
  yylineno = 1;
  curfilename = fn;
  return 1;
}

int popfile(void){
  struct buffstack *bstk = curbstk;
  struct buffstack *prevbstk;

  if(!bstk){
    return 0;
  }

  /* 删除当前文件 */
  fclose(bstk->f);
  yy_delete_buffer(bstk->bufferstate);

  /* 切换上个文件 */
  prevbstk = bstk->prev;
  free(bstk);

  if(!prevbstk){
    return 0;
  }

  yy_switch_to_buffer(prevbstk->bufferstate);
  curbstk=prevbstk;
  yylineno = curbstk->lineno;
  curfilename = curbstk->filename;
  return 1;
}

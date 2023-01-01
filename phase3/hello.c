
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* new_place(int* a)
{
    char* buff = malloc(32);
    a[0] = 4;
    sprintf(buff, "%d", a[0]);
    return buff;
}
int main()
{
    int a[10] = {0};    
    printf("%s", new_place(a));
    return 0;
}

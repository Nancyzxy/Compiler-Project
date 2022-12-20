import pathlib
import re
import subprocess


def execute(file):
  out = subprocess.check_output(['bin/splc', file])
  return out.decode().strip()

def compare_result(output0,output1):
  out = subprocess.check_output(['diff', output0, output1,'-b'])
  return out.decode().strip()


def check_right():
  data = pathlib.Path('project2_testcases/project2_testcases/github_test')
  for spl in data.glob('*.spl'):
    spl = spl.__str__()
    execute(spl)
    m = re.match(r'(.+).spl', spl)
    diff = compare_result(m.group(1)+".out","out.txt")
    print(spl+": " + diff)
    
def check_our():
      data = pathlib.Path('project2_testcases/project2_testcases/student_test')
      for spl in data.glob('*.spl'):
        spl = spl.__str__()
        execute(spl)
        m = re.match(r'(.+).spl', spl)
        diff = compare_result(m.group(1)+".out","out.txt")
        print(spl+": " + diff)

print("right:")
check_right()
# check_our()
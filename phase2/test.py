import pathlib
import re
import subprocess


DATA = pathlib.Path('project1_testcases/testcases')
DATA = pathlib.Path('project1_testcases/testcases')

def execute(file):
  out = subprocess.check_output(['bin/splc', file])
  return out.decode().strip()

def compare_result(output0,output1):
  out = subprocess.check_output(['diff', output0, output1,'-b'])
  return out.decode().strip()


def check_right():
  data = DATA/'github_test'
  #data = DATA/'student_test'
  for spl in data.glob('*.spl'):
    spl = spl.__str__()
    execute(spl)
    m = re.match(r'(.+).spl', spl)
    diff = compare_result(m.group(1)+".out","out.txt")
    print(spl+": " + diff)

def check_wrong():
  data = DATA/'wrong'
  for spl in data.glob('*.spl'):
    spl = spl.__str__()
    execute(spl)
    m = re.match(r'(.+).spl', spl)
    diff = compare_result(m.group(1)+".out","out.txt")
    print(spl+": " + diff)

def check_our():
      data = pathlib.Path('test')
      for spl in data.glob('*.spl'):
        spl = spl.__str__()
        execute(spl)
        m = re.match(r'(.+).spl', spl)
        diff = compare_result(m.group(1)+".out","out.txt")
        print(spl+": " + diff)

print("right:")
check_right()
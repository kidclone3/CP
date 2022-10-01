import re 
import os
import shutil
from settings import *

reg = re.compile(r'\"/problem/algorithm/.*\/\"')
if os.path.isdir('result'):
    shutil.rmtree("result")
os.mkdir("result")
# reg.findall()
for i in pages:
    ans = set()
    with open('data/out{}.html'.format(i), 'rt') as f:
        lines = iter(f.readlines())
        for line in lines:
            # print(line)
            tmp = reg.findall(line)
            if tmp != []:
                # print(tmp)
                tmp = tmp[0][9:-1]
                ans.add(tmp)
                # print(tmp)
    # print(ans)
    with open('result/task{}.txt'.format(i), 'w+') as f2:
        for j in ans:
            print(PROBLEM_URL.format(j), file=f2)



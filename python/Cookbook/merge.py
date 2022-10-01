from settings import *
ans = []
with open('merged.txt', 'w+') as wr:
    for i in pages:
        with open('result/task{}.txt'.format(i), "rt") as f:
            for line in iter(f.readlines()):
                print(line[:-1], file=wr) # remove \n 
                # ans.add(line)
                # print(line[:-1])

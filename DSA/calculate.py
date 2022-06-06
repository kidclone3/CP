fw_ans = 0
with open("cerr/slow_st/1e5.txt", "r") as f:
    for i in range(1000):
        fw_ans = fw_ans + int(f.readline())
print(fw_ans)
print(fw_ans/1000)
from sys import stdin

bank = {}

for line in stdin:
    query, num = line.split()
    num = int(num)
    if (query == "D"):
        if ("D" not in bank.items()):
            bank["D"] = num
        else:
            bank["D"] += num
    if (query == "W"):
        if ("D" not in bank.items() or bank["D"] < num):
            print("none")
        else:
            bank["D"] -= num
print(bank['D'])
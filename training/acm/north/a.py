a = input().split('.').lowercase()
# a += "."
print("yes" if a[len(a)-1] == "py" and len(a) > 1 else "no")

normal = ["great!", "don't think so", "not bad", "don't touch me", "cool"]
grumpy = ["don't even", "no way", "are you serious?", "worse", "terrible", "go die in a hole"]
for i in range(0, 10):
    print(i)
    s = input()
    if (s in normal):
        print("normal")
        break
    else: 
        if (s in grumpy):
            print("grumpy")
            break
def divideCandy(bags):
    bags.sort()
    sum1 = 0
    sum2 = 0
    for i in bags:
        sum2 += i
    if sum2 % 2 == 1:
        return False
    ans = sum2 // 2
    for i in range (0, len(bags) - 1):
        if (sum1 + bags[i] < ans): 
            sum1 += bags[i]
        else:
            if (sum1 + bags[i] == ans):
                return True;
            else:
                if (bags[0] == 1):
                    return True;
                else:
                    return False;

    return False

bags = [1, 1, 1, 1, 2, 2]
print(divideCandy(bags))
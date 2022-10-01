def findCouple(filename):
    
    with open(filename) as f:
        inp = f.read().split()
        # print(inp)
        # print(type(inp[0]))
        dt = dict()
        for x in inp:
            if x not in dt:
                dt[x[::-1]] = True
            else:
                if (x != x[::-1]):
                    # return x, x[::-1]
                    if (x > x[::-1]):
                        return x[::-1], x
                    else:
                        return x, x[::-1]
    
    return 'None','None'

# print(findCouple("/home/delus/Documents/mycodes/python/Advance_Programming/in"))
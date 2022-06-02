def range(*args):
    if len(args) == 1:
        start = 0
        stop = args[0]
    elif len(args) == 2:
        start = args[0]
        stop = args[1]

    current = start
    while current < stop:
        yield current
        current += 1


def squares(items):
    for item in items:
        yield item**2


print(*range(5))
print(*squares(range(5)))

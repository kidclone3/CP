s = "print(l(b, a))"

a = 3

ll = """
def l(a, b):
    return a + b
"""

pp = """
def p(a,b):
    print("asdasdasdasd")
    return l(a,b)
"""

f = {"b": a, "a": a}

g = {}

exec(ll, f, g)
exec(pp, f, g)

print(g)

ocho = ll + pp
cmd = "print(p(3,2))"

exec(ocho + cmd)
# exec("print(dir())", g)
# exec("print(p(3,2))", g)
# exec("print(dir())", f, g)
# print(g['l'](3,3))

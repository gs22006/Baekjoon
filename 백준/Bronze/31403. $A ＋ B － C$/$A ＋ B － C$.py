def cw(a, b, c):
    sr = float(a + b) - float(c)
    nr = float(a) + float(b) - float(c)
    return sr, nr
a = input()
b = input()
c = input()
sr, nr = cw(a, b, c)
print(int(nr))
print(int(sr))

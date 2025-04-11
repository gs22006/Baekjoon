def c(a, o, b):
    if o == '+':
        return a + b
    elif o == '-':
        return a - b
    elif o == '*':
        return a * b
    elif o == '/':
        q = abs(a) // abs(b)
        if (a < 0) ^ (b < 0):
            return -q
        else:
            return q

ex = input().split()
k1, o1, k2, o2, k3 = ex
k1, k2, k3 = int(k1), int(k2), int(k3)
r1 = c(c(k1, o1, k2), o2, k3)
r2 = c(k1, o1, c(k2, o2, k3))
print(min(r1, r2))
print(max(r1, r2))

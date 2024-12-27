import sys

d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
cv = {c: i for i, c in enumerate(d)}

def b2d(ns, b):
    v = 0
    for c in ns:
        v = v * b + cv[c]
    return v

def d2b(v, b):
    if v == 0:
        return "0"
    r = []
    while v > 0:
        v, rem = divmod(v, b)
        r.append(d[rem])
    return "".join(reversed(r))

def m():
    d = sys.stdin.read().strip().split('\n')
    t = int(d[0].strip())
    i = 1
    for _ in range(t):
        ib, ob, ns = d[i].split()
        i += 1
        ib = int(ib)
        ob = int(ob)
        dv = b2d(ns, ib)
        cv = d2b(dv, ob)
        print(f"{ib} {ns}")
        print(f"{ob} {cv}\n")

if __name__ == "__main__":
    m()

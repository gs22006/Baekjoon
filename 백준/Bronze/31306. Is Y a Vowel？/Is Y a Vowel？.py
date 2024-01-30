def cv(w):
    v = set("aeiou")
    c1 = sum(1 for ch in w if ch in v)
    c2 = c1 + w.count('y')
    print(c1, c2)

ew = input()
cv(ew)

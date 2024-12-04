n = int(input())
e = int(input())
ml = list(map(int, input().split()))

ts = 0

if e % 2 == 0:
    for m in ml:
        ts += m ** e
else:
    for m in ml:
        if m > 0:
            ts += m ** e

print(ts)

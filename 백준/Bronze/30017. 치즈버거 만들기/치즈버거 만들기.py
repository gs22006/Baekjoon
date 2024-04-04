a, b = map(int, input().split())

if a - 1 <= b:
    print(a * 2 - 1)
else:
    print(b * 2 + 1)
a, b, c, d, e = map(int, input().split())

if 4 * e <= a + b + c + d:
    print(0)
else:
    print(4 * e - a - b - c - d)
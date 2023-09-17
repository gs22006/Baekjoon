a, b = map(int, input().split())

if a * b % 2 == 0:
    print(a * b // 2, end = '')
    print(".0")
else:
    print(a * b // 2, end = '')
    print(".5")
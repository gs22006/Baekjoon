a, b, c = map(int, input().split())

if a*b<a+b*c:
    print(1)
elif a*b>a+b*c:
    print(2)
else:
    print(0)
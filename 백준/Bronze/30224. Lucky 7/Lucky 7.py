n = int(input())
c7 = '7' in str(n)
d7 = n % 7 == 0

if not c7 and not d7:
    print(0)
elif not c7 and d7:
    print(1)
elif c7 and not d7:
    print(2)
else:
    print(3)

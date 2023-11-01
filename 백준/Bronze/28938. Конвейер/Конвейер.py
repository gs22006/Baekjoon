n = int(input())
s = sum(map(int, input().split()))

if s < 0:
    print("Left")
elif s > 0:
    print("Right")
else:
    print("Stay")

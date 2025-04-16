n = int(input())
ws = list(map(int, input().split()))
t = sum(ws)
print("yes" if t % 3 == 0 else "no")

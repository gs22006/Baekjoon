n = map(int, input().split())
a = list(map(float, input().split()))
sum = 0

for x in a:
	sum += x * x * x

print(sum ** (1/3))
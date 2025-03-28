a, b, c = map(int, input().split())

if a > b:
	a, b = b, a

if a + c <= b:
	print((a + c) * 2)
else:
	print((a + b + c) // 2 * 2)
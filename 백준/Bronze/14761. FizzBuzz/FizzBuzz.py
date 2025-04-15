a, b, c = map(int, input().split())

for x in range(1, c + 1):
	if x % a == 0 and x % b == 0:
		print('FizzBuzz')
	elif x % a == 0:
		print('Fizz')
	elif x % b == 0:
		print('Buzz')
	else:
		print(x)
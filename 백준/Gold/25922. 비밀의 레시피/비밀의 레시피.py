import sys
n = int(input())
Y = 2**31 - 1;
print("? %d"%Y)
sys.stdout.flush()
q = int(input())
a = []

print("!", end = ' ')

n += 1

for x in range(n):
    a.append(q % Y)
    sys.stdout.flush()
    q //= Y

for x in range(n):
    print(a[x], end = ' ')
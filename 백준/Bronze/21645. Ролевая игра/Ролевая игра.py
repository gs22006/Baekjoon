n, m, k = map(int, input().split())

if m < k:
    print(n * (m // k + m))
else:
    print(n * (m // k + k - 1))
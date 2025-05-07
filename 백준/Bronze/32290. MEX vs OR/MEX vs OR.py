def f(l, r, x):
    s = set()
    for i in range(l, r+1):
        s.add(i | x)
    m = 0
    while m in s:
        m += 1
    return m

if __name__=='__main__':
    l, r, x = map(int, input().split())
    print(f(l, r, x))

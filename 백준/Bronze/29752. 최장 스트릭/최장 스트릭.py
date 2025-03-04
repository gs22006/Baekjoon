def s():
    import sys
    i = sys.stdin.readline

    n = int(i().strip())
    pr = list(map(int, i().split()))

    cs = 0
    ms = 0

    for p in pr:
        if p > 0:
            cs += 1
            ms = max(ms, cs)
        else:
            cs = 0

    print(ms)
s()
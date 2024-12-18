def s():
    bs = list(map(int, input().split()))
    dn = [1, 5, 10, 20, 50, 100]
    
    ts = [b * d for b, d in zip(bs, dn)]
    mt = max(ts)
    cs = [i for i, t in enumerate(ts) if t == mt]
    
    if len(cs) > 1:
        fb = min(bs[i] for i in cs)
        for i in cs:
            if bs[i] == fb:
                print(dn[i])
                return
    else:
        print(dn[cs[0]])
        
s()

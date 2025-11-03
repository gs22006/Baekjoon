n,k=map(int,input().split())
print(*[n if x*2>n+1 else 1 for x in map(int,input().split())])

import sys
i = sys.stdin.readline

def m():
    n, d = map(int, i().split())
    g = [i().strip() for _ in range(n)]
    if d == 1:
        mp = {'d':'q','b':'p','q':'d','p':'b'}
    else:
        mp = {'d':'b','b':'d','q':'p','p':'q'}
    for r in g:
        print(''.join(mp[c] for c in r))

if __name__ == '__main__':
    m()

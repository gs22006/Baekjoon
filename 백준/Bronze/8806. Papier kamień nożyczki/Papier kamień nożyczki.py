def rps(z, tc):
    rs = []
    for c in tc:
        x1, y1, z1 = c[0]
        x2, y2, z2 = c[1]
        pa = x1 * y2 + y1 * z2 + z1 * x2
        pg = x2 * y1 + y2 * z1 + z2 * x1
        if pa > pg:
            rs.append("ADAM")
        elif pa < pg:
            rs.append("GOSIA")
        else:
            rs.append("=")
    return rs

z = int(input())
tc = []
for _ in range(z):
    x1, y1, z1 = map(float, input().split())
    x2, y2, z2 = map(float, input().split())
    tc.append([(x1, y1, z1), (x2, y2, z2)])

rs = rps(z, tc)
for r in rs:
    print(r)

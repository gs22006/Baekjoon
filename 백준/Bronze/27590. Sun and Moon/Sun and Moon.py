def next_ecl(ds, ys, dm, ym):
    y = 0
    while (y + ds) % ys or (y + dm) % ym:
        y += 1
    return y

ds, ys = map(int, input().split())
dm, ym = map(int, input().split())

print(next_ecl(ds, ys, dm, ym))

sab = int(input().strip())
ma, fab, mb = map(int, input().strip().split())

ft = ma + fab + mb

if ft >= sab or sab <= 240:
    print("high speed rail")
else:
    print("flight")

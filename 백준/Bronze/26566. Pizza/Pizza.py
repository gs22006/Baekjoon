import math

n = int(input())

for i in range(n):
    A1, P1 = map(int, input().split())
    R1, P2 = map(int, input().split())

    if P1 * (math.pi * R1 ** 2) > P2 * A1 :
        print("Whole pizza")
    else:
        print("Slice of pizza")

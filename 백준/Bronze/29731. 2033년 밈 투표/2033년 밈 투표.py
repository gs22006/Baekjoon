n = int(input())
p = [
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
]
h = False

for _ in range(n):
    c = input()
    if c not in p:
        h = True
        break

print("Yes" if h else "No")

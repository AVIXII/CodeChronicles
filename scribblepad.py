from functools import reduce

def solve():
    input()
    print(reduce(lambda x, y: min(abs(x), abs(y)), [int(x) for x in input().split()]))

for _ in range(1):
    solve()
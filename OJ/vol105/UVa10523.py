# UVa 10523 - Very Easy!!!
# Solution: Compute the answer as told, might be good to simplify or expand in paper
# by jennyga

import sys


def solve( n, a ):
    ans, base = 0, a
    for i in range(1, n + 1):
        ans += i * base
        base *= a
    return ans

line = sys.stdin.readline()
while line:
    n, a = map(int, line.split())
    sys.stdout.write(str(solve(n, a)) + '\n')
    line = sys.stdin.readline()

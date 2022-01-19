# UVa 10925 - Krakovia
# Solution: Use big integers then proceed as usual
# by jennyga

import sys, math



tc = 1
line = sys.stdin.readline()
while line:
    n, f = map(int, line.split())
    if n == 0: break
    total = 0
    for i in range(n):
        total += int(sys.stdin.readline())
    print('Bill #', tc, ' costs ', total, ': each friend should pay ', total//f, '\n', sep='')
    tc += 1
    line = sys.stdin.readline()

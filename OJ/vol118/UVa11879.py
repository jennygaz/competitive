# UVa 11879 - Multiple of 17
# Solution: Simulate the process as asked, using big integers, or directly test the number modulo 17
# by jennyga

import sys


n = int(sys.stdin.readline())
while n != 0:
    if n % 17 == 0:
        print(1)
    else:
        print(0)
    n = int(sys.stdin.readline())

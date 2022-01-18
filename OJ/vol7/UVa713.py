# UVa 713 - Adding Reversed Numbers
# Solution: Do as told: Read numbers, reverse them, add them, reverse the answer, print
# by jennyga

import sys


tc = int(sys.stdin.readline())
while tc:
    tc -= 1
    a, b = sys.stdin.readline().split()
    a, b = map( int, [a[::-1], b[::-1]])
    c = str(a + b)
    c = str(int(c[::-1]))
    sys.stdout.write(c + "\n")
    

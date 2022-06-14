import sys, math


values = [[int(y) for y in x.replace('\n', '').split()] for x in sys.stdin.read().split('-999999') if x]
for val in values:
    if len(val) == 0:
        continue
    z, p, n = val[0], None, None
    for a in val:
        if a == 0:
            if z < a: z = a
            p, n = None, None
            continue
        elif a < 0:
            t = n
            n = a if p is None else p * a
            p = None if t is None else t * a
        else:
            n = None if n is None else n * a
            p = a if p is None else p * a
        z = n if n is not None and z < n else z
        z = p if p is not None and z < p else z
    print(z)

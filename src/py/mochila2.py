from __future__ import print_function
import numpy as np
import sys


def print_input(items, W):
    print(len(items), W)
    for i in items:
        print(i[0], i[1])

def random_items(n, pmin, pmax, wmin, wmax):
    if pmin > pmax:
        print("error: en random_items, pmin > pmax",
              file=sys.stderr)
        sys.exit(1)
    return [x for x in zip(np.random.randint(pmin, pmax, size=n),
                           np.random.randint(wmin, wmax, size=n))]



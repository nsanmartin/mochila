#!/usr/bin/env python3

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



def main(params):
    items = random_items(int(params[0]), 1, 49, 1, 49)
    print_input(items, params[1])

    
if __name__ == "__main__":
    # execute only if run as a script
    if len(sys.argv) != 3:
        print("Uso: ./mochila n W")
    else:
        main(sys.argv[1:])



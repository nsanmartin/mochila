#!/usr/bin/env python
import sys
import mochila2 as m2


def main(params):
    n = int(params[0])
    W = params[1]
    items = m2.random_items(n, 1, 49, 1, 49)
    m2.print_input(items, W)
    
if __name__ == "__main__":
    # execute only if run as a script
    if len(sys.argv) != 3:
        print("Uso: ./mochila n W")
    else:
        main(sys.argv[1:])



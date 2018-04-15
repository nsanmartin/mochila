#!/usr/bin/env python
import sys
import mochila2 as m2


def main(params):
    n = int(params[0])
    print n,n-1
    for i in range(1,n):
        print 1,1
    print n-1,n-1
    
if __name__ == "__main__":
    # execute only if run as a script
    if len(sys.argv) != 2:
        print("Falta n")
    else:
        main(sys.argv[1:])



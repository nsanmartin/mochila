#!/usr/bin/env python

import sys

def mochila_fuerza_bruta(pesos, precios, W):
    return


def generar_subconjuntos(pre, conj):

    if len(conj) == 1:
        return [pre + conj] + [pre]
    pre0 = pre[:]
    pre.append(conj[0])
    res = []
    res = generar_subconjuntos(pre, conj[1:]) \
          + generar_subconjuntos(pre0,conj[1:])
    return res


def main(n):
    res = generar_subconjuntos([], range(1,n))
    for i,s in enumerate(res):
        print("{}".format(s))

main(int(sys.argv[1]) + 1)

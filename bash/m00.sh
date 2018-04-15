#!/bin/bash

# Genero muestras entre n=2  a n=25
# para W=50  a W=1000 (cada 50)
#
# En total 12500
# es decir 25 * 25 * 50
#         ns * casos * Ws 

for ((W=50; W < 1000; W+=50)); do
    for i in {0..25}
    do ./bash/muestrear.sh  -W $W ./build/ttime 2 1 25
    done > muestras/W${W}n2-25
done

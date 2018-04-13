#!/bin/bash

STEP=10000
TIMES=25

if [ -z $1 ]; then
    echo muestra-n-fijo.sh: uso: $0 n
else
    n=$1
    for (( W=STEP; W < STEP*TIMES; W += STEP)); do
        ../py/muestra2.py $n $W| ../build/ttime
    done
fi

#!/bin/bash

STEP=1
TIMES=25

if [ -z $1 ]; then
    echo muestra-n-fijo.sh: uso: $0 W
else
    W=$1
    for (( n=STEP; n < STEP*TIMES; n += STEP)); do
        ../py/muestra2.py $n $W| ../build/ttime
    done
fi

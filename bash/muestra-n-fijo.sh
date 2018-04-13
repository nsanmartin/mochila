#!/bin/bash

STEP=11
TIMES=25
PROG=$1
n=$2

if [ $PWD == bash ]; then
    BASE_DIR=$(dirname $PWD)
else
    BASE_DIR=$PWD
fi

MUESTRA=${BASE_DIR}/py/muestra2.py

CMD=${BASE_DIR}/build/${PROG}
if [ ! -f $CMD ]; then
    echo falta compilar el programa: make ${PROG}
else if [ $# -ne 2 ]; then
         echo muestra-n-fijo.sh: uso: $0 PROG n
     else
         for (( W=STEP; W < STEP*TIMES; W += STEP)); do
             ${MUESTRA} $n $W| ${CMD}
             if [ $? -ne 0 ]; then break; fi
         done
     fi
fi

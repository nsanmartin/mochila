#!/bin/bash

STEP=11
TIMES=25
PROG=$1
VAR=$STEP 
CONST=$2
MUESTRA=${BASE_DIR}/py/muestra2.py

if [ $PWD == bash ]; then BASE_DIR=$(dirname $PWD); else BASE_DIR=$PWD; fi



while getopts "nW" opt; do
        case $opt in
            n)
                echo "n fijo"
                ;;
            W)
                echo "W fijo"
                ;;
            \?)
                echo "Invalid option: -$OPTARG" >&2
                OPTIND=1
                return 1
                ;;
            :)
                echo "Option -$OPTARG requires an argument." >&2
                OPTIND=1
                return 1
                ;;
        esac
done
OPTIND=1



CMD=${BASE_DIR}/build/${PROG}
if [ ! -f $CMD ]; then
    echo falta compilar el programa: make ${PROG}
else if [ $# -ne 2 ]; then
         echo >&2 muestra-n-fijo.sh: 
         echo >&2 uso: $0 PROG W
     else
         for (( VAR=STEP; VAR < STEP*TIMES; VAR += STEP)); do
             ${MUESTRA} $VAR $CONST| ${CMD}
             if [ $? -ne 0 ]; then break; fi
         done
     fi
fi

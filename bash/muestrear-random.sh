#!/bin/bash
if [ $(basename $PWD) == bash ]
then BASE_DIR=$(dirname $PWD); else BASE_DIR=$PWD; fi
MUESTRA=${BASE_DIR}/py/muestra2.py

print_help () {
    progs=$(ls $BASE_DIR/build)
    printf "uso:\t$0 PROG n W\n"
    printf "\tPROG debe ser uno de: "
    echo ${progs[*]}
}

PROG=$1

CMD=${BASE_DIR}/build/${PROG}

if [ ! -f $CMD ]; then
    echo "no encuentro CMD=${BASE_DIR}/build/${PROG}"
    echo falta compilar el programa: make ${PROG}
else if [ $# -ne 3 ]; then
         print_help
     else
         n=$2
         W=$3
         while [ $? -eq 0 ]; do
             ${MUESTRA} $((RANDOM%$n+1)) $((RANDOM%$W+1)) | ${CMD}
         done
     fi
fi



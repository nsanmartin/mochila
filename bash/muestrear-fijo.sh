#!/bin/bash
if [ $(basename $PWD) == bash ]
then BASE_DIR=$(dirname $PWD); else BASE_DIR=$PWD; fi
MUESTRA=${BASE_DIR}/py/muestra2.py

print_help () {
    progs=$(ls $BASE_DIR/build)
    printf "uso: $0 OPT1 CONST OPT2 CONST [VECES]\n"
    printf "\t -n NUM \t n esta fijo en NUM\n"
    printf "\t -W NUM \t W esta fijo en NUM\n\n"
    printf "PROG debe ser uno de: "
    echo ${progs[*]}
    printf "si falta VECES es 33\n"
}

VECES=33
n=0
W=0

while getopts ":n:W:h" opt; do
        case $opt in
            n)
                n=$OPTARG
                ;;
            W)
                W=$OPTARG
                ;;
            h)
                print_help
                exit 0
                ;;
            \?)
                echo "opci'on inv'alida: -$OPTARG" >&2
                print_help

                exit 1
                ;;
            :)
                echo "Option -$OPTARG requires an argument." >&2
                OPTIND=1
                exit 1
                ;;
        esac
done

shift $(($OPTIND -1 ))


PROG=$1
CMD=${PROG}
if [ ! -z $2 ]; then
    VECES=$2
fi
if [ ! -f $CMD ]; then
    echo falta compilar el programa: make ${PROG}
else if [ $# -lt 1 ]; then
         print_help
     else if [ $W -ne 0 ]; then # W es fijo
              for (( VAR=1; VAR < VECES; VAR++)); do
                       ${MUESTRA} $n $W | ${CMD}
                       if [ $? -ne 0 ]; then break; fi
              done
          fi
     fi
fi


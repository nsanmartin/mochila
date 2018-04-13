#!/bin/bash
if [ $PWD == bash ]; then BASE_DIR=$(dirname $PWD); else BASE_DIR=$PWD; fi
MUESTRA=${BASE_DIR}/py/muestra2.py

print_help () {
    progs=$(ls $BASE_DIR/build)
    printf "uso: $0 OPT CONST PROG DESDE CADA [VECES]\n"
    printf "\t -n NUM \t n esta fijo en NUM\n"
    printf "\t -W NUM \t W esta fijo en NUM\n\n"
    printf "PROG debe ser uno de: "
    echo ${progs[*]}
    printf "n y W deben ser uno fijo y otro no.\n"
    printf "si falta VECES es 33\n"
}

VECES=33
n=0
W=0

while getopts ":n:W:h" opt; do
        case $opt in
            n)
                echo "n fijo"
                n=$OPTARG
                ;;
            W)
                echo "W fijo"
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

if [ "$n" == "$W" ]; then
    print_help
    exit 1
fi

PROG=$1
DESDE=$2
CADA=$3
if [ ! -z $4 ]; then VECES=$4 ; fi
CMD=${BASE_DIR}/build/${PROG}
if [ ! -f $CMD ]; then
    echo falta compilar el programa: make ${PROG}
else if [ $# -lt 3 ]; then
         print_help
     else if [ $W -ne 0 ]; then # W es fijo
                   for (( VAR=DESDE; VAR < DESDE+CADA*VECES; VAR += CADA)); do
                       ${MUESTRA} $VAR $W | ${CMD}
                       if [ $? -ne 0 ]; then break; fi
                   done
                   
          else # n es fijo
              for (( VAR=DESDE; VAR < DESDE+CADA*VECES; VAR += CADA)); do
                  ${MUESTRA} $n $VAR | ${CMD}
                  if [ $? -ne 0 ]; then break; fi
              done
          fi
     fi
fi


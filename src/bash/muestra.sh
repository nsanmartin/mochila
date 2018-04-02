#!/bin/bash

../py/mochila.py $((RANDOM%25+1)) $((RANDOM%250+1)) |
    ../build/tentrada-salida

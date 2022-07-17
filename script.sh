#!/bin/bash

compilec
rm -rf ./saida.txt

for i in {1..100}
do
    ./build
    
    if [ $i -lt 100 ]
    then
        echo -n ", " >> ./saida.txt
    fi
done
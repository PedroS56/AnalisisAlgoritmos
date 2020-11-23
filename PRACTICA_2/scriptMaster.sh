#!/bin/bash
gcc BusquedaArbolHilos.c tiempo.c -pthread  -o  abHilos
for (( n=1000000; n<=10000000; n+=1000000 ))
do
    for x in $(cat tamProblema.txt); 
    do ./abHilos $n $x < numeros10M.txt >> salidasArbolHilos/salida$n.txt; 
    done
done


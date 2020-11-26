#!/bin/bash
gcc BusquedaLinealHilos.c tiempo.c -pthread  -o  linealHilos
for (( n=1000000; n<=10000000; n+=1000000 ))
do
    for x in $(cat tamProblema.txt); 
    do ./linealHilos $n $x < numeros10millones.txt >> salidasLinealHilos/salida$n.txt; 
    done
done


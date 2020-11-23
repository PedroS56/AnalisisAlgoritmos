#!/bin/bash
gcc BusquedaExponencialHilos.c tiempo.c -pthread  -o  expoHilos
for (( n=1000000; n<=10000000; n+=1000000 ))
do
    for x in $(cat tamProblema.txt); 
    do ./expoHilos $n $x < 10millones.txt >> salidasExponencialHilos/salida$n.txt; 
    done
done


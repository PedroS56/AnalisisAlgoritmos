#!/bin/bash
gcc BusquedaFibonacci.c tiempo.c -o fibonacci
for (( n=1000000; n<=10000000; n+=1000000 ))
do
    for x in $(cat tamProblema.txt); 
    do ./fibonacci $n $x < Ordenado10millones.txt >> salidasFibonacci/salida$n.txt; 
    done
done


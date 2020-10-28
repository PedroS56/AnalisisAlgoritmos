#!/bin/bash
gcc algo.c -o algo
./algo.out 100 < numeros10M.txt >> salida100.txt
./algo.out 1000 < numeros10M.txt >> salida1000.txt
./algo.out 5000 < numeros10M.txt >> salida5000.txt
./algo.out 10000 < numeros10M.txt >> salida10000.txt
./algo.out 50000 < numeros10M.txt >> salida50000.txt
./algo.out 100000 < numeros10M.txt >> salida100000.txt
./algo.out 400000 < numeros10M.txt >> salida400000.txt
./algo.out 600000 < numeros10M.txt >> salida600000.txt
./algo.out 800000 < numeros10M.txt >> salida800000.txt
./algo.out 1000000 < numeros10M.txt >> salida1000000.txt
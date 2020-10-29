#!/bin/bash
gcc Insercion.c timepo.c -o inser
./inser 100 < numeros10M.txt >> salida100.txt
./inser 500 < numeros10M.txt >> salida500.txt
./inser 800 < numeros10M.txt >> salida800.txt
./inser 1000 < numeros10M.txt >> salida1000.txt
./inser 2500 < numeros10M.txt >> salida2500.txt
./inser 5000 < numeros10M.txt >> salida5000.txt
./inser 7000 < numeros10M.txt >> salida7000.txt
./inser 10000 < numeros10M.txt >> salida10000.txt
./inser 20000 < numeros10M.txt >> salida20000.txt
./inser 40000 < numeros10M.txt >> salida40000.txt
./inser 50000 < numeros10M.txt >> salida50000.txt
./inser 70000 < numeros10M.txt >> salida70000.txt
./inser 100000 < numeros10M.txt >> salida100000.txt
./inser 200000 < numeros10M.txt >> salida200000.txt
./inser 400000 < numeros10M.txt >> salida400000.txt
./inser 500000 < numeros10M.txt >> salida500000.txt
./inser 600000 < numeros10M.txt >> salida600000.txt
./inser 650000 < numeros10M.txt >> salida650000.txt
./inser 800000 < numeros10M.txt >> salida800000.txt
./inser 1000000 < numeros10M.txt >> salida1000000.txt


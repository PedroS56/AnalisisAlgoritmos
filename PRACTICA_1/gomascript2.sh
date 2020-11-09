#!/bin/bash
gcc Seleccion.c timepo.c -o selec
./selec 100 < numeros10M.txt >> salida100.txt
./selec 500 < numeros10M.txt >> salida500.txt
./selec 800 < numeros10M.txt >> salida800.txt
./selec 1000 < numeros10M.txt >> salida1000.txt
./selec 2500 < numeros10M.txt >> salida2500.txt
./selec 5000 < numeros10M.txt >> salida5000.txt
./selec 7000 < numeros10M.txt >> salida7000.txt
./selec 10000 < numeros10M.txt >> salida10000.txt
./selec 20000 < numeros10M.txt >> salida20000.txt
./selec 40000 < numeros10M.txt >> salida40000.txt
./selec 50000 < numeros10M.txt >> salida50000.txt
./selec 70000 < numeros10M.txt >> salida70000.txt
./selec 100000 < numeros10M.txt >> salida100000.txt
./selec 200000 < numeros10M.txt >> salida200000.txt
./selec 400000 < numeros10M.txt >> salida400000.txt
./selec 500000 < numeros10M.txt >> salida500000.txt
./selec 600000 < numeros10M.txt >> salida600000.txt
./selec 650000 < numeros10M.txt >> salida650000.txt
./selec 800000 < numeros10M.txt >> salida800000.txt
./selec 1000000 < numeros10M.txt >> salida1000000.txt


/*
	BUSQUEDA LINEAL
	VERSION: 1.0
	AUTOR(ES):
		SÁNCHEZ CASTRO GAMALIEL
	FECHA: 09/11/2020

LIBRERIAS A UTILIZAR
*/
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

int main(int argc, char *argv[]){
	int n = 0, i = 0, *numeros, target=0;
	char encontrado='N';
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);
	target = atoi(argv[2]);
	//Se lee como argumento el tamaño del arreglo
	numeros = malloc(n*sizeof(int));
	printf("\n----------------------------------------------------------------------------\n");
    printf("n=%d\nx=%d\n",n,target);
	//Si no es posible reservar esa cantidad de memoria, salir del programa
	if(numeros==NULL)
		exit(1);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	//Marcamos el inicio de la medicion de tiempo
	uswtime(&utime0, &stime0, &wtime0);
	//Comienza el algoritmo
	for(i=0;i<n;i++){
		if(numeros[i]== target){
			encontrado = 'S';
			break;//Se ha encontrado, sal del for
		}
	}
	uswtime(&utime1, &stime1, &wtime1);
	if (encontrado=='S'){
		printf("Encontrado en:%d\n",i);
	}else{
		printf("No encontrado\n");
	}
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	// //Mostrar los tiempos en formato exponecial
	// printf("\n");
	// printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	// printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	// printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	// printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	// printf("\n");
	exit(0);
}
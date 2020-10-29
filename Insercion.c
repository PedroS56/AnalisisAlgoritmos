#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void Insercion(int *arreglo,int n){
	int i = 0, j = 0, temp = 0;
	for(i=0;i<n;i++){
		j=i;
		temp = arreglo[i];
		while((j>0)&&(temp<arreglo[j-1])){
			arreglo[j]=arreglo[j-1];
			j--;
		}
		arreglo[j] = temp;
	}
}

void main(int argc, char *argv[]){
	int n = 0, i = 0, *numeros;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);
	numeros = malloc(n*sizeof(int));
	if(numeros==NULL)
		exit(1);
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	uswtime(&utime0, &stime0, &wtime0);
	//Llamamos al algoritmo de nuestra preferencia
	Insercion(numeros,n);
	uswtime(&utime1, &stime1, &wtime1);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
}	


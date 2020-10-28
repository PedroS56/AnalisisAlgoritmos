#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Elem.h"
#include "DicBin.h"
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
	DicBin a = nuevoab();
	uswtime(&utime0, &stime0, &wtime0);
	for(i = 0; i < n; i++){
		a = InsOrdab(numeros[i], a);
	}
	ImpIn(a);
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
	
}
/*
void imprimir(int num[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%d,", num[i]);
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Arbin.h"
#include "tiempo.h"

struct argumentos{
	int *arreglo;
	int n;
	int target;
	char start;
};

void *BusquedaLineal(void *args){
	struct argumentos *argm = (struct argumentos*) args;
	int i = argm->start;
	while(i<(argm->n)){
		if((argm->arreglo[i])==(argm->target)){
			printf("Encontrado!\n");
		}
		i+=5;
	}
	int status = 0;
	pthread_exit((void*)&status);
}



void main(int argc, char *argv[]){
	int *numeros = NULL, i = 0, n = 0, target = 0; 
	int eid[5]; //STATUS DE LOS HILOS
	double utime0, stime0, wtime0,utime1, stime1, wtime1;

	//UNA ESTRUCTURA PARA TODOS LOS HILOS
	struct argumentos *args = NULL;
	pthread_t hilos[5];

	args = malloc(sizeof(struct argumentos));
	
	n = atoi(argv[1]);
	target = atoi(argv[2]);
	numeros = malloc(sizeof(int)*n);

	if(numeros==NULL)
		exit(2);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}

	args->arreglo = numeros;
	args->n = n;
	args->target = target;
	//COMENZAMOS A MEDIR EL TIEMPO
	uswtime(&utime0, &stime0, &wtime0);

	for(i=0;i<5;i++){
		args->start = i;
		pthread_create(&hilos[i],NULL,BusquedaLineal,(void*)args);
		pthread_join(hilos[i],(void*)&eid[i]);
	}

	for(i=0;i<5;i++){
		pthread_join(hilos[i],(void*)&eid[i]);
	}

	uswtime(&utime1, &stime1, &wtime1); 

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	return;
}

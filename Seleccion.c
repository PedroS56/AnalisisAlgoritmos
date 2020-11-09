/*
	FECHA: OCTUBRE 2020
	AUTOR(ES): 
		SANCHEZ CASTRO GAMALIEL
	VERSIÓN: 1.0
*/
//LIBRERIAS A UTILIZAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*
	FUNCION: Seleccion
	RECIBE: (int) Un apuntador a un arreglo de enteros, (int) el tamaño del arreglo.
	DESCRIPCION: Ordena un arreglo de enteros dado, utilizando el algoritmo 'Seleccion'.
	Realiza las modificaciones necesarias al arreglo y sale de la funcion.
	DEVUELVE: Implicitamente, el arreglo ordenado.
	OBSERVACIONES: Se debe crear previamente el arreglo.
*/
void Seleccion(int *arreglo,int n){
	int i = 0,j = 0,temp = 0,index = 0;
	for(i=0;i<(n-1);i++){
		index = i;
		for(j=(index+1);j<n;j++){
			if(arreglo[j]<arreglo[index])
				index=j;
		}
		temp = arreglo[index];
		arreglo[index] = arreglo[i];
		arreglo[i] = temp;
	}
}

void main(int argc, char *argv[]){
	int n = 0, i = 0, *numeros;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	n = atoi(argv[1]);
	//Se lee como argumento el tamaño del arreglo
	numeros = malloc(n*sizeof(int));
	//Si no es posible reservar esa cantidad de memoria, salir del programa
	if(numeros==NULL)
		exit(1);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	//Marcamos el inicio de la medicion de tiempo
	uswtime(&utime0, &stime0, &wtime0);
	//Llamamos al algoritmo 
	Seleccion(numeros,n);
	//Marcamos el final de la medicion de tiempo
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


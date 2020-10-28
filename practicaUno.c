#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void Burbuja(int *arreglo,int n){
	int aux=0,i=0,j=0;
    for(int i=0;i<(n-1);i++){
		for(int j=0;j<((n-1)-i);j++){
			if(arreglo[j]>arreglo[j+1]){
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;	
			}
		}
    }
}

void BurbujaOptimizada(int *arreglo, int n){
	int aux=0,i=0;
    char *cambios = "Si";
	while(i<(n-1)&&cambios!="No"){
		cambios = "No";
		for(int j=0;j<((n-1)-i);j++){
			if(A[j]<A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
				cambios = "Si";
			}
		}
		i++;
    }
}

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

void imprimeArreglo(int *arreglo, int tam){
	int i = 0;
	for(i=0;i<tam;i++)
		printf("%i,",arreglo[i]);
	printf("\n");
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
	Seleccion(numeros,n);
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


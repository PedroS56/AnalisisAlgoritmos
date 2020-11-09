#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#define LIMITE 50

int main(int argc, char *argv[]) {
    int *A,aux,n,i=0;
    char dato[LIMITE];
    char *cambios = "Si";
    double utime0, stime0, wtime0, utime1, stime1, wtime1;	
    
    if(argc != 2){
	printf("\nIndique el tamaño del algoritmo\n");
	exit(1);
    }
    else{
	n = atoi(argv[1]);
    }

    A=malloc(sizeof(int)*10000000);


    for(int k=0;k<n;k++){
	scanf("%d",&A[k]);
    }

    uswtime(&utime0, &stime0, &wtime0);
    
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

    //printf("\nFIN\n");

    //for(int l=0;l<n;l++){
  	printf("\nFIN\n");
    //}
   

    return 0;
}

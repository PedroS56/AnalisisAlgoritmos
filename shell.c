#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void Insercion(int *, int);


//***********************
//Metodo de ordenamiento shell
//***********************
int main (int argc, char* argv[])
{	
		
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos

	//**********************	
	//Algoritmo
	//**********************	
	FILE *Numeros;  
   Numeros = fopen("numeros10millones.txt", "r");
 
	int n,i;
	n=atoi(argv[1]);
	int *arr;
	//scanf("%d",&n);
	arr = (int *) malloc(sizeof(int)*n);
	
	for (i = 0; i < n; i++)
      fscanf(Numeros,"%d",&arr[i]);     
    fclose(Numeros);

	int k = n/2, b,temp,x;

	uswtime(&utime0, &stime0, &wtime0);
	
	for(int i = n/2;i>=1;i/=2){
		b=1;
		while(b != 0){
			b=0;
			for(int j = i; j<n; j++){
				if(arr[j-i]>arr[j]){
					temp=arr[j];
					arr[j]=arr[j-i];
					arr[j-i]=temp;
					b++;
				}
			}
		}
	}

	uswtime(&utime1, &stime1, &wtime1);
	
	for (i = 0; i < n; i++)
	{
		     printf("%d\n",arr[i]);  

	}

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
	//**********************

	//Terminar programa normalmente	
	exit (0);	
}
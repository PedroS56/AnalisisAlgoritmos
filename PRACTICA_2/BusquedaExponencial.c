// C program to implement iterative Binary Search 
#include <stdio.h> 
#include<stdlib.h>
#include "tiempo.h"

int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
   
        if (arr[m] == x) 
            return m; 
   
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 

    return -1; 
} 

int exponentialSearch(int arr[],int size,int key){
    if(size==0){
    	return -1;
    }

    int bound = 1;
    
    if(arr[0]==key){
        return 0;
    }

    int i=1;
    while(i < size && arr[i] <= key){
    	i=i*2;

    }
    
    int min;
    if(i<(size-1)){
        min=i;
    }
    else{
        min=(size-1);
    }

	return binarySearch(arr,i/2,min,key);

}
  
int main(int argc, char *argv[]){

if(argc!=3){
	printf("\nIntroduzca el elemento a buscar y el tamaño del espacio de busqueda\n");
	exit(1);
} 
double utime0, stime0, wtime0, utime1, stime1, wtime1;
int x = atoi(argv[1]);
int tam = atoi(argv[2]);
int *A;
A=malloc(sizeof(int)*10000000);


    for(int k=0;k<tam;k++){
	scanf("%d",&A[k]);
    }
	 
    int n = tam*4 / sizeof(A[0]); 
    uswtime(&utime0, &stime0, &wtime0); 
    int result = exponentialSearch(A, n , x); 
    uswtime(&utime1, &stime1, &wtime1);
    (result == -1) ? printf("\nEl elemento no esta presente en el arreglo\n") 
                   : printf("\nEl elemento se encuentra en el indice:%d\n", 
                            result); 
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	
    return 0; 
}

// C program to implement iterative Binary Search 
#include <stdio.h> 
#include<stdlib.h>
  
// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 
  
int main(int argc, char *argv[]){

if(argc!=3){
	printf("\nIntroduzca el elemento a buscar y el tamaño del espacio de busqueda\n");
	exit(1);
} 
double utime0, stime0, wtime0,utime1, stime1, wtime1;
int x = atoi(argv[1]);
int tam = atoi(argv[2]);
int *A;
 printf("\n----------------------------------------------------------------------------\n");
 printf("tam=%d\nx=%d\n",tam,x);
A=malloc(sizeof(int)*tam);


    for(int k=0;k<tam;k++){
	scanf("%d",&A[k]);
    }
	 
    int n = tam*4 / sizeof(A[0]);  
    uswtime(&utime0, &stime0, &wtime0);
    int result = binarySearch(A, 0, n - 1, x);
    uswtime(&utime1, &stime1, &wtime1); 
    (result == -1) ? printf("\nEl elemento no esta presente en el arreglo\n") 
                   : printf("\nEl elemento se encuentra en el indice:%d\n", 
                            result); 
    //Cálculo del tiempo de ejecución del programa
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
    return 0; 
}

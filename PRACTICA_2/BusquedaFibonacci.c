/*
	BUSQUEDA FIBONACCI
	VERSION: 1.0
	AUTOR(ES):
		SALVADOR BUCIO PEDRO ARMANDO
	FECHA: 10/11/2020

LIBRERIAS A UTILIZAR
*/
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) { return (x<=y)? x : y; }
int fibonacci(int arr[],int x, int n) 
    { 
        /* Inizializa numeros fibonacci  */
        int fibMMm2 = 0; // (m-2)'th Fibonacci No. 
        int fibMMm1 = 1; // (m-1)'th Fibonacci No. 
        int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
  
        /* fibM va a guardar el mas pequeño*/
        while (fibM < n) 
        { 
            fibMMm2 = fibMMm1; 
            fibMMm1 = fibM; 
            fibM = fibMMm2 + fibMMm1; 
        } 
  
        //Marca el rango eliminado desde el frente
        int offset = -1; 
  
    
        while (fibM > 1) 
        { 
            // Check if fibMm2 is a valid location 
            int i = min(offset+fibMMm2, n-1); 
  
            /* Si x es maqyor que el valor de index fibMn2, corta el subarray */
            if (arr[i] < x) 
            { 
                fibM = fibMMm1; 
                fibMMm1 = fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
                offset = i; 
            } 
  
            /* Si x es menor que el valor index fibMm2, corta el subarray despues de i+1 */
            else if (arr[i] > x) 
            { 
                fibM = fibMMm2; 
                fibMMm1 = fibMMm1 - fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
            } 
  
            /* Elemento encontrado retorna S*/
            else return i; 
        } 
  
        /* compara el ultimo elemento con x */
        if(fibMMm1 == 1 && arr[offset+1] == x) 
            return offset + 1; 
  
        /*Elemento no encontrado retorna N */
        return -1; 
    }
int main(int argc, char *argv[]){
    int n = 0, i = 0, *numeros, x=0;
    n = atoi(argv[1]);
	x = atoi(argv[2]);
    numeros = malloc(n*sizeof(int));
    printf("\n----------------------------------------------------------------------------\n");
    printf("n=%d\nx=%d\n",n,x);
    for(int i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
    double utime0, stime0, wtime0,utime1, stime1, wtime1;

    uswtime(&utime0, &stime0, &wtime0);
    int result = fibonacci(numeros,x,n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("\n");
    if (result != -1)
    {
       printf("x=%d encontrado en la posicion:%d\n",x,result); 
    }else
    {
        printf("x=%d NO encontrado\n",x);
    } 
    //Cálculo del tiempo de ejecución del programa
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
    
    exit (0);
}

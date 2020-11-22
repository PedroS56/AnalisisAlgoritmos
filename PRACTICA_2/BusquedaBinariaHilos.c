#include <stdio.h> 
#include<stdlib.h>
#include "tiempo.h"
int Hilos=2;
int Control=0;
int cont=0;
struct parametros{
	int *A;
	int key;
	int n;
	int resultado;
};
void *binarySearch(void *arg) 
{ 

    struct parametros *p1;
    p1=(struct parametros *)arg;
    
    int l=0,m=0;
    int *arr=malloc(sizeof(int)*10000000);
    int r=p1->n;
    int x=p1->key;
    arr = p1->A;
    int size=r/Hilos;
    int inicio=size*Control;
    r=size+size*Control;
    size=r-1;
    
	while (inicio <= size) { 
        int m = inicio + (size - inicio) / 2; 
  
        if (arr[m] == x){ 
	    printf("\nEl elemento se encuentra en el index:%i\n",m);
	    cont=1;
	}
  
        if (arr[m] < x){ 
            inicio = m + 1; 
	}
        else{
            size = m - 1;
	} 
    } 
    if(cont!=1&&Control==Hilos-1)
    printf("\nEl elemento no se encuentra en el arreglo\n");
    Control++; 
} 



int main(int argc, char *argv[]){

pthread_t *h;
h=malloc(sizeof(pthread_t)*Hilos);
struct parametros p;
if(argc!=3){
	printf("\nIntroduzca el elemento a buscar y el tamaño del espacio de busqueda\n");
	exit(1);
} 

p.key = atoi(argv[1]);
int tam = atoi(argv[2]);
double utime0, stime0, wtime0,utime1, stime1, wtime1;
p.A=malloc(sizeof(int)*10000000);


    for(int k=0;k<tam;k++){
	scanf("%d",&p.A[k]);
    }
	 
p.n = tam*4 / sizeof(p.A[0]);  
	
    uswtime(&utime0, &stime0, &wtime0);
    for(int l=0;l<Hilos;l++){
       if(pthread_create(&h[l], NULL, binarySearch, (void *)&p)!=0){
	 printf("\nError al crear el hilo\n");
	 exit(-1);
       }
    }

    for(int l=0;l<Hilos;l++){
        pthread_join(h[l],NULL);
    }
uswtime(&utime1, &stime1, &wtime1);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", Hilos,(utime1 - utime0)/Hilos);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	
	//Terminar programa normalmente	
	exit (0);
 
}

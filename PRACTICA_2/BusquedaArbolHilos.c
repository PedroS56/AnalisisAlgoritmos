#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Arbin.h"
#include "tiempo.h"

struct argumentos{
	Arbin a;
	int num;
};

void *buscaArbol(void *argm){
	struct argumentos *threadargs = (struct argumentos*) argm;
	int status = -1;
	int estaEn = BuscarElemento(threadargs->num, threadargs->a);
	if(estaEn==1)
		status = 0;
	pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){	
	int *numeros = NULL, i = 0, n = 0, target = 0, id1_stat = 0, id2_stat = 0;
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	struct argumentos *args = NULL;
	pthread_t id1,id2;
	args = malloc(sizeof(struct argumentos));
	Arbin a = Inicializar();
	n = atoi(argv[1]);
	target = atoi(argv[2]);
	numeros = malloc(sizeof(int)*n);

	args->num = target;

	if(numeros==NULL)
		exit(2);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	
	for(i = 0; i < n; i++){
		a = Insertar(numeros[i], a);
	}

	uswtime(&utime0, &stime0, &wtime0);

	if(ObtenerValor(a)>target)//Busqua por la izquierda
		a = HijoIzq(a);
	else //Busca por la derecha
		a = HijoDer(a);

	args->a = HijoIzq(a); //Creamos un hilo que recorra por la izquierda de mi sub arbol
	pthread_create(&id1,NULL,buscaArbol,(void*)args);
	args->a = HijoDer(a); //Creamos un hilo que recorra por la derecha de mi sub arbol
	pthread_create(&id2,NULL,buscaArbol,(void*)args);
	pthread_join(id1,(void*)&id1_stat);
	
	if(id1_stat==0)
		printf("Encontrado!\n");
	pthread_join(id2,(void*)&id2_stat);
	if(id2_stat==0)
		printf("Encontrado!\n");

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
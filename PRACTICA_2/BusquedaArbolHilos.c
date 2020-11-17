#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Arbin.h"
#include "tiempo.h"

struct argumentos{
	Arbin a;
	int num;
};

void *buscaDerecha(void *argm){
	struct argumentos *threadargs = (struct argumentos*) argm;
	int estaEn = BuscarElementoDerecha(threadargs->num, threadargs->a);
	if(estaEn==1)
		printf("D: Encontrado\n");
	int status = 0;
	pthread_exit((void*)&status);
}

void *buscaIzquierda(void *argm){
	struct argumentos *threadargs = (struct argumentos*) argm;
	int estaEn = BuscarElementoIzquierda(threadargs->num, threadargs->a);
	if(estaEn==1)
		printf("I: Encontrado\n");
	int status = 0;
	pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){	
	int *numeros = NULL, i = 0, n = 0, m = 0, id1_stat = 0;
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	struct argumentos *args = NULL;
	pthread_t id1;
	args = malloc(sizeof(struct argumentos));
	Arbin a = Inicializar();
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	numeros = malloc(sizeof(int)*n);

	if(numeros==NULL)
		exit(2);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	
	for(i = 0; i < n; i++){
		a = Insertar(numeros[i], a);
	}

	args -> a = a;
	args -> num = m;

	uswtime(&utime0, &stime0, &wtime0);

	pthread_create(&id1,NULL,buscaDerecha,(void*)args);
	pthread_join(id1,(void*)&id1_stat);

	pthread_create(&id1,NULL,buscaIzquierda,(void*)args);
	pthread_join(id1,(void*)&id1_stat);

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
/*
	FECHA: OCTUBRE 2020
	AUTOR(ES): 
		RODRIGUEZ MELGOZA IVETTE
		SALVADOR BUCIO PEDRO ARMANDO
		SANCHEZ CASTRO GAMALIEL
	VERSIÓN: 1.0
*/
//LIBRERIAS A UTILIZAR
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arbin.h"

/*
	FUNCION: main
	RECIBE: (int) numero de argumentos, (char *[]) argumentos
	DESCRIPCION: Recibe como argumento el tamaño del arreglo a ordenar
	DEVUELVE: El hijo derecho del nodo
*/
void main(int argc, char *argv[]){
	int n = 0, i = 0, *numeros;
	//Leemos como parametro
	n = atoi(argv[1]);
	numeros = malloc(n*sizeof(int));
	if(numeros==NULL)
		exit(1);
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	Arbin a = Inicializar();
	for(i = 0; i < n; i++){
		a = Insertar(numeros[i], a);
	}
	ImpIn(a);
}

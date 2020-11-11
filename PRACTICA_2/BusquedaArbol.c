/*
	BUSQUEDA ARBOL BINARIO
	VERSION: 1.0
	AUTOR(ES):
		SÁNCHEZ CASTRO GAMALIEL
	FECHA: 09/11/2020

LIBRERIAS A UTILIZAR
*/
#include <stdio.h>
#include <stdlib.h>
#include "Arbin.h"

void main(int argc, char *argv[]){
	int n=0, *numeros=NULL, i=0, num=0;
	boolean estaEn = FALSE;
	n = atoi(argv[1]);
	num = atoi(argv[2]);
	numeros=malloc(n*sizeof(int));
	if(numeros==NULL){
		printf("main.Imposible asignar memoria\n");
		exit(0);
	}
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}
	//Llenamos el arbol
	Arbin a = Inicializar();
	for(i = 0; i < n; i++){
		a = Insertar(numeros[i], a);
	}
	//Aqui comenzamos la busqueda
	estaEn = BuscarElemento(num,a);
	if(estaEn==TRUE){
		printf("El numero se encuentra en el arreglo\n");
		exit(0);
	}else{
		printf("El numero no se encuentra en el arreglo\n");
		exit(0);
	}
}
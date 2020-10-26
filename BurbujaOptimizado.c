#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 50

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int A[n],aux,i=0;
    char dato[LIMITE];
    char *cambios = "Si";
    FILE* fichero;
    fichero = fopen("numeros.txt","rt");
    for(int k=0;k<n;k++){
	fgets (dato, LIMITE, fichero);
	sscanf(dato,"%d",&A[k]);
    }
    fclose(fichero);

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
 
    for(int l=0;l<n;l++){
	printf("\n%i\n",A[l]);
    }
   

    return 0;
}

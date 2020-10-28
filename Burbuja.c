#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 50

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int A[n],aux;
    char dato[LIMITE];
    FILE* fichero;
    fichero = fopen("numeros.txt","rt");
    for(int k=0;k<n;k++){
	fgets (dato, LIMITE, fichero);
	sscanf(dato,"%d",&A[k]);
    }
    fclose(fichero);

    for(int i=0;i<(n-1);i++){
		for(int j=0;j<((n-1)-i);j++){
			if(A[j]>A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;	
			}
		}
    }

 
    for(int l=0;l<n;l++){
	printf("\n%i\n",A[l]);
    }
   

    return 0;
}

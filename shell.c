#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"


//***********************
//Metodo de ordenamiento shell
//***********************
int main (int argc, char* argv[])
{	
	if (argc != 2)
    exit(1);
		


	FILE *Numeros;  
   Numeros = fopen("numeros10millones.txt", "r");
   
 
	int n;
	n=atoi(argv[1]);
	int *arr;
	arr = (int *) malloc(sizeof(int)*n);
	
	for (int i = 0; i < n; i++)
      fscanf(Numeros,"%d",&arr[i]);     
    fclose(Numeros);

	int b,temp,x;

	
	for(int i = n/2;i>=1;i/=2){
		b=1;
		while(b != 0){
			b=0;
			for(int j = i; j<n; j++){
				if(arr[j-i]>arr[j]){
					temp=arr[j];
					arr[j]=arr[j-i];
					arr[j-i]=temp;
					b++;
				}
			}
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		     printf("%d\n",arr[i]);  

	}
	exit (0);	
}
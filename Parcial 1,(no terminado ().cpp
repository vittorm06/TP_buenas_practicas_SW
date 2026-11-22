#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

void mostrar(struct datos tanques[50],int referencia[2]);
//void agregartanque(struct datos *p)
struct datos{
	char nombretank[20];
	char sector[20];
	int nivel;
	
};
int main(int argc, char *argv[]) {
	
	int opcion,aux=1,check;
	int referencia[2]={200,200};
	int *aux;
	aux=&referencia;
	struct datos tanques[50];
	
	
	
	do{
	printf("Ingrese una opcion\n");
	printf(" 1-Agregar tanque.\n 2-Tanques Criticos\n 5-Salir\n");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		printf("tanque numero %d\n",aux);
		
		printf("Nombre del tanque:");
		scanf("%s",tanques[aux].nombretank);
		printf("%s",tanques[aux].nombretank);
		printf("\nSector del tanque:\n");
		scanf("%s",tanques[aux].sector);
		printf("%s",tanques[aux].sector);
		do{
		printf("Nivel de agua:\n");
		scanf("%d",&tanques[aux].nivel);
		if(tanques[aux].nivel>=0 && 100>=tanques[aux].nivel){
			check=1;
		}else{
			printf("porcentaje invalido, ingrese uno entre 0-100\n");
			check=0;
		}
		}while(check!=1);
		aux++;
		printf("%d\n",tanques[aux].nivel);
		break;
	case 2:
		mostrar(tanques,)
		break;
	case 5:
		printf("adios\n");
		break;
	default:
		printf("opcion invalida\n");
		break;
	}
}while(opcion!=5);
	return 0;
}

void mostrar(struct datos tanques[50],int referencia[2]){
	for(int i=1;i<51;i++){
		if(referencia[i]>tanques[i].nivel){
			referencia[i]=tanques[i].nivel
		}
		
	}
	//PROYECTRO ABANDONADO :( , pero perder una batalla no significa perder la guerra... MTFBWY
}

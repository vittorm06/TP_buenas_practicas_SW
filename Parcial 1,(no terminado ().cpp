#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


struct datos{
	char nombretank[20];
	char sector[20];
	int nivel;
};
struct datos *agregartanque(struct datos *tanques, int *cantidad);





int main(int argc, char *argv[]) {
	
	int opcion, cantidad=0;
	struct datos *tanques=NULL;
	
	
	
	do{
	printf("Ingrese una opcion\n");
	printf(" 1-Agregar tanque.\n 2-Tanques Criticos\n 9-Salir\n");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		tanques = agregartanque(tanques,&cantidad);
		break;
	case 2:
		
		break;
	case 9:
		printf("adios\n");
		break;
	default:
		printf("opcion invalida\n");
		break;
	}
}while(opcion!=9);
	free(tanques);
	return 0;
}
struct datos *agregartanque(struct datos *tanques, int *cantidad){
	int nuevos, i;
	printf("\n¿Cuantos tanques desea ingresar?: ");
	scanf("%d", &nuevos);
	
	if (nuevos <= 0) {
		printf("Cantidad invalida.\n");
		return tanques;
	}
	struct datos *temp = (struct datos*) realloc(tanques, (*cantidad + nuevos) * sizeof(struct datos));//agrega segun cuanto quiere el usuario
	if (temp == NULL) {
		printf("Error al asignar memoria.\n");
		return tanques;
	}
	tanques = temp;
	for (i = 0; i < nuevos; i++) {
		int indice = *cantidad + i;
		struct datos *p = &tanques[indice]; //puntero al actual
		
		printf("\nTanque #%d \n", indice + 1);
		printf("Nombre del tanque: ");
		scanf(" %29[^\n]", p->nombretank); //permite espacios y evita desbordamiento
		
		printf("Sector del tanque: ");
		scanf(" %29[^\n]", p->sector);
		do {
			printf("Nivel de agua (1 - 100%%): ");
			scanf("%d", &p->nivel);
			if (p->nivel < 1 || p->nivel > 100) {
				printf("Porcentaje invalido, ingrese un valor entre 1 y 100.\n");
			}
		} while (p->nivel < 1 || p->nivel > 100);
	}	
	*cantidad += nuevos; 
	return tanques;
}
	


//void mostrar(struct datos tanques[50],int referencia[2]){
//	for(int i=1;i<51;i++){
//		if(referencia[i]>tanques[i].nivel){
//			referencia[i]=tanques[i].nivel
//		}
//		
//	}
//
//}

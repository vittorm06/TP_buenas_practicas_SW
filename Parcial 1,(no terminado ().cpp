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
void mostrarCriticos(struct datos *tanques, int cantidad);
void buscarPorTexto(struct datos *tanques, int cantidad);

int main(int argc, char *argv[]) {
	
	int opcion, cantidad=0;
	struct datos *tanques=NULL;
	
	
	
	do{
	printf("Ingrese una opcion\n");
	printf(" 1-Agregar tanque.\n 2-Tanques Criticos\n3-Buscar tanques por texto \n9-Salir\n");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		tanques = agregartanque(tanques,&cantidad);
		break;
	case 2:
		mostrarCriticos(tanques, cantidad);
		break;
	case 3:
		buscarPorTexto(tanques, cantidad);
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
	void mostrarCriticos(struct datos *tanques, int cantidad) {
		if (cantidad == 0) {
			printf("No hay tanques cargados.\n");
			return;
		}
		
		if (cantidad == 1) {
			printf("\nSolo hay 1 tanque cargado:\n");
			printf("1) Nombre: %s | Sector: %s | Nivel: %d%%\n",
				   tanques[0].nombretank, tanques[0].sector, tanques[0].nivel);
			return;
		}
		int idxMin1 = -1, idxMin2 = -1;
		
		for (int i = 0; i < cantidad; i++) {
			if (idxMin1 == -1 || tanques[i].nivel < tanques[idxMin1].nivel) {
				idxMin2 = idxMin1;
				idxMin1 = i;      
			} else if (idxMin2 == -1 || tanques[i].nivel < tanques[idxMin2].nivel) {
				idxMin2 = i;
			}
		}
		
		printf("\nLOS 2 TANQUES CRITICOS SON\n");
		printf("1er Minimo -> Nombre: %s | Sector: %s | Nivel: %d%%\n",
			   tanques[idxMin1].nombretank, tanques[idxMin1].sector, tanques[idxMin1].nivel);
		printf("2do Minimo -> Nombre: %s | Sector: %s | Nivel: %d%%\n",
			   tanques[idxMin2].nombretank, tanques[idxMin2].sector, tanques[idxMin2].nivel);
	}
	void buscarPorTexto(struct datos *tanques, int cantidad) {
		if (cantidad == 0) {
			printf("\nNo hay tanques cargados.\n");
			return;
		}
		
		char busqueda[30];
		char etiqueta[70];
		int encontrados = 0;
		
		printf("\nIngrese silaba o texto a buscar en Nombre o Sector: ");
		scanf(" %29[^\n]", busqueda);
		
		printf("\nResultados que contienen \"%s\":\n", busqueda);
		for (int i = 0; i < cantidad; i++) {
			
			strcpy(etiqueta, tanques[i].sector);
			strcat(etiqueta, " - ");
			strcat(etiqueta, tanques[i].nombretank);

			if (strstr(tanques[i].nombretank, busqueda) != NULL ||
				strstr(tanques[i].sector, busqueda) != NULL) {
				printf("- [%s] -> Nivel: %d%%\n", etiqueta, tanques[i].nivel);
				encontrados++;
			}
		}
		
		if (encontrados == 0) {
			printf("No se encontraron coincidencias.\n");
		}
	}

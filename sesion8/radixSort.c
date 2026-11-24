/*
 * radixSort.h 
 *
 *  Created on: 03/11/2014
 *      Author: M.J. Polo
 */
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "radixSort.h"


void radixSort(nodo **lista,int numGrupos,int numCifras){

//nodo *grupos[10], gruposFin[10];
int cifra, k;
nodo **grupos, **gruposFin;
	grupos = (nodo **) calloc(numGrupos, sizeof (nodo*));
	gruposFin = (nodo **) malloc(numGrupos*sizeof(nodo*));
	
	for (cifra=numCifras; cifra>=1; cifra --){ //depende de como extraiga las cifras
		//Iniciar grupos
		for (k=0; k<numGrupos; k++){
			grupos[k]=NULL;
			gruposFin[k]=NULL;
		}
		//Distribuir
		distribuir(cifra, lista, grupos, gruposFin);
		
		//Concatenar
		concatenar(lista, grupos, gruposFin, numGrupos);
		contadorExterno++;
	}
}

void distribuir(int numCifra, nodo **lista, nodo** grupos,nodo **gruposFin){
	char cadena[20];
	nodo *aux;
	aux = *lista;
	int i;
	
	while(aux!=NULL){
		contadorInterno++;
		//Proceso
		sprintf(cadena, "%05d", aux->info);
		i = cadena[numCifra-1] - 48;
		
		if (grupos[i]==NULL){
			grupos[i]= aux;
			gruposFin[i]=aux;
		}else{
			gruposFin[i]->sig=aux;
			gruposFin[i]=aux;
		}
		aux = aux->sig;
	}
	*lista = NULL;
}

void concatenar(nodo **lista, nodo** grupos,nodo **gruposFin,int numGrupos){
	*lista = NULL;
	int k, anterior=0;
	for (k=0; k<numGrupos; k++){
		if (grupos[k]!=NULL){
			if (*lista == NULL){
				*lista=grupos[k];
			}else{
				gruposFin[anterior]->sig = grupos[k];
			}
			anterior = k;
		}
	}
	gruposFin[anterior]->sig = NULL;
}
 




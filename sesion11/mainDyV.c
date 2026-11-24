/*
 * mainDyV.c		
 *
 *  Created on: 01/12/2014
 *      Author: M José Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"
#include "esquemas.h"
long int contadorInterno, contadorExterno, contadorMedio;

int main(int argc, char *argv[])
{ int *vector, *vectorOrdenado,rango=10000,pos,valorBuscar,i;
  int numElementos;


	// Enunciado 1. Torres de Hanoi
	
	Hanoi(3,1,3,2);
	printf("\nEliminando recursividad de cola...\n");
   	HanoiERC(3,1,3,2);

	// Enunciado 2. Búsqueda ternaria

	numElementos = 1000;
	vector = crearVector(numElementos,rango);
	vectorOrdenado=ordenarBurbuja(vector,numElementos);
   	valorBuscar = vectorOrdenado[756];

	pos = bTernaria(vectorOrdenado,0,numElementos-1,valorBuscar);

   	if (pos==-1) printf("\nNo existe valor %d\n", valorBuscar);
	else printf("\nEl valor %d esta en posicion %d ( %d )\n",valorBuscar, pos, vectorOrdenado[pos]);

	// Enunciado 3. Exponenciación divide y vencerás
	   
	printf( "\npotencia %d elevado a %d es %ld\n", 2,10, potDyV(2,10));

}


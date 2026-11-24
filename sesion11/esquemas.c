/*
 * esquemas.c		Ejercicios sobre esquemas algoritmicos
 *
 *  Created on: 01/12/2014
 *      Author: M José Polo
 */
#include "esquemas.h"
#include <stdio.h>
// Enunciado 1 Torres de Hanoi
void Hanoi(int n,int origen, int destino, int aux)
{ if (n>0)
     {	  Hanoi(n-1,origen, aux, destino);
          printf(" Mueve disco n %d desde %d a %d \n",n, origen, destino);
          Hanoi(n-1, aux,destino, origen);
     }
}
void HanoiERC(int n,int origen, int destino, int aux)
{
	while (n > 0) {
		HanoiERC(n - 1, origen, aux, destino);
		printf("Mueve disco n %d desde %d a %d \n", n, origen, destino);
		
		int temp = origen;
		origen = aux;
		aux = temp;
		n--;
	}
}
// Enunciado 2: búsqueda ternaria (recuperamos funciones de otras sesiones...crearVector, ordenar....)
// Es mejor que la búsqueda binaria??? análisis y comparativa!!!
int bTernaria(int *vector, int base, int tope,int x)
{ 
	if (base > tope) return -1;
	else{
		int tercio = ((tope-base)+1)/3;
		int k = base + tercio;
		int k2 = base + 2*tercio;
		if (x==vector[k]){
			return k;
		} else if (x < vector[k]) {
			tope = k-1;
		} else if (x==vector[k2]) {
			return k2;
		} else if (x < vector[k2]){
			tope = k+1;
			tope = k2-1;
		} else if (x > vector[k2]){
			base=k2+1;
		}
		return bTernaria(vector, base, tope, x);
	}
}



// Enunciado 3: Versiones iterativa y Divide y Vencerás. Cúal es mejor??? análisis y comparativa!!!
long int potDyV(long int a, int n)
{
	if (n == 0){
		return 1;
	} else if (n == 1){
		return a;
	} else if (n%2==0){
		return potDyV(a, n/2) * potDyV(a, n/2);
	} else if (n%2==1){
		return a * potDyV(a, n-1);
	}
}



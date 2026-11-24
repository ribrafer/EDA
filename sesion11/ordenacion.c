/*
 * auxiliares.c
 *
 *  Created on: 20/09/2013
 *      Author: M José Polo 
 */
#include <stdlib.h>
#include "ordenacion.h"

/*
/* Crea y devuelve un vector de numElementos asignando a cada elemento del vector un numero 
/* aleatorio entre 0 y rango-1
*/

int *crearVector (int numElementos , int rango )
{ int *vector , i;

  vector = malloc ( numElementos * sizeof ( int));
  for (i = 0; i < numElementos ; i++)   vector[i] = rand () % rango ;

 return vector ;
}


//Crea un vector ordenado creciente
int *crearVectorCreciente (int numElementos)
{ int *vector , i;

  vector = malloc ( numElementos * sizeof ( int));
  for (i = 0; i < numElementos ; i++)   vector[i] = i+45 ;

 return vector ;
}


//Crea un vector ordenado decreciente
int *crearVectorDecreciente (int numElementos)
{ int *vector , i;

  vector = malloc ( numElementos * sizeof ( int));
  for (i = 0; i < numElementos ; i++)   vector[i] = numElementos-i ;

 return vector ;
}


/*
 * Crea y devuelve un vector de numElementos donde ordenada los elementos del vector desordenado que se
 * le pasa en el primer argumento
 * OJO:  se reserva memoria de forma dinámica !!!hay que liberarla después de su uso!!!!
 */

int *ordenarBurbuja (int *vector , int numElementos )
{ int *nuevo , i, j;

  nuevo = ( int *) malloc ( numElementos * sizeof (int));

  for (i = 0; i < numElementos ; i++)
  nuevo [i] = vector [i];

    for (i = 0; i < numElementos ; i++) {
	contadorExterno++;
      for (j = 0; j < numElementos -1-i; j++){
	contadorInterno++;
        if ( nuevo [j] > nuevo [j +1]) {
          intercambiar (&( nuevo [j]) ,&( nuevo [j +1]) );
        }
      }
     }
 return nuevo ;
}

void Burbuja (int *vector , int numElementos )
{
  int i, j, flag;

    for (i = 0; i < numElementos ; i++) {
	contadorExterno++;
	
      for (j = 0; j < numElementos -1-i; j++){
      	flag=0;
	contadorInterno++;
        if ( vector [j] > vector [j +1]) {
          intercambiar (&( vector [j]) ,&( vector [j +1]) );
          flag=1;
        }
      }
      if (flag==0){
      	break;
      }
     }
}

int * ordenarInsercion(int *vector , int numElementos ){
  int *nuevo , i, j, x;

  nuevo = ( int *) malloc ( numElementos * sizeof (int));

  for (i = 0; i < numElementos ; i++)
  nuevo [i] = vector [i];
  
  for (i = 1; i < numElementos; i++){
  	contadorExterno++;
  	x = nuevo[i];
  	j=i-1;
  	while(j>0 && nuevo[j]>x){
  		contadorInterno++;
  		nuevo[j+1]=nuevo[j];
  		j=j-1;
  	}
  	nuevo[j+1]=x;
  }
  return nuevo;
}


int * ordenarInsercionBinaria(int *vector , int numElementos ){
  int *nuevo , i, j, x, izq, der, medio;

  nuevo = ( int *) malloc ( numElementos * sizeof (int));

  for (i = 0; i < numElementos ; i++)
  nuevo [i] = vector [i];
  
  for (i = 0; i < numElementos; i++){
  	contadorExterno++;
  	x=nuevo[i];
  	izq=0;
  	der=i-1;
  	
  	while (izq <= der) {
            contadorMedio++;
            medio = izq + (der - izq) / 2;
            if (x < nuevo[medio]) {
                der = medio - 1;
            } 
            //Caso en que sea igual (añadir)
            else {
                izq = medio + 1;
            }
        }
        
        for (j = i - 1; j >= izq; j--) {
            contadorInterno++;
            nuevo[j + 1] = nuevo[j];
        }
        
        nuevo[izq] = x;
  	
  }
  return nuevo;
}


int * ordenarSeleccion(int *vector , int numElementos ){
  int *nuevo , i, j, posicion, valor;

  nuevo = ( int *) malloc ( numElementos * sizeof (int));

  for (i = 0; i < numElementos ; i++)
  nuevo [i] = vector [i];
  
  for (i = 1; i < (numElementos-1); i++){
  	contadorExterno++;
  	posicion = i;
  	valor = nuevo[i];
  	for (j = (i+1); j < numElementos; j++){
  		contadorInterno++;
  		posicion = j;
  		valor = nuevo[j];
  	}
  }
  nuevo[posicion]=nuevo[i];
  nuevo[i]=valor;
  return nuevo;
}

void  QuickSort(int *vector,int base,int tope){
	int ip;
	if (base < tope){
		contadorExterno++;
		ip = colocar(vector, base, tope);
		QuickSort(vector, base, ip-1);
		QuickSort(vector, ip+1, tope);
	}
}

int colocar(int *vector,int base, int tope){
	int i, ip, pivote;
	ip = base;
	pivote = vector[base];
	for (i = base+1; i <= tope; i++){
		contadorInterno++;
		if (vector[i] < pivote){
			ip++;
			intercambiar(vector[i], vector[ip]);
		}
	}
	intercambiar(vector[base], vector[ip]);
	return ip;
}

void  QuickSortMejora(int *vector,int base,int tope){
	int i, j, indiceP, x;
	i = base;
	j = tope;
	indiceP = (base+tope)/2;
	x = vector[indiceP];
	contadorExterno++;
	do{
		while (vector[i] < x){
			contadorInterno++;
			i++;
		}
		while (vector[j] > x){
			contadorInterno++;
			j--;
		}
		if (i <= j){
			intercambiar(vector[i], vector[j]);
			i++;
			j--;
		}
	}while (i <= j);
	if (base < j){
		QuickSortMejora(vector, base, j);
	}
	if (base > i){
		QuickSortMejora(vector, i, tope);
	}
}

/*
 * Intercambia los valores de sus dos argumentos
 */

void intercambiar (int *x, int *y)
{ int temp ;

  temp = *x;
  *x = *y;
  *y = temp;

}


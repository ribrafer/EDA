/*
 * lista.h	Representación memoria contigua
 *
 *  Created on: 15/12/2014
 *      Author: M J Polo
 */
#include <stdio.h>
#ifndef LISTAS_ARRAYS_H_INCLUDED
#define LISTAS_ARRAYS_H_INCLUDED
#define MAX 100

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

typedef struct 
{ tipoElemento elementos[MAX];
  int ultimo;
  } Lista;
typedef int tipoPosicion;

int anula(Lista *l);
int vacia(Lista *l);

int inserta(tipoElemento x, tipoPosicion p, Lista *l);
int suprime (tipoPosicion p, Lista *l);
tipoPosicion localiza (tipoElemento x, Lista *l);
tipoElemento recupera(tipoPosicion p, Lista *l);

void imprime(Lista *l);



tipoPosicion primero(Lista *l);
tipoPosicion siguiente(tipoPosicion p, Lista *l);
tipoPosicion anterior(tipoPosicion p, Lista *l);
tipoPosicion fin(Lista *l);


#endif // LISTAS_ARRAYS_H_INCLUDED

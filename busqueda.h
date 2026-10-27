/*
 * busqueda.h 
 *
 *  Created on: 03/11/2014
 *      Author: M.J. Polo
 */

#ifndef __BUSQUEDA_H
#define __BUSQUEDA_H

extern long int contadorExterno,contadorInterno;

int bSecuencial(int * vector,int numElementos, int valor);
int bBinariaI(int * vector,int numElemtos, int valor);
int bBinariaR(int * vector,int inicio,int fin, int valor);
#endif // BUSQUEDA_H

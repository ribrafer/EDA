#include "busqueda.h"

int bSecuencial(int * vector,int numElementos, int valor){
   int i; 
   for (i=0; i < numElementos; i++){
    contadorExterno++;
    if (vector [i] == valor){
    contadorInterno++; 
    return 1;}
    }
    return -1; 
  }  
int bBinariaI(int * vector,int numElemtos, int valor){
   int i = 1; 
   int j = numElemtos;
   do {
   	int k = (i+j)/2;
   	if ( valor < vector [k]){
   		j = k-1;
   	} else if (valor > vector [k]){
   		i = k+1;
   	} else (valor == vector [k]); {
   		i=k;
   		j=k;
   	}
   } while (i<j);
   
   if (valor == vector [i]) {
   	return 1; 
   } else {
   	return 0; 
   }
}

int bBinariaR(int *vector,int inicio,int fin,int valor){
int k; 
if (inicio > fin){
return 0; 
} else {
k = (inicio+fin)/2;
if (valor < vector [k]){
fin=k-1; 
}else if (valor > vector [k]){
inicio=k+1;
} else (valor == vector [k]);{
return k; 
}
//return bBinariaR();
}
}

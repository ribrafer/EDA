/*
 * algoritmos.c
 *
 *  Created on: 07/10/2013
 *      Author: MJ Polo
 */
#include <math.h>
#include "algoritmos.h"
// Orden cuadrático
void algA(int n)
{ int i,j,c;

	c = 1;
	for (i=1;i<=n;i++){
		contadorExterno++;
		for (j=1;j<=n;j++) {
			contadorInterno++;
			c = c + 1;
		}
  	}
}

void algB(int n)
{ int i, j, k, c;
	
	c=1;
	for(i=1;i<=n;i++){
		contadorExterno++;
		for(j=1;j<=n;j++){
			contadorMedio++;
			for(k=1;k<=2;k++){
				contadorInterno++;
				c=c+1;
			}
		}
	}

}

void algC(int n)
{	int i, j, k, c;
	int a = n*n;
	int b = n*n*n;
	
	c=1;
	for(i=1;i<=n;i++){
		contadorExterno++;
		for(j=1;j<=a;j++){
			contadorMedio++;
			for(k=1;k<=b;k++){
				contadorInterno++;
				c=c+1;
			}
		}
	}

}

void algD(int n)
{ int i, j, c;
	
	c=1;
	for(i=1;i<=n;i++){
		contadorExterno++;
		for(j=1;j<=i;j++){
			contadorInterno++;
		
			c=c+1;
		
		}
	}
}

void algE(int n)
{ int i, j, k, c;
	
	c=1;
	for(i=1;i<=n;i++){
		contadorExterno++;
		for(j=1;j<=n;j++){
			contadorMedio++;
			for(k=1;k<=j;k++){
				contadorInterno++;
				c=c+1;
			}
		}
	}
}

void algF(int n)
{ int i, j, k, c;
	
	c=1;
	for(i=1;i<=n;i++){
		contadorExterno++;
		for(j=1;j<=i;j++){
			contadorMedio++;
			for(k=1;k<=j;k++){
				contadorInterno++;
				c=c+1;
			}
		}
	}
}

void algG(int n)
{ int j, x;
	
	x=0;
	j=n;
	
	while(j>=1){
		contadorInterno++;
		x=x+1;
		j=j/2;
	}
}

void algH(int n)
{ int j, x;
	
	x=0;
	j=n;
	
	while(j>=1){
		contadorInterno++;
		x=x+1;
		j=j/3;
	}
}

void algI(int n)
{ int i, j, x;
	
	x=0;
	i=1;
	
	do{
		contadorExterno++;
		j=1;
		while(j<=i){
			contadorInterno++;
			x=x+1;
			j=j*2;
		}
		i=i+1;
	}while(n>=i);
}

void algJ(int n)
{ int i, j, x;
	
	x=0;
	i=1;
	
	do{
		contadorExterno++;
		j=1;
		while(j<=i){
			contadorInterno++;
			x=x+1;
			j=j+2;
		}
		i=i+1;
	}while(n>=i);
}


int algK(int n)
{ int i, j, x;
	
	x=0;
	i=1;
	
	while(i<n){
		contadorExterno++;
		for(j=1;j<=i;j++){
			contadorInterno++;
			x=x+1;
		}
		i=i*10;
	}
	return x;
}

double factorialI(int n){
	int i;
	double resultado;
	for (i=2; i<=n; i++){
		contadorInterno++;
		resultado = resultado*i;
	}
	return resultado;
}

double factorialR(int n){
	if (n<=0){
		return 1;
	}
	else{
		contadorInterno++;
		return (n*factorialR(n-1));
	}
}

int fibonacciR(int n){
	if (n<=0){
		return 0;
	}
	else if (n==1){
		return 1;
	}
	else{
		contadorInterno++;
		return (fibonacciR(n-1)+fibonacciR(n-2));
	}
}

int fibonacciI(int n){
	int a=0, b=1, c, i;
	
	for (i=2; i<=n; i++){
		contadorInterno++;
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

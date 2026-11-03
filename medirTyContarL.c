/*
 * medirTyContarL.c
 *
 *  Adaptado a listas enlazadas.
 *  Autor original: M.J. Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"
#include <time.h>

long int contadorInterno, contadorExterno, contadorMedio;

int main(int argc, char *argv[])
{ 
	double tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC ;
	double tiempo;

	// Declaración adaptada a listas enlazadas
	Lista lista, listaOrdenada; 
	int rango=100000, n=10000,i,repeticiones=0;
        
 	FILE *f;  
 	
	if (argc != 2) {
            printf("\n Uso: ./medirTyContarL <nombre fichero resultados>\n\n");
            return -1;
        }

        f = fopen(argv[1], "w+");
        fprintf(f,"n;tiempoMedio;Externo;Interno\n");


        for (n=5000;n<=50000;n=5000+n) {
            repeticiones=contadorInterno=contadorExterno=0;
            
		// Inicialización de lista
		lista = crearLista(n,rango);

     		tiempoInicial = tiempoFinal= (double)clock();
		{ 	
            // Algoritmo de ordenación adaptado a firmas de listas
            listaOrdenada = ordenarInsercionBinariaLista(lista,n);
	        
            // Liberación de memoria iterativa de la lista (sustituye a free)
            liberarLista(listaOrdenada);
			repeticiones++;
	     		tiempoFinal = (double) clock();
		}

     		tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
		printf("\n %d \t %e \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones);
		fprintf(f,"\n %d \t %e \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones);

      // Liberación de memoria de la lista original
      liberarLista(lista);
      }
fclose(f);

return 0;
}
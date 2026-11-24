# Sesión 8 - RadixSort: Ejemplo de Algoritmo de Ordenación por Distribución. Análisis

	# Prueba RadixSort
pruebaRadix: pruebaRadix.c lista.o radixSort.o
	gcc -g pruebaRadix.c lista.o radixSort.o -o pruebaRadix -lm

	# Analisis RadixSort
sesion8: medirTyContarL.c lista.o radixSort.o
	gcc -g medirTyContarL.c lista.o radixSort.o -o sesion8

radixSort.o: radixSort.c radixSort.h
	gcc -c -g radixSort.c

lista.o: lista.c lista.h
	gcc -c -g lista.c

# Varios
clean:
	rm *.o


# Proyecto para ejercicios T5.Esquemas Algoritmicos

# Sesión 9. Esquema Divide y Vencerás

mainDyV: mainDyV.c esquemas.o ordenacion.o
	gcc -g mainDyV.c esquemas.o ordenacion.o -o mainDyV

esquemas.o: esquemas.c esquemas.h
	gcc -g -c esquemas.c

ordenacion.o: ordenacion.c ordenacion.h
	gcc -c -g ordenacion.c

limpiar:
	rm *.o


//TO-DO
/*
 * Se leen desde un fichero de texto (ENT.TXT) una secuencia de valores indeterminada de números enteros,
 * como máximo 20. Escribir un programa que grabe en otro fichero de texto (SAL.TXT)
 * solo aquellos valores que han sido leídos y que sea múltiplos de 5.
 * El fichero de texto ENT.TXT debe ser creado previamente con block de notas.
 * El fichero de texto SAL.TXT si existe previamente se perderá.
 */
#include <stdio.h>

//prototipos
void leer   (FILE *pf1, int v[], int *longitud);
void grabar (int v[], int longitud,FILE *pf2);

int main(){
        FILE *pf1;
        FILE *pf2;
        int v[20];
        int *logitud;

        leer(*pf1,v,*longitud){
              *pf1 = fopen("ENT.TXT","r");
              fscanf("")

        }
}

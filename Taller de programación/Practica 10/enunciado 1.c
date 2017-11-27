/*
 * Se leen desde un fichero de texto (ENT.TXT) una secuencia de valores indeterminada de nímeros enteros,
 * como máximo 20. Escribir un programa que grabe en otro fichero de texto (SAL.TXT)
 * solo aquellos valores que han sido leídos y que sea múltiplos de 5.
 * El fichero de texto ENT.TXT debe ser creado previamente con block de notas.
 * El fichero de texto SAL.TXT si existe previamente se perderá.
 */
#include <stdio.h>

//prototipos
void leer(FILE *pf1, int v[], int *longitud);
void grabar(int v[], int longitud,FILE *pf2);

int main(){
        FILE *pf1;
        FILE *pf2;

        int v[20];
        int longitud;

        leer(pf1,v,&longitud);
        grabar(v,longitud,pf2);

        return 0;
}

void leer(FILE *pf1, int v[], int *longitud){

        pf1 = fopen("ENT.TXT","r"); //Abrimos pf1 en modo lectura
        int i=0,valor; //definimos dos variables
        while(((fscanf(pf1,"%d",&v[i]))!=EOF)&&(i<20)) //ejecutar el siguiente bloque hasta EOF o i<20
                i++;
        *longitud=i;
        fclose(pf1); //Cerramos fichero
}

void grabar(int v[], int longitud,FILE *pf2){
        int i;
        pf2 = fopen("SAL.TXT","w"); //Abrimos pf2 en modo escritura
        for(i=0; i<longitud; i++) { //hasta que i<longitud del array imprimir numeros en pf2
                if((v[i]%5)==0) //Si el valor es multiplo de 5 ejecutar lo siguientefprintf(pf2,"%d\n",v[i]);
                        fprintf(pf2,"%d\n",v[i]);
        }
        fclose(pf2);//Cerramos pf2
}

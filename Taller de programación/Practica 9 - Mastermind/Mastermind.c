/*
 * MASTERMIND EN C
 * Creado por: Óscar, @0smak
 * STATUS: EN CONSTRUCCIÓN
 */

#include <stdio.h>
#include <stdlib.h> //libreria para rand()
#include <time.h> //libreria para time()

#define N 5 //Numero de posiciones que hay que adivinar

//prototipos de funciones que se van a usar.
int ValidarCombinacion();
int CrearPistas();
int GenerarNumero(int v[], int i);

int main(){
        printf("\n\t\t========================\n\t\t\tMASTERMIND\n\t\t========================");
        printf("\n\n\tInstrucciones:\n");
        printf("\n\t  Se generará un codigo de 5 cifras el cual tendras que adivinar\n\t  Tendrás 10 oportunidades\n\t  * = Numero acertado, posicion incorrecta\n\t  + = numero y posicion correcta\n");

        int v[N], c[N]; //v = vector del codigo secreto, c = combinacion que introduce el usuario, N nº de cifras
        int intentos = 10; //Intentos para adivinar la combinacion
        int i; //variable de iteraccion

        GenerarNumero(v,i);


        return 0;
}

int GenerarNumero(int v[], int i){
        srand(time(NULL));
        int num,j=0, repetido = 0;
        for(i=0; i<5; i++) {
                repetido =0;
                num = rand()%9+1;
                for(j=0; j<i; j++) {
                        if(num==v[j]) {
                                repetido = 1;
                                i--;
                                j--;
                        }
                }
                if(!repetido) {
                        v[i]=num;
                }
        }

        printf("\nDEBUG: ");
        for(i=0; i<N; i++) {
                printf("%d",v[i]);
        }
        printf("\n");
}

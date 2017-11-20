/*
 * MASTERMIND EN C
 * Creado por: Óscar, @0smak
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
        int num,t=0, j=0, encontrado = 0, igual = 1;
        for(i=0; i<N; i++) {
                num=rand()%9+1;
                printf("\nNumero inicial generado: (%d)\n",num);
                do{ //mientras sea el numero = a valor de array seguir bucle
                        printf("==================> %d\n",t);
                        for(j=0;j<t;j++){ //Mientras exista un numero en el array ejecutar eso
                                printf("Vector[%d]: numero en array %d = generado %d?\n",j,v[j],num);
                                if(v[j]==num) { //si encontramos un numero coincidente, encontrado = 1
                                        encontrado = 1;
                                        printf("\n\n\n========== ENCONTRADO (%d) ======= \n\n\n",t);

                                }
                        }
                        if(encontrado==1) { //si encontrado = 1, generar otro numero aleatorio
                                num=rand()%9+1;
                        }else{
                                v[i] = num;
                                igual=0;
                                printf("\nnumero final:v[%d] = [%d]\n",i,v[i]);
                                t++;
                        }
                }while(igual==1);
                encontrado=0;
        }
        igual = 1;
        printf("\n");
        for(i=0; i<N; i++) {
                printf("%d - ",v[i]);
        }
        printf("\n");
}


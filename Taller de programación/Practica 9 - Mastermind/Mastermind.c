/*
 * MASTERMIND EN C
 * Creado por: Óscar, @0smak
 * STATUS: Terminado
 * TO-DO: Depurar programa para malgastar menos recursos y hacer más entendible el codigo
 */
#include <stdio.h>
#include <stdlib.h> //libreria para rand()
#include <time.h> //libreria para time()

#define N 5 //Numero de posiciones que hay que adivinar

//prototipos de funciones que se van a usar.
int ValidarCombinacion(int c[], int v[], int i, int intentos);
int IntroducirCombinacion(int c[], int i, int v[], int intentos);
int GenerarNumero(int v[], int i);

int main(){
        printf("\n\t\t========================\n\t\t\tMASTERMIND\n\t\t========================");
        printf("\n\n\tInstrucciones:\n");
        printf("\n\t  Se generará un codigo de 5 cifras el cual tendras que adivinar\n\t  El codigo no tiene ninguna cifra repetida\n\t  Tendrás 10 oportunidades\n\n\t  Pistas que se daran:\n\t  * = Numero acertado, posicion incorrecta\n\t  + = numero y posicion correcta\n");

        int v[N], c[N]; //v = vector del codigo secreto, c = combinacion que introduce el usuario, N nº de cifras
        int intentos = 10; //Intentos para adivinar la combinacion
        int i; //variable de iteraccion
        int opc; //numero entero que devuelve x opcion al introducir combinacion si es la primera vez o la n vez por fallo

        GenerarNumero(v,i);
        IntroducirCombinacion(c,i,v,intentos);

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
}

int IntroducirCombinacion(int c[], int i, int v[], int intentos){
        printf("\n\n\t========> Intentos restantes: %d <========", intentos);
        int comb,vCorrecto;
        printf("\n\nIntroduzca una combinacion de 5 numeros: ");
        do {
                scanf("%d",&comb );
                if((comb<0)||(comb>99999)) {
                        printf("\n\t*****Valor ilegal, Debe ser entre 0 y 99999.*****\n");
                        vCorrecto=0;
                        printf("\nIntroduzca una combinacion de 5 numeros: ");
                }else{
                        vCorrecto=1;
                }
        } while(vCorrecto==0);

        for(i=5; i>0; i--) {
                c[i-1] = comb%10;
                comb/=10;
        }

        printf("\n\nHas introducido: ");
        for(i=0; i<5; i++) {
                printf("%d",c[i]);
        }
        printf("\n");
        ValidarCombinacion(c,v,i,intentos);
}

int ValidarCombinacion(int c[], int v[], int i, int intentos){
        intentos--;
        if(intentos==0) {
                printf("\n\n\t\t=============================");
                printf("\n\t\t\tHAS PERDIDO :(\n");
                printf("\t\t=============================\n");
                return 0;
        }
        int j, cmas=0, cast=0; //j = interaccion, cmas = contador signo +, cast = contador asteriscos
        for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                        if((c[i]==v[j])&&(i!=j)) {
                                cast++;
                        }
                        if((c[i]==v[j])&&(i==j)) {
                                cmas++;
                        }
                }
        }
        if(cmas<5) {
                printf("\t  Pista: ");
                for(i=0; i<cmas; i++) {
                        printf("+");
                }
                for(i=0; i<cast; i++) {
                        printf("*");
                }
                printf("\n");
                IntroducirCombinacion(c,i,v,intentos);
        }else{
                printf("\n\n\t\t=========================");
                printf("\n\t\t\tHAS GANADO!\n");
                printf("\t\t=========================\n");
                return 0;
        }
}

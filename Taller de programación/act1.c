#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int salir();
int menu();
int volverMenu();
int quitarCeros();
int esPrimo();
int Mprimeros();

int salir(){
        return 0;
}

int volverMenu(){
        int opcion_menu_volver;
        do {
                printf("\n\n¿Deseas volver al menu principal?");
                printf("\n\n 1. Volver al menu");
                printf("\n 2. Salir");
                printf("\n\nTeclea opcion [1 - 2]: ");
                scanf("%d",&opcion_menu_volver);
                fflush(stdin);

                switch(opcion_menu_volver) {
                case 1: menu(); break;
                case 2: salir(); break;
                default: printf("\n\tError: Opcion incorrecta.");
                }
        } while((opcion_menu_volver>2)||(opcion_menu_volver<1));
}

int quitarCeros(){
        int secuencia_numeros;
        int aux_secuencia_numeros = -1; //Utilizamos el -1 como numero auxiliar
        printf("\n\n\t Quitar ceros consecutivos.\n\n");
        printf("Introduce una secuencia de numeros [fin = -1]: ");
        scanf("%d",&secuencia_numeros);
        while(secuencia_numeros != -1) {
                fflush( stdin );
                if((secuencia_numeros ==0)&&(aux_secuencia_numeros == 0)) {
                }else{
                        printf("%d ",secuencia_numeros);
                }
                aux_secuencia_numeros = secuencia_numeros;
                scanf("%d",&secuencia_numeros);
        }
        printf("\n");
        volverMenu();
}

int esPrimo(){
        int num, cota;
        printf("\n\t Comprobar si es un n%cmero primo\n",163);
        printf("\nIntroduce un n%cmero: ");
        scanf("%d",&num);
        fflush( stdin );
        if(num > 1) {
                if(((num%2==0)||(num%3==0)||(num%5==0))) {
                        if((num==2)||(num==3)||(num==5)) {
                                printf("\n\n1. Es primo");
                        }else{
                                printf("\n\n0. No es primo");
                        }
                }else{
                        printf("\n\n1. Es primo");
                }
                printf("\n");
                volverMenu();
        }else{
                printf("\nDebes introducir un valor > 1. \n\n");
                esPrimo();
        }
}

int Mprimeros(){
}

int menu(){
        fflush(stdin);
        int opcion_menu;
        do {
                printf("\n\tMenu General\n\n");
                printf("1. Quitar ceros consecutivos.\n");
                printf("2. Funci%cn primo.\n",162);
                printf("3. M primeros primos.");
                printf("\n");
                printf("4. Salir.\n");
                printf("\nTeclear opci%cn: ",162);
                scanf("%d", &opcion_menu);
                fflush( stdin );

                switch(opcion_menu) {
                case 1:
                        quitarCeros();
                        break;
                case 2:
                        esPrimo();
                        break;
                case 3:
                        Mprimeros();
                        break;
                case 4:
                        salir();
                        break;
                default:
                        printf("\nOpci%cn incorrecta, por favor teclee un n%cmero del 1 al 4.\n\n",162,163);
                        break;
                }


        } while((opcion_menu > 4 || opcion_menu < 1));
        salir();
}

int main(){
        fflush(stdin);
        menu();
}

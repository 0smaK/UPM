#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Prototipos
int pedirDNI();
int pedirLetra();
char comprobarLetra();

int main(){
    pedirDNI();
}

int pedirDNI(){
    int dni;
    do{
        printf("\nIntroduce DNI (sin letra): ");
        scanf("%d",&dni);
    }while(dni<0||dni>99999999);
    pedirLetra(dni);
}

int pedirLetra(int dni){
    char letra;
    printf("\nIntroduce letra del DNI: ");
    fflush(stdin);
    scanf("%c",&letra);
    if(isalpha(letra)){
        letra = toupper(letra);
        comprobarLetra(letra, dni);
    }else{
        printf("\n No has introducido una letra");
        pedirLetra(dni);
    }
}

char comprobarLetra(char * letra, int dni){
    int resto = dni%23;
    char letra_valida;
    switch(resto){
        case 0: letra_valida='T'; break;
        case 1: letra_valida='R'; break;
        case 2: letra_valida='W'; break;
        case 3: letra_valida='A'; break;
        case 4: letra_valida='G'; break;
        case 5: letra_valida='M'; break;
        case 6: letra_valida='Y'; break;
        case 7: letra_valida='F'; break;
        case 8: letra_valida='P'; break;
        case 9: letra_valida='D'; break;
        case 10: letra_valida='X'; break;
        case 11: letra_valida='B'; break;
        case 12: letra_valida='N'; break;
        case 13: letra_valida='J'; break;
        case 14: letra_valida='Z'; break;
        case 15: letra_valida='S'; break;
        case 16: letra_valida='Q'; break;
        case 17: letra_valida='V'; break;
        case 18: letra_valida='H'; break;
        case 19: letra_valida='L'; break;
        case 20: letra_valida='C'; break;
        case 21: letra_valida='K'; break;
        case 22: letra_valida='E'; break;
    }
    if(letra==letra_valida){
        printf("\nLetra valida");
        printf("\n\nDNI correcto: %d%c\n",dni,letra);
        int r;
        do{
            printf("\n\nDesea introducir otro NIF?\n1 ==> Si\n0 ==> No\n\n=====> ");
            scanf("%d",&r);
            if(r==1){
                main();
            }
        }while(r=0);

        return 0;
    }else{
        printf("\Letra invalida, letra correcta: %c",letra_valida);
        pedirLetra(dni);
    }
}

//Escribir un programa que añada al final del fichero ENT.TXT los números 55 y 66.

#include <stdio.h>

int main(){
        FILE *pf1;
        pf1 = fopen("ENT.TXT","a"); //Abrimos pf1 en modo a

        int i=0,longitud; //definimos dos variables

        fprintf(pf1,"55\n66\n"); //Escribimos los numeros

        fclose(pf1); //Cerramos fichero

        return 0;
}

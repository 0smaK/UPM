/*
* REALIZAR MENU CON OPCIONES PARA QUE GIRE UNA MATRIZ Y OTRA OPCION PARA QUE COMPRUEBE SI UN VECTOR ES GIRADO DE OTRO
*
* ENTREGAR ANTES DEL LUNES 11/12/2017
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 3

//prototipos
int esgiro (int A[], int B[], int *tamgiro);
void rotar (int mat[N][N]);

int main(){
    int A[N];
    int B[N];
    int mat[N][N];

    int tamgiro = 0;

    printf("\nA continuacion inserte los datos en la matriz A: \n");

    int i = 0, j = 0;
    for(i=0;i<N;i++){
        printf("Matriz A[%d]: ",i); scanf("%d",&A[i]);
        fflush(stdin);
    }

    printf("\n");

    for(i=0;i<N;i++){
        printf("Matriz B[%d]: ",i); scanf("%d",&B[i]);
        fflush(stdin);
    }

    ///                  DEBUG              ///

    int giro = esgiro(A,B,&tamgiro);
    printf("\n\nValor de giro: %d",giro);
    if(giro==0) tamgiro = -1;

    printf("\nTamanyo de giro: %d\n",tamgiro);

    return 0;
}

int esgiro (int A[], int B[], int *tamgiro){
    int i=0,j=0,k=0,
    Ag[N], giro = 0;

    for(i=0;i<N;i++){
        Ag[i] = A[i];
    }

    for(i=0;i<N;i++){
        printf("\nAg: %d - B: %d",Ag,B);
        if(Ag==B){
            giro = 1;
        }else{
            int x = N-1;
            Ag[0] = A[x];

            for(k=1;k<N;k++){
                Ag[i] = A[i-1];
            }
            printf("\nVector girado: ");
            for(j=0;j<N;j++){
                printf("%d ",Ag[j]);
            }
            printf("\n");
        }
    }

    printf("\nVector A: ");
    for(j=0;j<N;j++){
        printf("%d ",A[j]);
    }

    printf("\nVector B: ");
    for(j=0;j<N;j++){
        printf("%d ",B[j]);
    }
    return giro;
}

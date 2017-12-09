/*
* REALIZAR MENU CON OPCIONES PARA QUE GIRE UNA MATRIZ Y OTRA OPCION PARA QUE COMPRUEBE SI UN VECTOR ES GIRADO DE OTRO
*
* ENTREGAR ANTES DEL LUNES 11/12/2017
*/


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
    int i=0,j=0,k=0, Ac[N], Ag[N], giro = 0, b_igual = 1;

	//copiamos A[] en Ac[]

    for(i=0;i<N;i++){
        Ac[i] = A[i];
        Ag[i] = A[i];
    }
	
	//Hasta que o se acabe todos los giros posibles del array o hasta que lo encuentre ejecutar lo que está en el do...while
	
	do{
		
		//Comprobamos si Ag[] y B[] son iguales
		b_igual=1;
		for(i=0;i<N;i++){
			if(Ag[i] != B[i]){
				b_igual=0;
			}
		}
		
		//Giramos el array
		
		Ag[0] = Ac[N-1];
		for(i=1;i<N;i++){
			Ag[i] = Ac[i-1];
		}

		//Copia Ag[] en Ac[]
		
		for(i=0;i<N;i++){
        	Ac[i] = Ag[i];
    	}
    
    	//Asignamos el valor j a tamgiro
    	
		*tamgiro = j;
		j++;
		
	}while((b_igual == 0)&&(j<N));

	if(b_igual==1)giro=1;

	//Imprimir vectores A[] y B[]
	
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

void rotar (int mat[N][N]{}
	

/*
* REALIZAR MENU CON OPCIONES PARA QUE GIRE UNA MATRIZ Y OTRA OPCION PARA QUE COMPRUEBE SI UN VECTOR ES GIRADO DE OTRO
*
* ENTREGAR ANTES DEL LUNES 11/12/2017
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 3 //DEFINIR VALOR DE LA MATRIZ CUADRADA

//prototipos
int esgiro (int A[], int B[], int *tamgiro);
void rotar (int mat[N][N]);
int menu(int *opc);
int leerdatos_esgiro(int A[N], int B[N]); 
int leerdatos_rotar(int mat[N][N]);

int main(){
	
	int opc;
	menu(&opc);
    int A[N];
    int B[N];
    int mat[N][N];

	fflush(stdin);

    int tamgiro = 0;
	
	switch(opc){
		case 1: leerdatos_esgiro(A,B);	
				int giro = esgiro(A,B,&tamgiro);
    			printf("\n\nValor de giro: %d",giro);
    			if(giro==0) tamgiro = -1;
    			printf("\nTamanyo de giro: %d\n",tamgiro);
				break;
		case 2: leerdatos_rotar(mat); 
				rotar(mat);
				break;
		case 0: exit(0); 
				break;
		default: menu(&opc);
	}
	

    return 0;
}

int menu(int *opc){
	
	printf("\nElige una opcion.\n\n");
	printf("1. Girar array");
	printf("\n2. Rotar matriz");
	printf("\n0. Salir");
	printf("\n\n>>>>[0-2]: ");
	scanf("%d",opc);
	return *opc;
}

int leerdatos_esgiro(int A[N], int B[N]){
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

int leerdatos_rotar(int mat[N][N]){
	printf("\n\nA continuacion inserte los datos en la matriz: \n\n");
	int i = 0, j = 0;
	
	//rellenar matriz
	
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("mat[%d][%d]: ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
}

void rotar (int mat[N][N]){
	int i = 0, j = 0;
	
	printf("\n");
	//imprimimos matriz
	printf("Matriz inicial:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	int aux;
	//rotamos matriz, algoritmo: N-j-1, i. Así imprime la matriz girada.
	
	for (i = 0; i < N; i++){
        for (j = i + 1; j < N; j++){
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
 
    for (i = 0; i < N; i++){
        
		for (j = 0; j < N / 2; j++){
            aux = mat[i][j];
            mat[i][j] = mat[i][N - 1 - j];
            mat[i][N - 1 - j] = aux;
        }
	}
	printf("\nMatriz girada 90 grados:\n");
	
	//imprimimos nuestra nueva matriz
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
}

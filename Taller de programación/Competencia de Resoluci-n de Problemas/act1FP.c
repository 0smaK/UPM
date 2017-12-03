#include <stdio.h>
#define matricula "bo0548"
#define nombre "Munoz Cano, Oscar"

//Prototipos
int crearAlgoritmo(int n, int *algoritmo);
int crearTarjeta(int vprimer[], int algoritmo, int *longitud, int n_tarjeta);
int adivinar(int vprimer[], int longitud);

int main(){
	int n_tarjeta = 1, algoritmo, longitud = 0;
	int vprimer[7];
	printf("\nPiensa un numero del 1 al 100");
	printf("\ny a continuacion contesta las siguientes preguntas con Si (s/S) o No (n/N)\n\n");
	
	do{  //Bucle do...while que ejecuta las diferentes funciones 7 veces
		crearAlgoritmo(n_tarjeta,&algoritmo); //Crea el "algoritmo" para saber que numeros tiene que imprimir
		crearTarjeta(vprimer, algoritmo, &longitud, n_tarjeta); //Imprime los numeros y te pide si el numero que has pensado esta en la lista
		n_tarjeta++;
	}while(n_tarjeta<=7);
	
	adivinar(vprimer, longitud); //Te adivina el numero
	
	return 0; //salimos sin errores del programa
}

/*
* Funcion que crea el algoritmo
* Cada tarjeta tiene asignado diferente tipo de algoritmo y esta funcion calcula como tiene que hacerlo
*/
int crearAlgoritmo(int n, int *algoritmo){
	switch(n){ 
		case 1: //algoritmo +2                                  0
		    *algoritmo = 0;
			break;
		case 2: //algoritmo +1 +(1+2)                           1
			*algoritmo = 1;
			break;
		case 3: //algoritmo +1 (3 veces) +(3+2)                 3
			*algoritmo = 3;
			break;
		case 4: //algoritmo +1 (7 veces) +(7+2)                 7
			*algoritmo = 7;
			break; 
		case 5: //algoritmo +1 (15 veces) +(15+2)               15
			*algoritmo = 15;
			break;
		case 6: //algoritmo +1 (31 veces) +(31+2)               31
			*algoritmo = 31;
			break;
		case 7: //algoritmo +1 (63 veces) +(63+2)               63
			*algoritmo = 63;
			break;
	}
}

/*
* Funcion que crea la tarjeta
*/
int crearTarjeta(int vprimer[],int algoritmo, int *longitud, int n_tarjeta){
	int n_gen=0, primernum = 0, i = 0, j=0;

	n_gen = algoritmo+1; //Algoritmo + 1 siempre es el primer numero
	printf("\n%d\n",n_gen);
	primernum=n_gen;
	
	while(n_gen<=100){ 
		for(i=0;i<algoritmo;i++){
			n_gen++;
			if(n_gen<=100) printf("%d ",n_gen);
		}
		n_gen=n_gen+(algoritmo+2);
		if(n_gen<=100) printf("%d ",n_gen);
	}
	
	int resp;
	printf("\n\nEsta el numero en la lista? >>> ");
        fflush(stdin);

	scanf("%c",&resp);
	if((resp=='s')||(resp=='S')){
		vprimer[*longitud] = primernum;
		(*longitud)++;
    }
		
}

int adivinar(int vprimer[],int longitud){
	int i = 0, numero_adivinado=0;
	for (i=0; i<longitud; i++){
		numero_adivinado += vprimer[i];
	}
	printf("\n\n\t================================================\n");
	printf("\t\tEl numero que has pensado es el %d",numero_adivinado);
	printf("\n\t================================================\n");
}

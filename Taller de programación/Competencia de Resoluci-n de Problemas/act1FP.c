
#include <stdio.h>

//Prototipos
int crearAlgoritmo(int n, int *algoritmo);
int crearTarjeta(int vprimer[], int algoritmo, int *longitud, int n_tarjeta);
int adivinar(int vprimer[], int longitud);

int main(){
	int n_tarjeta = 1, algoritmo, longitud = 0;
	int vprimer[7];
	printf("\nPiensa un numero del 1 al 100");
	printf("\ny a continuacion contesta las siguientes preguntas con Si (s/S) o No (n/N)\n\n");
	
	do{
		crearAlgoritmo(n_tarjeta,&algoritmo);
		crearTarjeta(vprimer, algoritmo, &longitud, n_tarjeta);
		n_tarjeta++;
	}while(n_tarjeta<=7);
	
	adivinar(vprimer, longitud);
	
	return 0;
}

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

int crearTarjeta(int vprimer[],int algoritmo, int *longitud, int n_tarjeta){
	int n_gen=0, i = 0 , primernum = 0;
	n_gen = algoritmo+1;
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
			vprimer[n_tarjeta] = primernum;
			printf("\n\nDEB: %d\n\n",vprimer[n_tarjeta]);
			(*longitud)++;
		}
		
}

int adivinar(int vprimer[],int longitud){
	int i = 0, numero_adivinado=0;
	for (i=0; i<longitud; i++){
		printf("\n\nv[%d]: %d",i,vprimer[i]);
		printf("\nnumad: %d",numero_adivinado);
		numero_adivinado += vprimer[i];
	}
	printf("\n\n\t================================================\n");
	printf("\t\tEl numero que has pensado es el %d",numero_adivinado);
	printf("\n\t================================================\n");
}

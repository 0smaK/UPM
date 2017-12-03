#include <stdio.h>
#include <stdlib.h>

#define NumDias 30

//prototipos de funciones que se usan en el programa 
int menuPP(int tMAX[], int tMIN[]);
int menuIntroducirDatos(int tMAX[], int tMIN[]);
int menuTrabajarDatos(int tMAX[], int tMIN[]);
int IntroducirMAX(int tMAX[]);
int IntroducirMIN(int tMIN[]);
int CalcMAXMED(int tMAX[], int *mediaMAX);
int CalcMINMED(int tMIN[], int *mediaMIN);
int CalcDiasSupMediaMax(int tMAX[], int mediaMAX);
int CalcCoincid(int tMIN[], int mediaMIN); 
int CalcMinMin(int tMIN[]); 
int CalcMaxMax(int tMAX[]); 

int main(){
	int tMAX[30], tMIN[30];
	menuPP(tMAX, tMIN);
	return 0;
}

/*
* Menu Principal.
* Muestra por pantalla las 3 opciones principales y contiene un switch que controla la opcion.
*/
int menuPP(int tMAX[], int tMIN[]){
	int opc;
	do{
		printf("\nEscoge una opcion.\n\n");
		printf("1. Introducir datos\n");
		printf("2. Trabajar con los datos\n");
		printf("3. Salir del programa\n\n");
		
		printf(">>>>>>>>>> ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1: menuIntroducirDatos(tMAX, tMIN); break; //Nos dirige al menu para introducir datos
			case 2: menuTrabajarDatos(tMAX, tMIN); break; //Nos dirige al menu para trabajar con los datos 
			case 3: exit(0); break; //Se cierra el programa
			default: printf("\nERROR OPCION INVALIDA."); menuPP(tMAX, tMIN); //en caso de entrada invalida, nos vuelve a mostrar el menu
		}
	}while(opc!=3);
	
}

/*
* Menu Introducir Datos
* Muestra por pantalla el contenido del menu y nos lleva a las distintas funciones que lo contienen
*/
int menuIntroducirDatos(int tMAX[], int tMIN[]){
	int opc;
	do{
		printf("\n\nEscoge una opcion.\n\n"); 
		printf("11. Introducir temperaturas maximas\n"); 
		printf("12. Introducir temperaturas minimas\n");
		printf("13. Volver al menu anterior\n\n");
		
		printf(">>>>>>>>>> ");
		scanf("%d",&opc);
		
		switch(opc){
			case 11: IntroducirMAX(tMAX); break; //Nos lleva a la funcion para introducir las temperaturas maximas
			case 12: IntroducirMIN(tMIN); break; //Nos lleva a la funcion para introducir las temperaturas minimas
			case 13: menuPP(tMAX, tMIN);  break; //Nos regresa al menu principal
			default: printf("\nERROR OPCION INVALIDA."); menuIntroducirDatos(tMAX, tMIN); //En caso de entrada invalida, vuelve a mostrar el menu
		}
	}while(opc!=13);
}

/*
* Funcion para trabajar datos
* Muestra por pantalla contenido del menu y un switch que te lleva a las diferentes funciones
*/
int menuTrabajarDatos(int tMAX[], int tMIN[]){
	int opc;
	do{		
		int mediaMAX, mediaMIN;
	
		printf("\n\nEscoge una opcion.\n\n");
		printf("21. Calcular la temperatura media maximas del mes\n");
		printf("22. Calcular la temperatura media minimas del mes\n");
		printf("23. Calcular cuantos dias se ha superado la media de las maximas\n");
		printf("24. Calcular cuantos dias coincide la temperatura minima con la media de las minimas\n");
		printf("25. Calcular la temperatura mínima de las mínimas\n");
		printf("26. Calcular la temperatura máxima de las máximas\n");
		printf("27. Volver al menu anterior\n\n");
		
		printf(">>>>>>>>>> ");
		scanf("%d",&opc);
		
		switch(opc){
			case 21: CalcMAXMED(tMAX, &mediaMAX); break; //Te lleva a la funcion de calcular la media de las max
			case 22: CalcMINMED(tMIN, &mediaMIN); break; //Te lleva a la funcion de calcular la media de las min
			case 23: CalcDiasSupMediaMax(tMAX, mediaMAX); break; //Calcula los idas que se superan las temperaturas maximas
			case 24: CalcCoincid(tMIN, mediaMIN); break; //Calcula los dias que coincide la Temp. minima con la media de las minimas
			case 25: CalcMinMin(tMIN); break; //Calcula la temperatura minima de las temperaturas minimas
			case 26: CalcMaxMax(tMAX); break; //Calcula la temperatura maxima de las temperaturas maximas
			case 27: menuPP(tMAX, tMIN); break;
			default: printf("\nERROR OPCION INVALIDA."); menuTrabajarDatos(tMAX, tMIN);
		}
	}while(opc!=27);
}

/*
* En esta funcion se introducen las temp maximas del mes
*/
int IntroducirMAX(int tMAX[]){
	printf("\n\nIntroduce a continuacion las temperaturas maximas del mes: ");
	int dia = 0;
	for(dia = 0; dia < NumDias;dia++){
		printf("\nDia %d: ",dia+1);
		scanf("%d",&tMAX[dia]);
	}
}

/*
* En esta funcion se introducen las temp minimas del mes
*/
int IntroducirMIN(int tMIN[]){
	printf("\n\nIntroduce a continuacion las temperaturas minimas del mes: ");
	int dia = 0;
	for(dia = 0; dia<NumDias;dia++){
		printf("\nDia %d: ",dia+1);
		scanf("%d",&tMIN[dia]);
	}
}

/*
* En esta funcion se calcula mediante un ciclo for la media de las maximas
*/
int CalcMAXMED(int tMAX[], int *mediaMAX){
	int i=0;
	for(i=0;i<NumDias;i++){ //esto va sumando en la variable media las temperaturas hasta que i sea 30
		*mediaMAX+=tMAX[i];
	}
	*mediaMAX/=30; //cuando los valores esten sumados se divide entre 30 para conseguir la media
	printf("\n\nLa temperatura media maxima es: %dºC\n",*mediaMAX);
}

/*
* En esta funcion se calcula mediante un ciclo for la media de las minimas
*/
int CalcMINMED(int tMIN[], int *mediaMIN){
	int i=0;
	for(i=0;i<NumDias;i++){ //esto va sumando en la variable media las temperaturas hasta que i sea 30
		*mediaMIN+=tMIN[i];
	}
	*mediaMIN/=30; //cuando los valores esten sumados se divide entre 30 para conseguir la media
	printf("\n\nLa temperatura media minima es: %dºC",*mediaMIN);
}

int CalcDiasSupMediaMax(int tMAX[], int mediaMAX){
	int i=0, dias_superados=0;
	for(i=0;i<NumDias;i++){
		if(tMAX[i]>mediaMAX){
			dias_superados++;
		}
	}
	printf("\n\nEn este mes se ha superado la media maxima un total de %d veces.",dias_superados);
}

int CalcCoincid(int tMIN[], int mediaMIN){
	int i=0, coinciden=0;
	for(i=0;i<NumDias;i++){
		if(tMIN[i]==mediaMIN){
			coinciden++;
		}
	}
	printf("\n\nEn este mes las temperaturas minimas y la media coinciden un total de %d veces.",coinciden);
}
int CalcMinMin(int tMIN[]){
	int i = 1, minimo = tMIN[0];
	for(i=1; i<NumDias;i++){
		if(tMIN[i]<minimo){
			minimo=tMIN[i];
		}
	}
	printf("\n\nLa temperatura minima de las temperaturas minimas es de %dºC",minimo);
	
}
int CalcMaxMax(int tMAX[]){
	int i = 1, maximo = tMAX[0];
	for(i=1; i<NumDias;i++){
		if(tMAX[i]>maximo){
			maximo=tMAX[i];
		}
	}
	printf("\n\nLa temperatura maxima de las temperaturas maximas es de %dºC",maximo);
}

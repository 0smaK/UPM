#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	
	=======================
	Autor: Óscar 
	Grupo: 
	ETSI SIST. INFORMATICOS
	=======================
	
	Valores numeros romanos:
	I = 1
	V = 5
	X = 10
	L = 50
	C = 100
	D = 500
	M = 1000
	*/
	printf("Introduzca un n%cmero romano (Finalizar cadena con '.'): ",163);
	int letra, //Letra introducida en el programa (M/D/C/L/X/V/I)
		valor = 0, //valor que toma control del numero romano que se introduce y lo traduce a numero decimal
		valor_anterior = 1001, //Valor anterior de la cadena para saber si es menor o mayor, establecemos 1001 por defecto para que el programa no lea que es menor en el inicio
		aviso = 0; //si coinciden el valor anterior y el actual son iguales, aviso se transforma en 1, y si aviso es 1 y el valor del siguiente es mayor al anterior el programa se para
	do{
		letra = getchar();
		switch(letra){
			
			case 'M': //1000
				valor += 1000;
				if(1000>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior<1000)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>1000)){
					aviso = 0;
				}
				if(valor_anterior==1000){
					aviso = 1;
				}
				valor_anterior = 1000;
				break;
			case 'D': //500
				valor += 500;
				if(500>valor_anterior){
					valor = valor - (valor_anterior*2);  
				}
				if((aviso==1)&&(valor_anterior<500)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>500)){
					aviso = 0;
				}
				if(valor_anterior==500){
					aviso = 1;
				}
				valor_anterior = 500;
				break;
			case 'C': //100
				valor += 100;
				if(100>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior<100)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>100)){
					aviso = 0;
				}
				if(valor_anterior==100){
					aviso = 1;
				}
				valor_anterior = 100;
				break;
			case 'L': //50
				valor += 50;
				if(50>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior<50)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>50)){
					aviso = 0;
				}
				if(valor_anterior==50){
					aviso = 1;
				}
				valor_anterior = 50;
				break;
			case 'X': //10
				valor += 10;
				if(10>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior>10)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior<10)){
					aviso = 0;
				}
				if(valor_anterior==10){
					aviso = 1;
				}
				valor_anterior = 10;
				break;
			case 'V': //5
				valor += 5;
				if(10>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior<5)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>5)){
					aviso = 0;
				}
				if(valor_anterior==5){
					aviso = 1;
				}
				valor_anterior = 5;
				break;
			case 'I': //1
				valor += 1;
				if(1>valor_anterior){
					valor = valor - (valor_anterior*2); 
				}
				if((aviso==1)&&(valor_anterior<1)){
					printf("El n%cmero romano introducido es incorrecto, El programa se va a detener",163);
					return 0;
				}
				if((aviso==1)&&(valor_anterior>1)){
					aviso = 0;
				}
				if(valor_anterior==1){
					aviso = 1;
				}
				valor_anterior = 1;
				break;
			case '.':
				break;
			case '\n':
				printf("\nPara finalizar la introducci%cn del numero teclee un punto ('.') y a continuaci%cn presione intro ",162,162);
				break;
			default: 
				printf("\nEl car%ccter '",160); putchar(letra); printf("' no est%c permitido en los n%cmeros romanos. El programa se detendr%c\n",160,163,160);
				return 0;
				break;
		}
	}while(letra != '.');
	printf("\n=======================================================================\n");
	printf("\n\tEl n%cmero decimal introducido corresponde a %d: \n",163, valor);
	printf("\n=======================================================================\n");
	return 0;
}

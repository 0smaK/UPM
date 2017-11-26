//TO-DO
/*
 * Se leen desde un fichero de texto (ENT.TXT) una secuencia de valores indeterminada de números enteros,
 * como máximo 20. Escribir un programa que grabe en otro fichero de texto (SAL.TXT)
 * solo aquellos valores que han sido leídos y que sea múltiplos de 5.
 * El fichero de texto ENT.TXT debe ser creado previamente con block de notas.
 * El fichero de texto SAL.TXT si existe previamente se perderá.
 */
#include <stdio.h>

//prototipos
void leer(FILE *pf1, int v[], int *longitud);
void grabar(int v[], int longitud,FILE *pf2);

int main(){
        FILE *pf1;
		FILE *pf2;
        int v[20];
        int longitud = 0;

        leer(pf1,v,&longitud);
	grabar(v,longitud,pf2);
        
        return 0;
}
void leer(FILE *pf1, int v[], int *longitud){	
	pf1 = fopen("ENT.TXT","r");
	int i,valor;
    while((fscanf(pf1,"%d",&valor))!=EOF){
	    if((valor%5)==0){
		  	(*longitud)++;
	    	v[i] = valor;
			i++;
		}
	}
	fclose(pf1);
}

void grabar(int v[], int longitud,FILE *pf2){
	pf2 = fopen("SAL.TXT","w");
	int i;
	for(i=0;i<longitud;i++){
		fprintf(pf2,"%d\n",v[i]);
	}	
	fclose(pf2);
}

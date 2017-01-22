#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libre.h"
#define NCoef 2
#define DCgain 33250

struct formato_wav {
    char        ChunkID[4];          
    int32_t     ChunkSize;          //4 bytes
    int32_t     Format;
    int32_t     Subchunk1ID;
    int32_t     Subchunk1Size;
    int16_t     AudioFormat;
    int16_t     NumChannels;
    int32_t     SampleRate;
    int32_t     ByteRate;
    int16_t     BlockAlign;
    int16_t     BitsPerSample;
    char        Data[4];
	int32_t     Subchunk2Size;        
};

void AEIOU(FILE* f1,FILE* f2,FILE* f3,FILE* f4,FILE* f5,FILE* f6){ 

    int16_t data,A,E,I,O,U;
    int i=0;

    while(fread(&data,sizeof(int16_t),1,f1)){
    	//Vocal A
        A=fir1A(data);
		A=fir2A(A);
		A=fir3A(A);
		//printf("%i\n",A);
        fwrite(&A,sizeof(int16_t),1,f2);
        
        //Vocal E
        E=fir1E(data);
		E=fir2E(E);
		E=fir3E(E);
        E=fir4E(E);
        E=fir5E(E);
        E=fir6E(E);
		//printf("%i\n",A);
        fwrite(&E,sizeof(int16_t),1,f3);
        
        //Vocal I
        I=fir1I(data);
		I=fir2I(I);
		I=fir3I(I);
        //I=fir4I(I);
        I=fir5I(I);
        //I=fir6I(I);
		//printf("%i\n",A);
        fwrite(&I,sizeof(int16_t),1,f4);
        
        //Vocal O
        O=fir1O(data);
		O=fir2O(O);
		O=fir3O(O);
        O=fir4O(O);
        O=fir5O(O);
        O=fir6O(O);
		//printf("%i\n",A);
        fwrite(&O,sizeof(int16_t),1,f5);
        
        //Vocal U
        U=fir1U(data);
		U=fir2U(U);
		U=fir3U(U);
        U=fir4U(U);
        U=fir5U(U);
        U=fir6U(U);
		//printf("%i\n",A);
        fwrite(&U,sizeof(int16_t),1,f6);

        i++;
    }printf("Correcto: %i\n",i);
    
    return;
}

void archivo(){
    FILE *f1;
    FILE *f2;
    FILE *f3;
    FILE *f4;
    FILE *f5;
    FILE *f6;

    f1 = fopen("tren1.wav","rb");
    f2 = fopen("A.wav","wb+");
    f3 = fopen("E.wav","wb+");
    f4 = fopen("I.wav","wb+");
    f5 = fopen("O.wav","wb+");
    f6 = fopen("U.wav","wb+");
    

    struct formato_wav cabecera;

    //leer cabecera
    fread(&cabecera,sizeof(cabecera),1,f1);
    
    printf("El Numero de canales es: %d\n", (int)cabecera.NumChannels);
    printf("El Tamaño de los datos es: %d\n\n", (int)cabecera.Subchunk2Size);
    
    //Poner Cabecera
    fwrite(&cabecera,sizeof(cabecera),1,f2);
    fwrite(&cabecera,sizeof(cabecera),1,f3);
    fwrite(&cabecera,sizeof(cabecera),1,f4);
    fwrite(&cabecera,sizeof(cabecera),1,f5);
    fwrite(&cabecera,sizeof(cabecera),1,f6);

    //AEIOU
    AEIOU(f1,f2,f3,f4,f5,f6);    

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);

    return;
}

int main(){
    archivo();
    return 0;
}

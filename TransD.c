#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#define DCgain 32767
    

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

void Trans_D(FILE *f1, FILE *f2,int length){
    int16_t data;
    int32_t datos[length];
    int i=0,j;

    while(fread(&data,sizeof(data),1,f1)){
        datos[i]=data;
        //printf("data %d: %d\n",i,datos[i]);
        i++;
        
        if(i==length)
            break;
    }printf("Correcto: %i\n",i);

    int32_t ec[length];
    int32_t es[length];
    for (i = 0; i < length; i++){
        ec[i]=0;
        es[i]=0;
        double angulo=2*M_PI/length;
        ec[i] += datos[i]*cos(angulo);
        es[i] -= datos[i]*sin(angulo);      
        //printf("Cos %i: %i\n",i,es[i]);
    }

    double Gain,divisor;
    for (i = 0; i < length-1; i++){
        if(ec[i]<ec[i+1])
            Gain=ec[i+1];    
    }

    printf("%i \n",Gain);


    divisor= (Gain/DCgain);
    if(divisor==0)
        divisor=1;


    //printf("Div: %i \n",divisor);
    for (i = 0; i < length; i++){
        printf("Cos %i: %i\n",i,data);
        data=ec[i]/divisor;
        fwrite(&data,sizeof(data),1,f2);
        
        data=es[i]/divisor;
        fwrite(&data,sizeof(data),1,f2);
    }
    
    return;
}

void archivo(FILE *f1,FILE* f2){
    int16_t data;
    struct formato_wav cabecera, trans;

    //leer cabecera
    fread(&cabecera,sizeof(cabecera),1,f1);
    

    printf("El Numero de canales es: %d\n", (int)cabecera.NumChannels);
    printf("El Tamaño del archivo es: %d\n", (int)cabecera.ChunkSize);
    printf("El Tamaño de los datos es: %d\n\n", (int)cabecera.Subchunk2Size);
    
    trans=cabecera;
    trans.ChunkSize= 2*trans.Subchunk2Size+110;
    trans.NumChannels=2;
    trans.ByteRate= trans.SampleRate * 2 * trans.BitsPerSample/8;
    trans.BlockAlign=2*trans.BitsPerSample/8;
	trans.Subchunk2Size=2*trans.Subchunk2Size;

    //Poner Cabecera
    fwrite(&trans,sizeof(trans),1,f2);
    
    //Trnasformada
	Trans_D(f1,f2,(int)cabecera.Subchunk2Size/2);
	
	
    while(fread(&data,sizeof(data),1,f1))
        fwrite(&data,sizeof(data),1,f2);

    fclose(f1); 
    fclose(f2);
}

int main(int argc,const char* argv[]){
    FILE *f1, *f2;
    /*
    if (argc<1) {
        fprintf(stderr,"usage: Transformada <Nombre Archivo Entrada>\n");
        exit(1);
    }
    const char *arch=argv[1];*/
    f1 = fopen("cos.wav","rb");
    f2 = fopen("copiado.wav","wb+");
    archivo(f1,f2);
    return 0;
}
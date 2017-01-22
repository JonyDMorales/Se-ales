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

void Trans_I(FILE *f1, FILE *f2,int length){
    int16_t data;
    int32_t a[length],b[length];
    int i=0,j,k;

    //printf("L %d\n",length);

    while(fread(&data,sizeof(data),1,f1)){
        a[i]=data;
        fread(&data,sizeof(data),1,f1);
        b[i]=data;
        //printf("data %d: %d\n",i,datos[i]);
        i++;
        if(i==length)
            break;
    }printf("Correcto: %i\n",i);
    
    int32_t t;
    for (i = 0; i < length; i++){
        t=0;
        for (j = 0; j <length/2; j++){
            double angulo=2*M_PI*i*j/length;
            t += a[j]*cos(angulo)+b[j]*sin(angulo);
        }
        data=t;
        printf("%i: %i\n",i,data);
        fwrite(&data,sizeof(data),1,f2);
        //printf("%i: %i\n",i,t[i]);
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
    trans.ChunkSize= (trans.Subchunk2Size/2)+110;
    trans.NumChannels=1;
    trans.ByteRate= trans.SampleRate*1*trans.BitsPerSample/8;
    trans.BlockAlign=1*trans.BitsPerSample/8;
	trans.Subchunk2Size=trans.Subchunk2Size/2;

    //Poner Cabecera
    fwrite(&trans,sizeof(trans),1,f2);
    
    //Trnasformada
	Trans_I(f1,f2,(int)cabecera.Subchunk2Size/4);
	
	
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
    f1 = fopen("copiado.wav","rb");
    f2 = fopen("original.wav","wb+");
    archivo(f1,f2);
    return 0;
}
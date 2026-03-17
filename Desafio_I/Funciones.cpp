#include "Funciones.h"

unsigned char **crearTablero(unsigned short int alto, unsigned short int ancho){
    unsigned short int ancho_bytes=ancho/8;

    unsigned char **tablero=new unsigned char*[alto];

    for (int i=0;i<alto;i++){
        tablero [i]=new unsigned char[ancho_bytes];

        for (int j=0;j<ancho_bytes;j++){
            tablero[i][j]=0;
        }
    }
    return tablero;
}

void liberarTablero(unsigned char**tablero,unsigned short int alto){

    for(int i=0;i<alto;i++){
        delete [] tablero[i];
    }
    delete [] tablero;
}

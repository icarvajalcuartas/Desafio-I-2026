#include "Funciones.h"
#include <cstdlib>
#include<ctime>
bool dimensionesValidas(unsigned short alto, unsigned short ancho)
{
    if(alto<8||ancho<8){
        return false;
    }
    if(ancho%8 !=0){
        return false;
    }
    return true;
}
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

void inciarSemilla()
{
    srand(time(0);
}

void generarPieza(unsigned char *pieza,int )
{
    unsigned char piezas[5][4];
    [[0b00010000,0b00010000,0b00010000,0b00010000],
    [0b00011000,0b00011000,0b00000000,0b00000000],
    [0b00001100,0b00011000,0b00000000,0b00000000],
    [0b00010000,0b00010000,0b00011000,0b00000000],
    [0b00011100,0b00001000,0b00000000,0b00000000]
    ]

    int tipo=rand()%5;
    unsigned char *ptr=*(pieza+tipo);
    for(int i=0;i<4;i++){
        *(pieza+i)=*(ptr+i);
    }
}

void juego(unsigned char **tablero, unsigned short alto, unsigned short ancho)
{
    unsigned char *pieza[4];

    generarPieza(pieza);
}





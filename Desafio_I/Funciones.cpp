#include "Funciones.h"
#include <cstdlib>
#include<ctime>
#include <iostream>

using namespace std;

bool dimensionesValidas(unsigned short int alto, unsigned short int ancho)
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
    srand(time(0));
}

void generarPieza(unsigned char *pieza,unsigned short int &tipo )
{
    unsigned char piezas[5][4]={
    {0b00010000,0b00010000,0b00010000,0b00010000},
    {0b00011000,0b00011000,0b00000000,0b00000000},
    {0b00001100,0b00011000,0b00000000,0b00000000},
    {0b00010000,0b00010000,0b00011000,0b00000000},
    {0b00011100,0b00001000,0b00000000,0b00000000}};


    tipo=rand()%5;
    unsigned char *ptr=*(piezas+tipo);
    for(int i=0;i<4;i++){
        *(pieza+i)=*(ptr+i);
    }
}

bool bitPieza(unsigned char *pieza, int fila, int col)
{
    unsigned char mascara = (unsigned char)(1<<(7-col));
    return (pieza[fila] &mascara)!=0;

}
bool bitTablero(unsigned char **tablero, int fila, int col)
{
    int iByte=col/8;
    int iBit=col%8;
    unsigned char mascara = (unsigned char)(1<<(7-iBit));
    return (tablero[fila][iByte] &mascara)!=0;


}
bool colision(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, int fila, int columna)
{for (int f=0;f<4;f++){
        for (int c=0;c<8;c++){
            if (bitPieza(pieza,f,c)){
                int filareal = fila+f;
                int colreal=columna+c;
                if (colreal<0 ||colreal>=ancho){
                    return true;
                }
                if (filareal>=alto){
                    return true;
                }
                if (bitTablero(tablero,filareal,colreal)){
                    return true;
                }
            }
        }
    }
    return false;

}

void juego(unsigned char **tablero, unsigned short int alto, unsigned short int ancho)
{
    unsigned char pieza[4];
    unsigned short int tipo = 0;
    int fila = 0;
    int col = (ancho/2)-4;
    bool gameOver = false;

    generarPieza(pieza,tipo);

    if (colision(tablero,alto,ancho,pieza,fila,col)) {
        gameOver = true;
    }
    if(gameOver){
        cout<<"*****GAME OVER***** <3"<<endl;
    }
}














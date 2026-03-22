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

    for (short int i=0;i<alto;i++){
        tablero [i]=new unsigned char[ancho_bytes];

        for (short int j=0;j<ancho_bytes;j++){
            tablero[i][j]=0;
        }
    }
    return tablero;
}

void liberarTablero(unsigned char**tablero,unsigned short int alto){

    for(short int i=0;i<alto;i++){
        delete [] tablero[i];
    }
    delete [] tablero;
}

void iniciarSemilla()
{
    srand(time(0));
}

void generarPieza(unsigned char *pieza,int &tipo )
{
    unsigned char piezas[5][4]={
    {0b00010000,0b00010000,0b00010000,0b00010000},
    {0b00011000,0b00011000,0b00000000,0b00000000},
    {0b00001100,0b00011000,0b00000000,0b00000000},
    {0b00010000,0b00010000,0b00011000,0b00000000},
    {0b00011100,0b00001000,0b00000000,0b00000000}};


    tipo=rand()%5;
    unsigned char *ptr=*(piezas+tipo);
    for(short int i=0;i<4;i++){
        *(pieza+i)=*(ptr+i);
    }
}

bool bitPieza(unsigned char *pieza, short int fila, short int col)
{
    unsigned char mascara = (unsigned char)(1<<(7-col));
    return (pieza[fila] &mascara)!=0;

}
bool bitTablero(unsigned char **tablero, short int fila, short int col)
{
    short int iByte=col / 8;
    short int iBit=col % 8;
    unsigned char mascara = (unsigned char)(1<<(7-iBit));
    return (tablero[fila][iByte] &mascara)!=0;    
}

void onBitTablero(unsigned char **tablero, int fila, int col)
{
    int indiceByte=col/8;
    int indiceBit=col%8;
    unsigned char mascara = (unsigned char)(1<<(7-indiceBit));
    tablero[fila][indiceByte]= (unsigned char)(tablero[fila][indiceByte]|mascara);

}

bool colision(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short int fila, short int columna)
{
    for (short int f=0;f<4;f++){
        for (short int c=0;c<8;c++){
            if (bitPieza(pieza,f,c)){
                short int filareal = fila+f;
                short int colreal=columna+c;
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
void fijarPieza(unsigned char **tablero, unsigned short alto, unsigned short ancho, unsigned char *pieza, int fila, int columna)
{
    for (int f=0;f<4;f++) {
        for(int c=0;c<8;c++){
            if (bitPieza(pieza,f,c)){
                int filaReal=fila+f;
                int colReal=columna+c;

                if (filaReal>=0 && filaReal<alto && colReal>=0 && colReal<ancho){
                    onBitTablero(tablero,filaReal,colReal);
                }
            }
        }
    }
}


void imprimirTablero(unsigned char **tablero, unsigned short alto, unsigned short ancho, unsigned char *pieza, short int filapieza, short int colpieza)
{
    cout<<endl;
    for (short int i = 0;i<alto; i++){
        cout << "<3";
        for(short int j=0; j<ancho;j++){
            bool ocupado=bitTablero(tablero,i,j);
            bool piezaactual=false;
            for (short int f=0;f<4;f++){
                for (short int c=0;c<8;c++){
                    if (bitPieza(pieza,f,c)){
                        if((filapieza+f==i)&& (colpieza + c == j )){
                            piezaactual=true;
                        }
                    }
                }
            }
            if (ocupado || piezaactual){
                cout<<"Ll";
            }
            else {
                cout<< " .";
            }
        }
        cout<<"<3"<<endl;
    }
    cout<< "<3";
    for (short int i = 0;i<ancho;i++){
        cout<<"__";
    }
    cout<<"<3"<<endl;
    cout<<"[A] IZQUIERDA [D] DERECHA [S] ABAJO [W] ROTAR [Q] SALIR"<<endl;
}

bool filallena(unsigned char *fila, unsigned short ancho)
{
    int anchoBytes = ancho/8;

    for (int i=0;i<anchoBytes;i++){
        if (fila[i] != 0xFF){
            return false;
        }
    }
    return true;
}


void limpiarfilas(unsigned char **tablero, unsigned short alto, unsigned short ancho)
{
    int anchoBytes=ancho/8;
    for (int i=alto-1; i>=0;i--){
        if (filallena(tablero[i],ancho)){
            delete[] tablero [i];

            for (int k=i;k>0;k--){
                tablero [k]= tablero[k-1];
            }
            tablero[0]=new unsigned char [anchoBytes];
            for (int j = 0; j < anchoBytes; j++) {
                tablero [0][j]=0;

            }
            i++;
        }

    }
}


bool moverIzq(unsigned char **tablero, unsigned short alto, unsigned short ancho, unsigned char *pieza, short int filapieza, short int &colpieza)
{
    if(!colision(tablero,alto,ancho,pieza,filapieza,colpieza-1)){
        colpieza--;
        return true;
    }
    return false;
}
bool moverDer(unsigned char **tablero, unsigned short alto, unsigned short int ancho, unsigned char *pieza, short int filapieza, short int &colpieza)
{
    if(!colision(tablero,alto,ancho,pieza,filapieza,colpieza+1)){
        colpieza++;
        return true;
    }
    return false;
}
void apagarPieza(unsigned char *pieza)
{
    for(short int i=0;i<4;i++){
        pieza[i]=0;
    }
}


void encenderBitpieza(unsigned char *pieza, short fila, short col)
{
    unsigned char mascara=(unsigned char)(1<<(7-col));
    *(pieza+fila)=(unsigned char)(*(pieza+fila)|mascara);
}


void rotar90(unsigned char *piezaOrg, unsigned char *piezaRot)
{
   apagarPieza(piezaRot);

    for(short int f=0;f<4;f++){
       for(short int c=0;c<4;c++){
            short int colByte=c+2;

           if(bitPieza(piezaOrg,f,colByte)){
                short int nuevafila=c;
               short int nuevacol=5-f;
                encenderBitpieza(piezaRot,nuevafila,nuevacol);
           }
       }
    }
}

bool intentarRot(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short filapieza, short colpieza)
{
    unsigned char piezarot[4];
    rotar90(pieza,piezarot);
    if(!colision(tablero,alto,ancho,piezarot,filapieza,colpieza)){
        for(short int i=0;i<4;i++){
            pieza[i]=piezarot[i];
        }
        return true;
    }
    return false;

}

bool bajar(unsigned char **tablero, unsigned short int alto, unsigned short ancho, unsigned char *pieza, int &tipo, short int &filapieza, short int &colpieza, bool &gameOver)
{
    if(!colision(tablero,alto,ancho,pieza,filapieza+1,colpieza)){
        filapieza++;
        return true;
    }

    fijarPieza(tablero,alto,ancho,pieza,filapieza,colpieza);
    limpiarfilas(tablero,alto,ancho);

    filapieza=0;
    colpieza=(ancho/2)-4;
    generarPieza(pieza,tipo);

    if (colision(tablero,alto,ancho,pieza,filapieza,colpieza)){
        gameOver=true;
    }

    return false;

}


void juego(unsigned char **tablero, unsigned short int alto, unsigned short int ancho)
{
    unsigned char pieza[4];
    int tipo = 0;
    short int fila = 0;
    short int col = (ancho/2)-4;
    bool gameOver = false;
    char accion;

    generarPieza(pieza,tipo);

    if (colision(tablero,alto,ancho,pieza,fila,col)) {
        gameOver = true;
    }
    while (!gameOver){
        imprimirTablero(tablero,alto,ancho,pieza,fila,col);
        cout<<"Presione la tecla (W,S,D,A) para la accion: ";
        cin >> accion;
        if(accion=='a'||accion=='A'){
            moverIzq(tablero,alto,ancho,pieza,fila,col);
        }
        else if (accion=='d'||accion=='D'){
            moverDer(tablero,alto,ancho,pieza,fila,col);

        }
        else if(accion=='w'||accion=='W'){
            intentarRot(tablero,alto,ancho,pieza,fila,col);
        }
        else if (accion=='s'||accion=='S'){
            bajar(tablero,alto,ancho,pieza,tipo,fila,col,gameOver);
        }

    }
    if(gameOver){
        cout<<"*****GAME OVER***** <3"<<endl;
    }
}































#include <iostream>
#include "Funciones.h"

using namespace std;

int main()
{
    unsigned short int ancho=0;
    unsigned short int alto=0;
    unsigned char **tablero;
    cout<<"Ingrese por favor el alto del tablero (Minimo 8): "<<endl;
    cin>>alto;
    cout<<"Ingrese por favor el ancho del tablero (multiplos de 8): "<<endl;
    cin>>ancho;
    if (!dimensionesValidas(alto,ancho)){
        cout<<"Dimensiones invalidas"<<endl;
        return 1;
    }
    tablero=crearTablero(alto,ancho);
    iniciarSemilla();

    juego(tablero,alto,ancho);
    liberarTablero(tablero,alto);

    return 0;
}

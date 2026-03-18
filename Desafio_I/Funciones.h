#ifndef FUNCIONES_H
#define FUNCIONES_H

bool dimensionesValidas(unsigned short int alto,unsigned short int ancho);
unsigned char **crearTablero(unsigned short int alto, unsigned short int ancho);
void liberarTablero(unsigned char **tablero, unsigned short int alto);
void generarPieza(unsigned char *pieza);
void juego(unsigned char **tablero, unsigned short alto, unsigned short ancho);
#endif // FUNCIONES_H

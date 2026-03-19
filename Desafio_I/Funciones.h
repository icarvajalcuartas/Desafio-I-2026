#ifndef FUNCIONES_H
#define FUNCIONES_H

bool dimensionesValidas(unsigned short int alto,unsigned short int ancho);
unsigned char **crearTablero(unsigned short int alto, unsigned short int ancho);
void liberarTablero(unsigned char **tablero, unsigned short int alto);
void generarPieza(unsigned char *pieza,unsigned short int &tipo);
void juego(unsigned char **tablero, unsigned short alto, unsigned short ancho);
void iniciarSemilla();
bool colision (unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, int fila, int columna);
bool bitPieza(unsigned char *pieza, int fila, int col);
bool bitTablero(unsigned char **tablero,int fila,int col);
void imprimirTablero(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, int filapieza, int colpieza);
#endif // FUNCIONES_H

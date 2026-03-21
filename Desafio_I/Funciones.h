#ifndef FUNCIONES_H
#define FUNCIONES_H

bool dimensionesValidas(unsigned short int alto,unsigned short int ancho);
unsigned char **crearTablero(unsigned short int alto, unsigned short int ancho);
void liberarTablero(unsigned char **tablero, unsigned short int alto);
void generarPieza(unsigned char *pieza,unsigned short int &tipo);
void juego(unsigned char **tablero, unsigned short alto, unsigned short ancho);
void iniciarSemilla();
bool colision (unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short int fila,short int columna);
bool bitPieza(unsigned char *pieza, short int fila, short int col);
bool bitTablero(unsigned char **tablero,short int fila,short int col);
void imprimirTablero(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short int filapieza, short int colpieza);
bool moverIzq(unsigned char **tablero,unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short int filapieza, short int &colpieza);
bool moverDer(unsigned char **tablero,unsigned short int alto,unsigned short int ancho,unsigned char *pieza,short int filapieza, short int &colpieza);
void apagarPieza (unsigned char *pieza);
void encenderBitpieza(unsigned char*pieza,short int fila,short int col);
void rotar90(unsigned char *piezaOrg, unsigned char *piezaRot);
bool intentarRot(unsigned char **tablero, unsigned short int alto, unsigned short int ancho, unsigned char *pieza, short int filapieza, short int colpieza);
#endif // FUNCIONES_H

#include <iostream>
#include <string>
#include <fstream>
#include "Funciones_Piezas.hpp"
using namespace std;

struct Pieza {
    char simbolo; // Define qué tipo de pieza es y su caracter
    int x, y;     // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
  int cantidad_piezas; // Cantidad de piezas del tablero
  Pieza *piezas_tablero; // Arreglo de todas las piezas
};

Tablero TableroAjedrez; //Tablero como variable global

/*****
 * bool TableroEnJaqueMate
 ******
 * Calcula si el Rey de Ton está en Jaque Mate, si lo está retorna True y si no False
 ******
 * Input:
 * Tablero tablero: Entrega el tablero con todas las piezas y la cantidad total de estas
 ******
 * Returns:
 * bool, El retorno dependerá de si el rey de Ton se en cuentra en Jaque Mate o no
 *****/
bool TableroEnJaqueMate(Tablero &tablero) {
    char* ArrayTablero = new char[64];
    int pos, e;
    PosMov *MovimientosRT, *MovimientosS, *MovimientosP, *MovimientosA, *MovimientosC, *MovimientosR, *MovimientosT;

    for (int i = 0; i < 64; i++) {
        ArrayTablero[i] = '.';
    }

    for (int i = 0; i < tablero.cantidad_piezas; i++) {
        pos = tablero.piezas_tablero[i].x + tablero.piezas_tablero[i].y * 8;
        if (tablero.piezas_tablero[i].simbolo != 'X') {
            ArrayTablero[pos] = '+';
        }
    }

    /*
    - Cuando se encuentra una pieza de Sebastían se le asigna un + en el tablero
    - Cuando una pieza atacante encuentra un + deja de tomar las posciones de ataque y la convierte en un # indicando que está protegida
    - Una posición de ataque se determina como *
    */

    for (int i = 0; i < tablero.cantidad_piezas; i++) {

        if (tablero.piezas_tablero[i].simbolo == 'K') {

            MovimientosS = ReyS(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y);
            for (e = 0; e < MovimientosS[0].CantidadMov; e++) {

                pos = MovimientosS[e].MovX + MovimientosS[e].MovY * 8;

                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }
            }

            delete[] MovimientosS;

        } else if (tablero.piezas_tablero[i].simbolo == 'P') {

            MovimientosP = Peon(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y);
            for (e = 0; e < MovimientosP[0].CantidadMov; e++) {

                pos = MovimientosP[e].MovX + MovimientosP[e].MovY * 8;

                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }
            }

            delete[] MovimientosP;

        } else if (tablero.piezas_tablero[i].simbolo == 'A') {

            MovimientosA = Alfil(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y, ArrayTablero);
            for (e = 0; e < MovimientosA[0].CantidadMov; e++) {

                pos = MovimientosA[e].MovX + MovimientosA[e].MovY * 8;

                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }              
            }

            delete[] MovimientosA;

        } else if (tablero.piezas_tablero[i].simbolo == 'T') {

            MovimientosT = Torre(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y, ArrayTablero);
            for (e = 0; e < MovimientosT[0].CantidadMov; e++) {

                pos = MovimientosT[e].MovX + MovimientosT[e].MovY * 8;

                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }

            }

            delete[] MovimientosT;

        } else if (tablero.piezas_tablero[i].simbolo == 'C') {

            MovimientosC = Caballo(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y);
            for (e = 0; e < MovimientosC[0].CantidadMov; e++) {

                pos = MovimientosC[e].MovX + MovimientosC[e].MovY * 8;
                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }
            }

            delete[] MovimientosC;

        } else if (tablero.piezas_tablero[i].simbolo == 'R') {

            MovimientosR = Reina(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y, ArrayTablero);
            for (e = 0; e < MovimientosR[0].CantidadMov; e++) {
                
                pos = MovimientosR[e].MovX + MovimientosR[e].MovY * 8;

                if (ArrayTablero[pos] == '+' or ArrayTablero[pos] == '#') {
                    ArrayTablero[pos] = '#';
                } else {
                    ArrayTablero[pos] = '*';
                }
            }

            delete[] MovimientosR;
        }
    }

    /*
    - El Rey de Ton convierte las posiciones que puede atacar a A, 
      si en estos lugares se encuentra una pieza protegida o un 
      lugar atacado por otra pieza esta posición no se asigna
    */

    for (int i = 0; i < tablero.cantidad_piezas; i++) {
        if (tablero.piezas_tablero[i].simbolo == 'X') {

            MovimientosRT = ReyT(tablero.piezas_tablero[i].x, tablero.piezas_tablero[i].y);
            for (e = 0; e < MovimientosRT[0].CantidadMov; e++) {

                pos = MovimientosRT[e].MovX + MovimientosRT[e].MovY * 8;
                if (ArrayTablero[pos] != '*' and ArrayTablero[pos] != '#') {
                    ArrayTablero[pos] = 'A';
                }
            }

            delete[] MovimientosRT;
        }
    }

    /*
    Si encuentra una A dentro del tablero se retorna el estado de false
    */
    for (int i = 0; i < 64; i++) {

        if (ArrayTablero[i] == 'A') {
            delete[] ArrayTablero;
            return false;
        }
    }

    delete[] ArrayTablero;
    return true;
}

/*****
 * Pieza AbrirArchivo
 ******
 * Abre el archivo y guarda la información de las Piezas disponibles y la cantidad de estas en TableroAjedrez
 ******
 * Input:
 * string Archivo: Nombre del archivo a abrir
 ******
 * Returns:
 * Pieza, retorna un arreglo de tipo Pieza con toda la información de las piezas disponibles
 *****/
Pieza *AbrirArchivo(string Archivo) {
    ifstream fp;
    char caracter;
    int PosX, PosY = -1, i = 0;

    fp.open(Archivo);

    if (!fp.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return NULL;
    }

    fp >> TableroAjedrez.cantidad_piezas;
    Pieza* Piezas = new Pieza[TableroAjedrez.cantidad_piezas];

    while ((caracter = fp.get()) != EOF) {
        if (caracter == '\n') {
            PosX = 0;
            ++PosY;
        } else if (caracter == '.') {
            ++PosX;
        } else {
            Piezas[i].simbolo = caracter;
            Piezas[i].x = PosX;
            Piezas[i].y = PosY;

            ++PosX;
            ++i;
        }
    }
    fp.close();
    return Piezas;
}

/*****
 * int main
 ******
 * Llama a las otras funciones y con la infomación recibida determina si está en Jaque o no, para luego imprimir el resultado
 ******
 * Input: No input
 ******
 * Returns:
 * int, retorna 0 en caso de que se haya ejecutado correctamente
 *****/
int main() {
    bool Jaque;

    TableroAjedrez.piezas_tablero = AbrirArchivo("tablero.txt");
    Jaque = TableroEnJaqueMate(TableroAjedrez);

    if (Jaque == false) {
        cout << "\nNo\n";
    } else if (Jaque == true) {
        cout << "\nSí\n";
    }

    delete[] TableroAjedrez.piezas_tablero;
    return 0;
}
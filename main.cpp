#include <iostream>
#include <string>
#include <fstream>
#include "TDA_SuperString.hpp"
using namespace std;

/*****
* void Insertar
******
* Mediante un recorrido del string entregado, va agregando los caracteres al super_string
******
* Input:
* super_string &super_string_principal: Super_string al que se le agregará la línea
* int pos_trabajo: Posición en la que se insertará la línea
* string linea: String que se insertará en el super_string
******
* Returns:
*****/
void Insertar(super_string &super_string_principal, int pos_trabajo, string linea) {
    super_string super_string_2;

    super_string_principal.separar(pos_trabajo, super_string_principal, super_string_2);
    for (size_t i = 0; i < linea.length(); i++) {
        super_string_principal.agregar(linea[i]);
    }

    super_string_principal.juntar(super_string_2);
}

/*****
* void Reverso
******
* Cambia el orden de los caracteres en el super_string invirtiendolo entre las posiciones pos_inicial y pos_final
******
* Input:
* super_string &super_string_principal: Super_string al que se le invertirá el orden de los caracteres
* int pos_inicial: Posición inicial de la inversión
* int pos_final: Posición final de la inversión
******
* Returns:
*****/
void Reverso(super_string &super_string_principal, int pos_inicial, int pos_final) {
    super_string super_string_2, super_string_3;
    super_string_principal.separar(pos_inicial, super_string_principal, super_string_2);
    super_string_2.separar(pos_final - pos_inicial + 1, super_string_2, super_string_3);
    super_string_2.reverso();
    super_string_principal.juntar(super_string_2);
    super_string_principal.juntar(super_string_3);
}

/*****
* void Eliminar
******
* Elimina los caracteres en el rango de las posiciones pos_inicial y pos_final
******
* Input:
* super_string &super_string_principal: Super_string al que se le eliminarán los caracteres
* int pos_inicial: Posición inicial de la eliminación
* int pos_final: Posición final de la eliminación
******
* Returns:
*****/
void Eliminar(super_string &super_string_principal, int pos_inicial, int pos_final) {
    super_string super_string_2, super_string_3;

    super_string_principal.separar(pos_inicial, super_string_principal, super_string_2);
    super_string_2.separar(pos_final - pos_inicial + 1, super_string_2, super_string_3);
    super_string_principal.juntar(super_string_3);
}

/*****
* int main
******
* Lee un archivo de texto con instrucciones, y a medida que las lee, realiza las operaciones correspondientes en un super_string
******
* Input:
******
* Returns:
* int:
*****/
int main() {
    ifstream fp;
    string linea, oracion;
    super_string super_string_principal;
    int pos_trabajo, pos_inicial, pos_final;
    fp.open("prueba.txt");

    if (!fp.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    fp >> linea;

    while (linea != "FIN") {
        if (linea == "INSERTAR") {
            fp >> pos_trabajo;
            fp >> linea;
            Insertar(super_string_principal, pos_trabajo, linea);
        } else if (linea == "MOSTRAR") {
            oracion = super_string_principal.stringizar();
            cout << oracion << endl;
        } else if (linea == "ELIMINAR") {
            fp >> pos_inicial;
            fp >> pos_final;
            Eliminar(super_string_principal, pos_inicial, pos_final);
        } else if (linea == "REVERSO") {
            fp >> pos_inicial;
            fp >> pos_final;
            Reverso(super_string_principal, pos_inicial, pos_final);
        }else if (linea == "RECORTAR") {
            cout << super_string_principal.recortar() << endl;
        }
        fp >> linea;
    }

    fp.close();
}
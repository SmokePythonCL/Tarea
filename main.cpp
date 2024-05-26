#include <iostream>
#include <string>
#include <fstream>
#include "funciones.hpp"
using namespace std;

int main() {
    ifstream fp;
    string linea, oracion;
    super_string super_string, super_string_2, super_string_3;
    int pos_trabajo, pos_inicial, pos_final;
    fp.open("Prueba_1.txt");

    if (!fp.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    fp >> linea;

    while (linea != "FIN") {
        if (linea == "INSERTAR") {
            fp >> pos_trabajo;
            fp >> linea;
            for (size_t i = 0; i < linea.length(); i++) {
                super_string.agregar(linea[i]);
            }
        } else if (linea == "MOSTRAR") {
            oracion = super_string.stringizar();
            cout << oracion << endl;
        } else if (linea == "ELIMINAR") {
            fp >> pos_inicial;
            fp >> pos_final;
            super_string.separar(pos_inicial, super_string, super_string_2);
            super_string_2.separar(pos_final - pos_inicial + 1, super_string_2, super_string_3);
            super_string.juntar(super_string_3);
            super_string_2.limpiar();
            super_string_3.limpiar();

        } /*else if (linea == "REVERSO") {
            fp >> pos_inicial;
            fp >> pos_final;
            cout << "[" << pos_inicial << "," << pos_final <<"]" << endl;
            //super_string.reverso();
        } else if (linea == "RECORTAR") {
            //super_string.recortar();
        }*/
        fp >> linea;
    }

    fp.close();
}

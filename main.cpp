#include <iostream>
#include <string>
#include <fstream>
#include "funciones.hpp"
using namespace std;

int main() {
    ifstream fp;
    string linea, oracion;
    super_string super_string;
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
            cout << "[" << pos_trabajo << "," << linea <<"]" << endl;
            //for (int i = 0; i < linea.size(); i++) {
                //super_string.agregar(linea[i]);
            //}
        } else if (linea == "MOSTRAR") {
            //oracion = super_string.stringizar();
            cout << oracion << endl;
        } else if (linea == "ELIMINAR") {
            fp >> pos_inicial;
            fp >> pos_final;
            cout << "[" << pos_inicial << "," << pos_final <<"]" << endl;
            //super_string.eliminar();
        } else if (linea == "REVERSO") {
            fp >> pos_inicial;
            fp >> pos_final;
            cout << "[" << pos_inicial << "," << pos_final <<"]" << endl;
            //super_string.reverso();
        } else if (linea == "RECORTAR") {
            //super_string.recortar();
        }
        fp >> linea;
    }

    fp.close();
}

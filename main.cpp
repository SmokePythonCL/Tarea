#include <iostream>
#include <string>
#include <fstream>
#include "TDA_SuperString.hpp"
using namespace std;

void insertar(super_string &super_string_principal, int pos_trabajo, string linea) {
    super_string super_string_2;

    super_string_principal.separar(pos_trabajo, super_string_principal, super_string_principal);
    for (size_t i = 0; i < linea.length(); i++) {
        super_string_principal.agregar(linea[i]);
    }

    super_string_principal.juntar(super_string_2);
}

void reverso(super_string &super_string_principal, int pos_inicial, int pos_final) {
    super_string super_string_2, super_string_3;
    super_string_principal.separar(pos_inicial, super_string_principal, super_string_2);
    super_string_2.separar(pos_final - pos_inicial + 1, super_string_2, super_string_3);
    super_string_2.reverso();
    super_string_principal.juntar(super_string_2);
    super_string_principal.juntar(super_string_3);
}

void eliminar(super_string &super_string_principal, int pos_inicial, int pos_final) {
    super_string super_string_2, super_string_3;

    super_string_principal.separar(pos_inicial, super_string_principal, super_string_2);
    super_string_2.separar(pos_final - pos_inicial + 1, super_string_2, super_string_3);
    super_string_principal.juntar(super_string_3);
}

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
            insertar(super_string_principal, pos_trabajo, linea);
        } else if (linea == "MOSTRAR") {
            oracion = super_string_principal.stringizar();
            cout << oracion << endl;
        } else if (linea == "ELIMINAR") {
            fp >> pos_inicial;
            fp >> pos_final;
            eliminar(super_string_principal, pos_inicial, pos_final);
        } else if (linea == "REVERSO") {
            fp >> pos_inicial;
            fp >> pos_final;
            reverso(super_string_principal, pos_inicial, pos_final);
        }else if (linea == "RECORTAR") {
            cout << super_string_principal.recortar() << endl;
        }
        fp >> linea;
    }

    fp.close();
}
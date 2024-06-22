#include <iostream>
#include <string>
#include <fstream>
#include "TDA_HASH.hpp"
using namespace std;

int main() {
    ifstream fp;
    string linea, rol, nombre, descripcion;
    registro_cuentas cuentas;
    cuenta actual;
    fp.open("prueba.txt");

    if (!fp.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    fp >> linea;

    while (!fp.eof()) {
        if (linea == "AGREGAR") {
            fp >> rol;
            fp >> nombre;
            fp >> descripcion;

            actual.rol = rol;
            actual.nombre = nombre;
            actual.descripcion = descripcion;
            cuentas.agregar(actual);
            
        } else if (linea == "QUITAR") {
            fp >> rol;

            cuentas.eliminar(rol);
        } else if (linea == "MODIFICAR") {
            fp >> rol;
            fp >> descripcion;

        } else if (linea == "OBTENER") {
            fp >> rol;
            cuenta actual = cuentas.obtener(rol);
            nombre = actual.nombre;
            descripcion = actual.descripcion;
            cout << nombre << " " << descripcion << endl;
        } else if (linea == "ESTADISTICAS") {
            cuentas.estadisticas();
        }
        fp >> linea;
        cout << linea << endl;
    }
    //cuentas.display();

    fp.close();
}
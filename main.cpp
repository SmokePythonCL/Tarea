#include <iostream>
#include <string>
#include <fstream>
#include "TDA_HASH.hpp"
using namespace std;

/*****
* int main
******
* Lee un archivo de texto con instrucciones, y a medida que las lee, realiza las operaciones correspondientes en un registro_cuentas
******
* Input:
******
* Returns:
* int
*****/
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

    do {
        fp >> linea;
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

            cuentas.modificar(rol, descripcion);
        } else if (linea == "OBTENER") {
            fp >> rol;

            cuenta actual = cuentas.obtener(rol);
            nombre = actual.nombre;
            descripcion = actual.descripcion;
            if (nombre != "") {
                cout << nombre << " " << descripcion << endl;
            }
        } else if (linea == "ESTADISTICAS") {
            cuentas.estadisticas();
        }
    } while (!fp.eof());
    //cuentas.display();

    fp.close();
}
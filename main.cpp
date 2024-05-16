#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#include "funciones.hpp"

int main() {
    ifstream fp;
    string line;
    fp.open("Prueba_1.txt");

    if (!fp.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    fp >> line;
    
    while (line != "FIN") {
        cout << line << endl;
        fp >> line;
    }
}


#include <string>
using namespace std;

struct cuenta {
    // El rol es el identificador de la persona.
    // El nombre y la descripcion son valores asociados al rol
    string rol, nombre, descripcion;
    bool ocupied;
    cuenta() : ocupied(false) {}
};

class registro_cuentas {
private:
    float factor_de_carga = 0.0;
    cuenta* tabla; // Aca se almacenaran los elementos de la tabla
    int ranuras = 15; // Cuantas ranuras tiene la tabla hash (inicialmente)
    int hash(string rol); // Se obtiene el hash dado el rol
    int p(string rol, int i); // Se obtiene la ranura a revisar en caso de colisión dado el rol y el intento i

    int num_ocupados;
public:
    registro_cuentas() {
        tabla=new cuenta[ranuras];
    } // (Recuerde que puede crear con distintos parametros)
    ~registro_cuentas();
    cuenta obtener(string rol); // Dado el rol, devuelve la cuenta con ese rol
    void agregar(cuenta c); // Se agrega una cuenta a la tabla
    void eliminar(string rol); // Se elimina la cuenta
    void modificar(string rol, string descripcion); // Se modifica la descripcion del rol
    void redimensionar(int n); // Se redimensiona la tabla a n espacios
    void estadisticas(); // Debe mostrar las estadísticas

    void display();
    float getLoadFactor();
};

int registro_cuentas::hash(string rol){
    int hashvalue=0;
    for(char ch: rol){
        hashvalue = (hashvalue*31 + ch) % ranuras;
    }
    //cout << "Hash value: " << hashvalue << endl;
    return hashvalue;
}

int registro_cuentas::p(string rol, int i) {
    int c1 = 1;
    int c2 = 3;
    return (hash(rol) + c1 * i + c2 * i * i) % ranuras;
}

float registro_cuentas::getLoadFactor() {
    factor_de_carga = static_cast<float>(num_ocupados) / ranuras;
    return factor_de_carga;
}

registro_cuentas::~registro_cuentas(){
    delete[] tabla;
}


cuenta registro_cuentas::obtener(string rol) {
    int value = hash(rol);

    while (tabla[value].rol != rol) {
        value = p(rol, value);        
    }

    if (tabla[value].rol == rol) {
        return tabla[value];
    } else {
        cout << "Rol no existe." << endl;
    }
    return cuenta();
}

void registro_cuentas::agregar(cuenta c){
    if(getLoadFactor() >= 0.75){
        redimensionar(2);
    }

    int i=0;
    int index;
    string key=c.rol;
    do{
        index=p(key,i);
        if(!tabla[index].ocupied){
            tabla[index].rol=key;
            tabla[index].nombre=c.nombre;
            tabla[index].descripcion=c.descripcion;
            tabla[index].ocupied=true;
            num_ocupados+=1;
            return;
        } else if (tabla[index].rol == key) {
            cout << "Rol ya existente" << endl;
            return;
        }
        i++;

    } while(i<ranuras);
    cout<<"lleno"<<endl;
}

void registro_cuentas::eliminar(string rol){
    int i=0;
    int index;
    do{
        index=p(rol,i);
        if(tabla[index].ocupied && tabla[index].rol ==rol){
            tabla[index].ocupied=false;
            num_ocupados -= 1;
            getLoadFactor();
            return;
        }
        i++;
    }while(i<ranuras);
    cout<<"key not found" << endl;
}

void registro_cuentas::modificar(string rol, string descripcion) {
    int value = hash(rol);

    while (tabla[value].rol != rol) {
        value = p(rol, value);        
    }

    if (tabla[value].rol == rol) {
        tabla[value].descripcion = descripcion;
    } else {
        cout << "Rol no existe." << endl;
    }
    return;
}

void registro_cuentas::redimensionar(int n) {
    int oldSize = ranuras;
    ranuras = ranuras * n;
    cuenta* oldTable = tabla;
    tabla = new cuenta[ranuras];
    num_ocupados = 0;
    
    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i].ocupied) {
            agregar(oldTable[i]);
        }
    }
    delete[] oldTable;
}

void registro_cuentas::estadisticas() {
    cout << "RANURAS OCUPADAS: " << num_ocupados << endl;
    cout << "RANURAS TOTALES: " << ranuras << endl;
    cout << "FACTOR DE CARGA: " << factor_de_carga << endl;
    return;
}

void registro_cuentas::display() {
    for (int i = 0; i < ranuras; i++) {
        if (tabla[i].ocupied) {
            cout << i << ": (" << tabla[i].rol << ", " << tabla[i].nombre << ")" << endl;
        } else {
            cout << i << ": (empty)" << endl;
        }
    }
}
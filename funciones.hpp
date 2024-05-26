#include <string>
using namespace std;

class super_string {
    private:
        struct nodo {
            nodo *left = nullptr, *right = nullptr;
            int index;
            char c;
            nodo(int index, char c) {}
            nodo(){}
        };
        int height = 0;       // Altura del árbol
        int length = 0;       // Largo del super-string
        nodo *root = nullptr; // Raíz del super-string
    public:
        super_string() {}
        ~super_string() {}
        void juntar(super_string &s);
        void agregar(char c); // Insertar un caracter en la última posición
        // En la izquierda esta el super_string a y en la derecha el super_string b
        void separar(int i, super_string &a, super_string &b);
        void reverso(); // No debe cambiar la altura del árbol
        int recortar(); // Retorna this->height después de recortar
        string stringizar(); // Debe ser O(n)
        void limpiar(); // Se deben borrar todos los nodos del super-string

        int largo();
};

void super_string::agregar(char letra) {
    if (root == nullptr) {
        root = new nodo();
        root->c = letra;
        root->index = 0;

        length++;
    } else {
        nodo *temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = new nodo();
        temp->right->c = letra;
        temp->right->index = length;

        length++;
    }
}

string super_string::stringizar() {
    string oracion;
    nodo *temp = root;
    while (temp != nullptr) {
        oracion += temp->c;
        temp = temp->right;
    }
    return oracion;
}

void super_string::separar(int i, super_string &a, super_string &b) {
    super_string temp;
    string oracion_temportal;
    for (int j = 0; j < i; j++) {
        temp.agregar(root->c);
        root = root->right;
    }

    if (i != length) {
        for (int k = i; k < length; k++) {
            b.agregar(root->c);
            root = root->right;
        }
    }
    a.limpiar();
    oracion_temportal = temp.stringizar();
    for (size_t i = 0; i < oracion_temportal.length(); i++) {
        a.agregar(oracion_temportal[i]);
    }
    temp.limpiar();
}

void super_string::limpiar() {
    if (root != nullptr) {
        nodo *temp = root;
        while (temp != nullptr) {
            nodo *temp2 = temp;
            temp = temp->right;
            delete temp2;
        }
        root = nullptr;
    }

    length = 0;
    height = 0;
}

void super_string::juntar(super_string &s) {
    if (s.root != nullptr) {
        if (length == 0) {
            root = new nodo();
            root->c = s.root->c;
            root->right = s.root->right;
            length += s.length;
            s.length = 0;
            s.root = nullptr;
        } else {
            nodo *temp = root;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = s.root;
            length += s.length;
            s.length = 0;
            s.root = nullptr;
        }
    }
}

void super_string::reverso() {
    //Arreglar
    string oracion_temporal, oracion;
    nodo *nodo_temp = root;
    while (nodo_temp->right != nullptr) {
        oracion += nodo_temp->c;
        nodo_temp = nodo_temp->right;
    }
    oracion += nodo_temp->c;
    
    for (size_t i = oracion.size(); i > 0 ; i--) {
        oracion_temporal += oracion[i];
    }

    oracion_temporal += oracion[0];

    if (root != nullptr) {
        nodo *nodo_temp = root;
        while (nodo_temp != nullptr) {
            nodo *nodo_temp2 = nodo_temp;
            nodo_temp = nodo_temp->right;
            delete nodo_temp2;
        }
        root = nullptr;
        length = 0;
        height = 0;
    }

    for (size_t i = 0; i < oracion_temporal.length(); i++) {
        if (root == nullptr) {
            root = new nodo();
            root->c = oracion_temporal[i];
            root->index = 0;

            length++;
        } else {
            nodo *temp = root;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = new nodo();
            temp->right->c = oracion_temporal[i];
            temp->right->index = length;

            length++;
        }
    }
}

int super_string::recortar() {

}


int super_string::largo() {
    return length;
}
#include <string>
using namespace std;

class super_string {
    private:
        struct nodo {
            nodo *left = nullptr, *right = nullptr;
            int index;
            char c;
            nodo(int index, char c) : index(index), c(c) {}
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

        void inOrderStringizar(nodo* node, string& oracion);
        void inOrderReverso(nodo* node, super_string& temp);
        void inOrderSeparar(nodo* node, super_string& a, super_string& b, int i);
        void inOrderTransversal(nodo* node, nodo** nodos, int& i);
        super_string::nodo* Balancear(nodo** nodos, int start, int end);
        int Altura(nodo* node);
};

/*****
* void super_string::agregar
******
* Agrega un nodo a la derecha del último nodo del super-string
******
* Input:
* char letra: Caracter a agregar
******
* Returns:
*****/
void super_string::agregar(char letra) {
    if (root == nullptr) {
        root = new nodo(0, letra);

        length++;
    } else {
        nodo *temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = new nodo(length, letra);

        length++;
    }
}

/*****
* string super_string::stringizar
******
* Con la ayuda de inOrderStringizar, retorna un string con todos los caracteres del super-string en recorrido de inOrder
******
* Input:
******
* Returns:
* string, string con todos los caracteres del super-string
*****/
string super_string::stringizar() {
    string oracion;
    inOrderStringizar(root, oracion);
    return oracion;
}

/*****
* void super_string::separar
******
* Separa el super-string en dos super-strings a y b, donde a tiene los primeros i caracteres y b el resto
******
* Input:
* int i: Cantidad de caracteres que tendrá a
* super_string &a: Super-string que será llenado con los primeros i caracteres
* super_string &b: Super-string que será llenado con el resto de caracteres
******
* Returns:
*****/
void super_string::separar(int i, super_string &a, super_string &b) {
    super_string temp;

    inOrderSeparar(a.root, temp, b, i);

    a.limpiar();
    if (temp.root != nullptr) {
        a.root = new nodo(0, temp.root->c);
        a.root->right = temp.root->right;
        a.length = temp.length;
    }
}

/*****
* void super_string::limpiar
******
* Elimina todos los nodos del super-string, generando un super-string vacío
******
* Input:
******
* Returns:
*****/
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

/*****
* void super_string::juntar
******
* Inserta el super-string s al final del super-string actual
******
* Input:
* super_string &s: Super-string que se insertará
******
* Returns:
*****/
void super_string::juntar(super_string &s) {
    if (s.root != nullptr) {
        if (length == 0) {
            root = new nodo(0, s.root->c);
            root->right = s.root->right;
            length = s.length;
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

/*****
* void super_string::reverso
******
* Función que con la ayuda de inOrderReverso invierte el super-string actual
******
* Input:
******
* Returns:
*****/
void super_string::reverso() {
    super_string temp;
    inOrderReverso(root, temp);
    limpiar();
    root = temp.root;
    length = temp.length;
}

/*****
* int super_string::recortar
******
* Ayuda a disminuir el tiempo de búsqueda de un nodo en el árbol desde uno O(n) a O(log n)
******
* Input:
******
* Returns:
* int, altura del árbol después de recortar
*****/
int super_string::recortar() {
    nodo** nodos = new nodo*[length];
    int i = 0;
    inOrderTransversal(root, nodos, i);
    root = Balancear(nodos, 0, length - 1);
    height = Altura(root);
    delete[] nodos;

    return height;
}

/*****
* void super_string::inOrderStringizar
******
* Realiza un recorrido inOrder del árbol y va concatenando los caracteres en un string
******
* Input:
* nodo* node: Nodo actual
* string& oracion: String que se va concatenando
******
* Returns:
*****/
void super_string::inOrderStringizar(nodo* node, string& oracion) {
    if (node != nullptr) {
        inOrderStringizar(node->left, oracion);
        oracion += node->c;
        inOrderStringizar(node->right, oracion);
    }
}

/*****
* void super_string::inOrderSeparar
******
* Realiza un recorrido inOrder del árbol y va separando los caracteres en dos super-strings a y b, donde a tiene los primeros i caracteres y b el resto.
******
* Input:
* nodo* node: Nodo actual
* super_string& a: Super-string que se va llenando con los primeros i caracteres
* super_string& b: Super-string que se va llenando con el resto de caracteres
* int i: Cantidad de caracteres que tendrá a
******
* Returns:
*****/
void super_string::inOrderSeparar(nodo* node, super_string& a, super_string& b, int i) {
    if (node != nullptr) {
        inOrderSeparar(node->left, a, b, i);
        if (node->index < i) {
            a.agregar(node->c);
        } else if (node->index >= i){
            b.agregar(node->c);
        }
        inOrderSeparar(node->right, a, b, i);
    }
}

/*****
* void super_string::inOrderReverso
******
* Realiza un recorrido inOrder de forma inversa (De derecha a izquierda) del árbol y va concatenando los caracteres en un super-string
******
* Input:
* nodo* node: Nodo actual
* super_string& temp: Super-string que se va llenando con los caracteres en orden inverso
******
* Returns:
*****/
void super_string::inOrderReverso(nodo* node, super_string& temp) {
    if (node != nullptr) {
        inOrderReverso(node->right, temp);
        temp.agregar(node->c);
        inOrderReverso(node->left, temp);
    }
}

/*****
* void super_string::inOrderTransversal
******
* Recolecta los nodos del árbol en un arreglo de nodos mediante un recorrido inOrder
******
* Input:
* nodo* node: Nodo actual
* nodo** nodos: Arreglo de nodos
* int& i: Índice del arreglo de nodos
******
* Returns:
*****/
void super_string::inOrderTransversal(nodo* node, nodo** nodos, int& i) {
    if (!node) return;

    inOrderTransversal(node->left, nodos, i);
    nodos[i++] = node;
    inOrderTransversal(node->right, nodos, i);
}

/*****
* super_string::nodo* super_string::Balancear
******
* Recorre el arbol desde la mitad y va agregando los nodos de tal forma que el arbol queda balanceado
******
* Input:
* nodo** nodos: Arreglo de nodos
* int inicio: Inicio del arreglo
* int fin: Fin del arreglo
******
* Returns:
* nodo*, Retorna un nodo con sus hijos balanceados
*****/
super_string::nodo* super_string::Balancear(nodo** nodos, int inicio, int fin) {
    if (inicio > fin) return nullptr;

    int centro = (inicio + fin) / 2;
    nodo* node = nodos[centro];

    node->left = Balancear(nodos, inicio, centro - 1);
    node->right = Balancear(nodos, centro + 1, fin);

    return node;
}

/*****
* int super_string::Altura
******
* Retorna la altura del árbol
******
* Input:
* nodo* node: Nodo actual
******
* Returns:
* int, Altura maxima de sus hijos más su propia altura (+1)
*****/
int super_string::Altura(nodo* node) {
    if (!node) return 0;
    return 1 + max(Altura(node->left), Altura(node->right));
}
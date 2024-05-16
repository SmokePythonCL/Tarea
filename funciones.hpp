class super_string {
    private:
        struct nodo {
            nodo *left = nullptr, *right = nullptr;
            int index;
            char c;
            nodo(int index, char c) {}
        };
        int height = 0;       // Altura del árbol
        int length = 0;       // Largo del super-string
        nodo *root = nullptr; // Raíz del super-string
    public:
        super_string() {}
        void juntar(super_string &s);
        void agregar(char c); // Insertar un caracter en la última posición
        // En la izquierda esta el super_string a y en la derecha el super_string b
        void separar(int i, super_string &a, super_string &b);
        void reverso(); // No debe cambiar la altura del árbol
        int recortar(); // Retorna this->height después de recortar
        string stringizar(); // Debe ser O(n)
        void limpiar(); // Se deben borrar todos los nodos del super-string
};

super_string::super_string() {
    root = new nodo(0, '$');
}

void super_string::juntar(super_string &s) {
    nodo *nuevo = new nodo(length, '$');
    nuevo->left = root;
    nuevo->right = s.root;
    root = nuevo;
    length += s.length;
    height = max(height, s.height) + 1;
}

void super_string::agregar(char c) {
    nodo *nuevo = new nodo(length, c);
    nuevo->left = root;
    root = nuevo;
    length++;
    height++;
}

void super_string::separar(int i, super_string &a, super_string &b) {
    nodo *nodo_i = root;
    while (nodo_i->left->index != i) {
        if (nodo_i->left->index > i) {
            nodo_i = nodo_i->left;
        } else {
            nodo_i = nodo_i->right;
            i -= nodo_i->left->index + 1;
        }
    }
    a.root = nodo_i->left;
    b.root = nodo_i->right;
    a.length = i;
    b.length = nodo_i->left->index - i;
    a.height = recortar();
    b.height = nodo_i->left->height;
}

void super_string::reverso() {
    stack<nodo*> pila;
    pila.push(root);
    while (!pila.empty()) {
        nodo *nodo_actual = pila.top();
        pila.pop();
        swap(nodo_actual->left, nodo_actual->right);
        if (nodo_actual->right != nullptr) {
            pila.push(nodo_actual->right);
        }
        if (nodo_actual->left != nullptr) {
            pila.push(nodo_actual->left);
        }
    }
}

int super_string::recortar() {
    if (root->left->height == height) {
        nodo *nuevo = root->left;
        root = root->left;
        delete nuevo;
        height--;
    }
    return height;
}

string super_string::stringizar() {
    string s;
    stack<nodo*> pila;
    pila.push(root);
    while (!pila.empty()) {
        nodo *nodo_actual = pila.top();
        pila.pop();
        if (nodo_actual->c != '$') {
            s += nodo_actual->c;
        }
        if (nodo_actual->right != nullptr) {
            pila.push(nodo_actual->right);
        }
        if (nodo_actual->left != nullptr) {
            pila.push(nodo_actual->left);
        }
    }
    return s;
}

void limpiar() {
    stack<nodo*> pila;
    pila.push(root);
    while (!pila.empty()) {
        nodo *nodo_actual = pila.top();
        pila.pop();
        if (nodo_actual->right != nullptr) {
            pila.push(nodo_actual->right);
        }
        if (nodo_actual->left != nullptr) {
            pila.push(nodo_actual->left);
        }
        delete nodo_actual;
    }
    root = nullptr;
    height = 0;
    length = 0;
}
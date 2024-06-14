struct PosMov {
    int CantidadMov, MovX, MovY; // Posibles movimientos para la piezas
};

/*****
* PosMov ReyT
******
* Calcula las posiciones de todas las casillas que puede atacar el Rey de Ton
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *ReyT(int PosX, int PosY) {
    PosMov *MovimientosRT = new PosMov[9];
    int X = PosX, Y = PosY, i = 0;

    // Ataque Izquierda Arriba
    X = PosX - 1, Y = PosY - 1;

    if (X >= 0 and Y >= 0) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Arriba
    X = PosX, Y = PosY - 1;

    if (Y >= 0) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Derecha Arriba
    X = PosX + 1, Y = PosY - 1;

    if (X <= 7 and Y >= 0) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Izquierda
    X = PosX - 1, Y = PosY;

    if (X >= 0) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Derecha
    X = PosX + 1, Y = PosY;

    if (X <= 7) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Izquierda Abajo
    X = PosX - 1, Y = PosY + 1;

    if (X >= 0 and Y <= 7) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Abajo
    X = PosX, Y = PosY + 1;

    if (Y <= 7) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    // Ataque Derecha Abajo
    X = PosX + 1, Y = PosY + 1;

    if (X <= 7 and Y <= 7) {
        MovimientosRT[i].MovX = X;
        MovimientosRT[i].MovY = Y;
        i++;
    }

    MovimientosRT[i].MovX = PosX;
    MovimientosRT[i].MovY = PosY;
    i++;

    MovimientosRT[0].CantidadMov = i;

    return MovimientosRT;
}

/*****
* PosMov ReyS
******
* Calcula las posiciones de todas las casillas que puede atacar el Rey de Sebastián
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *ReyS(int PosX, int PosY) {
    PosMov *MovimientosS = new PosMov[8];
    int X = PosX, Y = PosY, i = 0;

    // Ataque Izquierda Arriba
    X = PosX - 1, Y = PosY - 1;

    if (X >= 0 and Y >= 0) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Arriba
    X = PosX, Y = PosY - 1;

    if (Y >= 0) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Derecha Arriba
    X = PosX + 1, Y = PosY - 1;

    if (X <= 7 and Y >= 0) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Izquierda
    X = PosX - 1, Y = PosY;

    if (X >= 0) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }


    // Ataque Derecha
    X = PosX + 1, Y = PosY;

    if (X <= 7) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Izquierda Abajo
    X = PosX - 1, Y = PosY + 1;

    if (X >= 0 and Y <= 7) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Abajo
    X = PosX, Y = PosY + 1;

    if (Y <= 7) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    // Ataque Derecha Abajo
    X = PosX + 1, Y = PosY + 1;

    if (X <= 7 and Y <= 7) {
        MovimientosS[i].MovX = X;
        MovimientosS[i].MovY = Y;
        i++;
    }

    MovimientosS[0].CantidadMov = i;

    return MovimientosS;
}

/*****
* PosMov Peon
******
* Calcula las posiciones de todas las casillas que puede atacar el Peon
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *Peon(int PosX, int PosY) {
    PosMov *MovimientosP = new PosMov[2];
    int X = PosX, Y = PosY, i = 0;
    
    X = PosX - 1, Y = PosY - 1;

    // Ataque Izquierda
    if (X >= 0 and Y >= 0) {
        MovimientosP[i].MovX = X;
        MovimientosP[i].MovY = Y;
        i++;
    }

    X = PosX + 1, Y = PosY - 1;

    // Ataque Derecha
    if (X <= 7 and Y >= 0) {
        MovimientosP[i].MovX = X;
        MovimientosP[i].MovY = Y;
        i++;
    }

    MovimientosP[0].CantidadMov = i;

    return MovimientosP;
}

/*****
* PosMov Alfil
******
* Calcula las posiciones de todas las casillas que puede atacar el Alfil
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
* char ArrayTablero[]: Arreglo con las posiciones actuales de las piezas ya evaluadas
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *Alfil(int PosX, int PosY, char ArrayTablero[]) {
    PosMov *MovimientosA = new PosMov[13];
    int X = PosX, Y = PosY, i = 0, PosArr;
    

    //Ataque Diagonal Izquierda Superior
    while (X > 0 and Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosA[i].MovX = --X;
        MovimientosA[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Derecha Superior
    while (X < 7 and Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosA[i].MovX = ++X;
        MovimientosA[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Izquierda Inferior
    while (X > 0 and Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosA[i].MovX = --X;
        MovimientosA[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Derecha Inferior
    while (X < 7 and Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosA[i].MovX = ++X;
        MovimientosA[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    };

    MovimientosA[0].CantidadMov = i;

    return MovimientosA;
}

/*****
* PosMov Torre
******
* Calcula las posiciones de todas las casillas que puede atacar el Torre
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
* char ArrayTablero[]: Arreglo con las posiciones actuales de las piezas ya evaluadas
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *Torre(int PosX, int PosY, char ArrayTablero[]) {
    PosMov *MovimientosT = new PosMov[17];
    int X = PosX, Y = PosY, i = 0, PosArr;

    PosArr = X + (Y - 1)*8;

    //Ataque Superior
    while (Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    }

    X = PosX, Y = PosY - 1;

    if (Y > -1) {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = Y;
        i++;
    }

    X = PosX, Y = PosY;
    PosArr = X + (Y + 1)*8;
    
    //Ataque Inferior
    while (Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    }

    X = PosX, Y = PosY + 1;

    if (Y < 8) {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = Y;
        i++;
    }

    X = PosX - 1, Y = PosY;
    PosArr = (X - 1) + Y*8;

    //Ataque Izquierdo
    while (X > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosT[i].MovX = --X;
        MovimientosT[i].MovY = Y;
        PosArr = X + Y * 8;
        i++;
    }

    X = PosX - 1, Y = PosY;

    if (X > -1) {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = Y;
        i++;
    }

    X = PosX, Y = PosY;
    PosArr = (X + 1) + Y*8;

    //Ataque Derecho
    while (X < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosT[i].MovX = ++X;
        MovimientosT[i].MovY = Y;
        PosArr = X + Y * 8;
        i++;
    }

    X = PosX + 1, Y = PosY;

    if (X < 8) {
        MovimientosT[i].MovX = X;
        MovimientosT[i].MovY = Y;
        i++;
    }

    MovimientosT[0].CantidadMov = i;

    return MovimientosT;
}

/*****
* PosMov Caballo
******
* Calcula las posiciones de todas las casillas que puede atacar el Caballo
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *Caballo(int PosX, int PosY) {
    PosMov *MovimientosC = new PosMov[8];
    int X = PosX, Y = PosY, i = 0;

    // Ataque 1 Izquierda 2 Arriba
    X = PosX - 1, Y = PosY - 2;

    if (X >= 0 and Y >= 0) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 2 Izquierda 1 Arriba
    X = PosX - 2, Y = PosY - 1;

    if (X >= 0 and Y >= 0) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 2 Arriba 1 Derecha
    X = PosX + 1, Y = PosY - 2;

    if (X <= 7 and Y >= 0) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 1 Arriba 2 Derecha
    X = PosX + 2, Y = PosY - 1;

    if (X <= 7 and Y >= 0) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 1 Abajo 2 Izquierda
    X = PosX - 2, Y = PosY + 1;

    if (X >= 0 and Y <= 7) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 2 Abajo 1 Izquierda
    X = PosX - 1, Y = PosY + 2;

    if (X >= 0 and Y <= 7) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 1 Abajo 2 Derecha
    X = PosX + 2, Y = PosY + 1;

    if (X <= 7 and Y <= 7) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    // Ataque 2 Abajo 1 Derecha
    X = PosX + 1, Y = PosY + 2;

    if (X <= 7 and Y <= 7) {
        MovimientosC[i].MovX = X;
        MovimientosC[i].MovY = Y;
        i++;
    }

    MovimientosC[0].CantidadMov = i;    

    return MovimientosC;
}

/*****
* PosMov Reina
******
* Calcula las posiciones de todas las casillas que puede atacar el Reina
******
* Input:
* int PosX: Posición de la pieza en el eje X
* int PosY: Posición de la pieza en el eje Y
* char ArrayTablero[]: Arreglo con las posiciones actuales de las piezas ya evaluadas
******
* Returns:
* PosMov, Retorna un arreglo de todas las posiciones que puede atacar
*****/
PosMov *Reina(int PosX, int PosY, char ArrayTablero[]) {
    PosMov *MovimientosR = new PosMov[27];
    int X = PosX, Y = PosY, i = 0, PosArr;

    //Ataque Superior
    while (Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = X;
        MovimientosR[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    };


    X = PosX, Y = PosY;
    PosArr = -1;
    
    //Ataque Inferior
    while (Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = X;
        MovimientosR[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Izquierdo
    while (X > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = --X;
        MovimientosR[i].MovY = Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Derecho
    while (X < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = ++X;
        MovimientosR[i].MovY = Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Izquierda Superior
    while (X > 0 and Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = --X;
        MovimientosR[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Derecha Superior
    while (X < 7 and Y > 0 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = ++X;
        MovimientosR[i].MovY = --Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Izquierda Inferior
    while (X > 0 and Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = --X;
        MovimientosR[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    };

    X = PosX, Y = PosY;
    PosArr = -1;

    //Ataque Diagonal Derecha Inferior
    while (X < 7 and Y < 7 and ArrayTablero[PosArr] != '+' and ArrayTablero[PosArr] != '#') {
        MovimientosR[i].MovX = ++X;
        MovimientosR[i].MovY = ++Y;
        PosArr = X + Y * 8;
        i++;
    };

    MovimientosR[0].CantidadMov = i;

    return MovimientosR;
}
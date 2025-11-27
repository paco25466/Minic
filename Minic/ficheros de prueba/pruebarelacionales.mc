prueba() {
    var int x, y, z;
    const int max = 11;

    x = 10;
    y = 0;
    z = 1;

    print("Iniciando pruebas operadores relacionales\n");    // Prueba menor que
    if (x < max) {
        print("x es menor que max\n");
        while (z < 3) {
            print("z = "); 
            print(z);
            print("\n");
            z = z + 1;
        }
    }

    // Prueba mayor que
    if (x > y) {
        print("x es mayor que y\n");
        while (y < 3) {
            print("y = ");
            print(y);
            print("\n");
            y = y + 1;
        }
    }

    // Prueba igual 
    if (z == 3) {
        print("z es igual a 3\n");
    }

    // Prueba distinto
    if (y != 0) {
        print("y ya no es 0\n");
    }

    // Prueba menor o igual
    if (y <= 3) {
        print("y es menor o igual a 3\n");
    }

    // Prueba mayor o igual
    if (x >= 10) {
        print("x es mayor o igual a 10\n");
    }

    print("Fin de pruebas\n");
}
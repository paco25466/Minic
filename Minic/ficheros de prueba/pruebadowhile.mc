prueba() {
    var int contador;
    var int suma;
    const int limite = 5;
    
    print("Inicio del programa - Prueba do-while\n");
    
    contador = 1;
    suma = 0;
    
    do {
        suma = suma + contador;
        print("Contador = ");
        print(contador);
        print(", Suma acumulada = ");
        print(suma);
        print("\n");
        contador = contador + 1;
    } while (contador <= limite);
    
    print("Resultado final: ");
    print(suma);
    print("\n");
    print("Fin del programa\n");
}
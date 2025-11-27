prueba() {
    const int a=2, b=1;  
    var int c;
    
    print("=== Prueba  IF-ELSE-WHILE ===\n");
    print("Valores iniciales:\n");
    print("a = "); print(a); print("\n");
    print("b = "); print(b); print("\n");
    
    c = 5;
    print("c inicializado a: "); print(c); print("\n\n");

    // Estructura principal if-else con while
    print("-> Inicio estructura if-else\n");
    if (a > 3) {
        print("Caso 1: a > 3 (verdadero)\n");
        print("a = "); print(a); print(" es mayor que 3\n");
    } else {
        print("Caso 1: a > 3 (falso)\n");
        print("a = "); print(a); print(" no es mayor que 3\n\n");
        
        print("-> Segundo if anidado\n");
        if (b > 0) {
            print("Caso 2: b > 0 (verdadero)\n");
            print("b = "); print(b); print(" es mayor que 0\n");
        } else {
            print("Caso 2: b > 0 (falso)\n");
            print("b = "); print(b); print(" no es mayor que 0\n\n");
            
            print("-> Inicio bucle while\n");
            while (c > 2) {
                print("Iteración while: c = "); print(c); print("\n");
                print("Operación: c = "); print(c); print(" - 2 + 1 = "); 
                c = c-2+1;
                print(c); print("\n");
            }
            print("-> Fin bucle while (c <= 2)\n");
        }
    }
    
    print("\n=== RESULTADOS FINALES ===\n");
    print("a final: "); print(a); print("\n");
    print("b final: "); print(b); print("\n");
    print("c final: "); print(c); print("\n");
    print("=======================\n");
}
pruebaSem() {
    var int a;
    var int a;               // Error semántico: redeclaración de 'a'
    const int a=0,b=0;       // Error semántico: redeclaración de 'a' como constante
    a = 5+x;                 // Error semántico: 'x' no declarada
    b = 5;                   // Error semántico: asignación a constante 'b'
    c = 0;                   // Error semántico: 'c' no declarada
    read(a, b);              // Error semántico: 'b' es constante (no modificable)
    read(c);                 // Error semántico: 'c' no declarada
}
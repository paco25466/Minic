# Project Description — Minic 

Purpose
-------
Minic is a small, educational compiler project implemented in C. Its main goal is to demonstrate typical front-end compiler components: lexical analysis (lexer), syntactic analysis (parser), symbol table management, and a simple representation for intermediate code. It is intended for learning, experimentation, and as a base for further compiler-class projects.

High-level Architecture
-----------------------
- Lexer: defined by 'p1.l.l' and generates 'lex.yy.c' (Flex-style). The lexer recognizes tokens of the language (identifiers, literals, keywords, operators).
- Parser: grammar definition in 'lexico.y' (Bison/Yacc-style) compiles to `sintactico.tab.c` and `sintactico.tab.h`. The parser builds syntactic structures and drives semantic actions.
- Symbol Table: implemented in 'listaSimbolos.c' / 'listaSimbolos.h'. Tracks declared identifiers, scopes, and attributes needed for semantic checks.
- Intermediate Code: 'listaCodigo.c' / 'listaCodigo.h' implement a list or sequence of intermediate instructions or representations produced by semantic actions.
- Driver / Entry: 'main.c' initializes components, invokes the parser, and coordinates output or error reporting.

Key Files
---------
- 'p1.l.l' — lexer source (Flex). Modify when changing tokenization rules.
- 'lexico.y' — parser grammar (Bison/Yacc). Modify when changing syntax/grammar.
- 'listaSimbolos.*' — symbol table implementation and interface.
- 'listaCodigo.*' — intermediate code representation and utilities.
- 'main.c' — program entry point; orchestrates parsing and output.
- 'makefile' — build rules for compiling sources and linking the executable.

Build & Development Notes
-------------------------
- The project uses traditional C build tools. Use 'make' to build the project.
- To regenerate parser/lexer sources after editing 'lexico.y' or 'p1.l.l', run Bison and Flex (or your equivalents) before running 'make'.


Testing and Example Inputs
--------------------------
Example `.mc` test files are included in `ficheros de prueba/`. These exercise control flow (if/else, while/do-while), relational operators, and error handling.





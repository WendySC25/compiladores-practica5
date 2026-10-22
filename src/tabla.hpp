#pragma once

#include <string>
#include <vector>

enum TipoAccion { 
    ERR, 
    SHIFT,
    REDUCE,
    ACCEPT
};

struct Accion { 
    TipoAccion tipo;
    int n;
};

#define E   {ERR, 0}
#define S(j) {SHIFT, j}
#define R(k) {REDUCE, k}
#define ACC {ACCEPT, 0}

enum Terminal {
    INT, 
    BOOL,
    IF,
    ELSE,
    TRUE,
    FALSE,
    AND,
    OR,
    NOT,
    ID,
    INT_LITERAL,
    COLON,
    SEMI,
    LT,
    EQ,
    LPAR,
    RPAR,
    LBRACE,
    RBRACE,
    END
};

const int NUM_TERMINALES = 20;
const char* const NOMBRES_TERMINALES[NUM_TERMINALES] = {
    "INT",
    "BOOL",
    "IF",
    "ELSE",
    "TRUE",
    "FALSE",
    "AND",
    "OR",
    "NOT",
    "ID",
    "INT_LITERAL",
    ":",
    ";",
    "<",
    "=",
    "(",
    ")",
    "{",
    "}",
    "$"
};

const int NUM_NO_TERMINALES = 10;
enum NoTerminal {
    NT_Program_AUM,
    NT_Program,
    NT_StatementList,
    NT_Statement,
    NT_Block,
    NT_Type,
    NT_Expression,
    NT_Conjunction,
    NT_Comparison,
    NT_Value,
};

const char* const NOMBRES_NO_TERMINALES[NUM_NO_TERMINALES] = {
    "Program'",
    "Program",
    "StatementList",
    "Statement",
    "Block",
    "Type",
    "Expression",
    "Conjunction",
    "Comparison",
    "Value",
};

struct Produccion { 
    NoTerminal izquierda;
    int longitud;
    const std::string produccion;
};


const int NUM_PRODUCCIONES = 24;
const Produccion PRODUCCIONES[NUM_PRODUCCIONES] = {
};

const int NUM_ESTADOS;

//           INT BOOL IF ELSE TRUE FALSE AND OR NOT ID INT_LITERAL : ; < = ( ) { } $
const Accion ACCION[NUM_ESTADOS][NUM_TERMINALES] = {
};

//        Program' Program StatementList Statement Block Type Expression Conjunction Comparison Value
const int IR_A[NUM_ESTADOS][NUM_NO_TERMINALES] = {
};

#undef E
#undef S
#undef R
#undef ACC

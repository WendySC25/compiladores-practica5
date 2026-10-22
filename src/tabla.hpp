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

const int NUM_ESTADOS = 46;
const int NUM_PRODUCCIONES = 24;

const Produccion PRODUCCIONES[NUM_PRODUCCIONES] = {
    /*  0 */ {NT_Program_AUM, 1, "Program' -> Program"},
    /*  1 */ {NT_Program, 1, "Program -> StatementList"},
    /*  2 */ {NT_StatementList, 2, "StatementList -> StatementList Statement"},
    /*  3 */ {NT_StatementList, 1, "StatementList -> Statement"},
    /*  4 */ {NT_Statement, 5, "Statement -> Type ID : Expression ;"},
    /*  5 */ {NT_Statement, 4, "Statement -> ID : Expression ;"},
    /*  6 */ {NT_Statement, 5, "Statement -> IF ( Expression ) Block"},
    /*  7 */ {NT_Statement, 7, "Statement -> IF ( Expression ) Block ELSE Block"},
    /*  8 */ {NT_Block, 3, "Block -> { StatementList }"},
    /*  9 */ {NT_Type, 1, "Type -> INT"},
    /* 10 */ {NT_Type, 1, "Type -> BOOL"},
    /* 11 */ {NT_Expression, 3, "Expression -> Expression OR Conjunction"},
    /* 12 */ {NT_Expression, 1, "Expression -> Conjunction"},
    /* 13 */ {NT_Conjunction, 3, "Conjunction -> Conjunction AND Comparison"},
    /* 14 */ {NT_Conjunction, 1, "Conjunction -> Comparison"},
    /* 15 */ {NT_Comparison, 3, "Comparison -> Value < Value"},
    /* 16 */ {NT_Comparison, 3, "Comparison -> Value = Value"},
    /* 17 */ {NT_Comparison, 1, "Comparison -> Value"},
    /* 18 */ {NT_Value, 3, "Value -> ( Expression )"},
    /* 19 */ {NT_Value, 2, "Value -> NOT Value"},
    /* 20 */ {NT_Value, 1, "Value -> ID"},
    /* 21 */ {NT_Value, 1, "Value -> INT_LITERAL"},
    /* 22 */ {NT_Value, 1, "Value -> TRUE"},
    /* 23 */ {NT_Value, 1, "Value -> FALSE"},
};



// Columnas: INT BOOL IF ELSE TRUE FALSE AND OR NOT ID INT_LITERAL : ; < = ( ) { } $
const Accion ACCION[NUM_ESTADOS][NUM_TERMINALES] = {
    /*  0 */ {S(7), S(8), S(6), E, E, E, E, E, E, S(5), E, E, E, E, E, E, E, E, E, E},
    /*  1 */ {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, ACC},
    /*  2 */ {S(7), S(8), S(6), E, E, E, E, E, E, S(5), E, E, E, E, E, E, E, E, E, R(1)},
    /*  3 */ {R(3), R(3), R(3), E, E, E, E, E, E, R(3), E, E, E, E, E, E, E, E, R(3), R(3)},
    /*  4 */ {E, E, E, E, E, E, E, E, E, S(10), E, E, E, E, E, E, E, E, E, E},
    /*  5 */ {E, E, E, E, E, E, E, E, E, E, E, S(11), E, E, E, E, E, E, E, E},
    /*  6 */ {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S(12), E, E, E, E},
    /*  7 */ {E, E, E, E, E, E, E, E, E, R(9), E, E, E, E, E, E, E, E, E, E},
    /*  8 */ {E, E, E, E, E, E, E, E, E, R(10), E, E, E, E, E, E, E, E, E, E},
    /*  9 */ {R(2), R(2), R(2), E, E, E, E, E, E, R(2), E, E, E, E, E, E, E, E, R(2), R(2)},
    /* 10 */ {E, E, E, E, E, E, E, E, E, E, E, S(13), E, E, E, E, E, E, E, E},
    /* 11 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 12 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 13 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 14 */ {E, E, E, E, E, E, E, S(27), E, E, E, E, S(26), E, E, E, E, E, E, E},
    /* 15 */ {E, E, E, E, E, E, S(28), R(12), E, E, E, E, R(12), E, E, E, R(12), E, E, E},
    /* 16 */ {E, E, E, E, E, E, R(14), R(14), E, E, E, E, R(14), E, E, E, R(14), E, E, E},
    /* 17 */ {E, E, E, E, E, E, R(17), R(17), E, E, E, E, R(17), S(29), S(30), E, R(17), E, E, E},
    /* 18 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 19 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 20 */ {E, E, E, E, E, E, R(20), R(20), E, E, E, E, R(20), R(20), R(20), E, R(20), E, E, E},
    /* 21 */ {E, E, E, E, E, E, R(21), R(21), E, E, E, E, R(21), R(21), R(21), E, R(21), E, E, E},
    /* 22 */ {E, E, E, E, E, E, R(22), R(22), E, E, E, E, R(22), R(22), R(22), E, R(22), E, E, E},
    /* 23 */ {E, E, E, E, E, E, R(23), R(23), E, E, E, E, R(23), R(23), R(23), E, R(23), E, E, E},
    /* 24 */ {E, E, E, E, E, E, E, S(27), E, E, E, E, E, E, E, E, S(33), E, E, E},
    /* 25 */ {E, E, E, E, E, E, E, S(27), E, E, E, E, S(34), E, E, E, E, E, E, E},
    /* 26 */ {R(5), R(5), R(5), E, E, E, E, E, E, R(5), E, E, E, E, E, E, E, E, R(5), R(5)},
    /* 27 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 28 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 29 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 30 */ {E, E, E, E, S(22), S(23), E, E, S(19), S(20), S(21), E, E, E, E, S(18), E, E, E, E},
    /* 31 */ {E, E, E, E, E, E, E, S(27), E, E, E, E, E, E, E, E, S(39), E, E, E},
    /* 32 */ {E, E, E, E, E, E, R(19), R(19), E, E, E, E, R(19), R(19), R(19), E, R(19), E, E, E},
    /* 33 */ {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S(41), E, E},
    /* 34 */ {R(4), R(4), R(4), E, E, E, E, E, E, R(4), E, E, E, E, E, E, E, E, R(4), R(4)},
    /* 35 */ {E, E, E, E, E, E, S(28), R(11), E, E, E, E, R(11), E, E, E, R(11), E, E, E},
    /* 36 */ {E, E, E, E, E, E, R(13), R(13), E, E, E, E, R(13), E, E, E, R(13), E, E, E},
    /* 37 */ {E, E, E, E, E, E, R(15), R(15), E, E, E, E, R(15), E, E, E, R(15), E, E, E},
    /* 38 */ {E, E, E, E, E, E, R(16), R(16), E, E, E, E, R(16), E, E, E, R(16), E, E, E},
    /* 39 */ {E, E, E, E, E, E, R(18), R(18), E, E, E, E, R(18), R(18), R(18), E, R(18), E, E, E},
    /* 40 */ {R(6), R(6), R(6), S(42), E, E, E, E, E, R(6), E, E, E, E, E, E, E, E, R(6), R(6)},
    /* 41 */ {S(7), S(8), S(6), E, E, E, E, E, E, S(5), E, E, E, E, E, E, E, E, E, E},
    /* 42 */ {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, S(41), E, E},
    /* 43 */ {S(7), S(8), S(6), E, E, E, E, E, E, S(5), E, E, E, E, E, E, E, E, S(45), E},
    /* 44 */ {R(7), R(7), R(7), E, E, E, E, E, E, R(7), E, E, E, E, E, E, E, E, R(7), R(7)},
    /* 45 */ {R(8), R(8), R(8), R(8), E, E, E, E, E, R(8), E, E, E, E, E, E, E, E, R(8), R(8)},
};

// Columnas: Program' Program StatementList Statement Block Type Expression Conjunction Comparison Value
const int IR_A[NUM_ESTADOS][NUM_NO_TERMINALES] = {
    /*  0 */ {-1, 1, 2, 3, -1, 4, -1, -1, -1, -1},
    /*  1 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  2 */ {-1, -1, -1, 9, -1, 4, -1, -1, -1, -1},
    /*  3 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  4 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  5 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  6 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  7 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  8 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /*  9 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 10 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 11 */ {-1, -1, -1, -1, -1, -1, 14, 15, 16, 17},
    /* 12 */ {-1, -1, -1, -1, -1, -1, 24, 15, 16, 17},
    /* 13 */ {-1, -1, -1, -1, -1, -1, 25, 15, 16, 17},
    /* 14 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 15 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 16 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 17 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 18 */ {-1, -1, -1, -1, -1, -1, 31, 15, 16, 17},
    /* 19 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, 32},
    /* 20 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 21 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 22 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 23 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 24 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 25 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 26 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 27 */ {-1, -1, -1, -1, -1, -1, -1, 35, 16, 17},
    /* 28 */ {-1, -1, -1, -1, -1, -1, -1, -1, 36, 17},
    /* 29 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, 37},
    /* 30 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, 38},
    /* 31 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 32 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 33 */ {-1, -1, -1, -1, 40, -1, -1, -1, -1, -1},
    /* 34 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 35 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 36 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 37 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 38 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 39 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 40 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 41 */ {-1, -1, 43, 3, -1, 4, -1, -1, -1, -1},
    /* 42 */ {-1, -1, -1, -1, 44, -1, -1, -1, -1, -1},
    /* 43 */ {-1, -1, -1, 9, -1, 4, -1, -1, -1, -1},
    /* 44 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    /* 45 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
};

#undef E
#undef S
#undef R
#undef ACC
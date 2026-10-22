
#pragma once

#include <string>

struct Prueba { 
    const std::string tokens; 
    bool resultado; 
};

// Gente, estas son las que estaban anotadas en el latex
static const Prueba PRUEBAS[] = {
    {"INT ID : INT_LITERAL ;", true},
    {"ID : ID OR TRUE AND NOT FALSE ;", true},
    {"BOOL ID : ID < INT_LITERAL ; ID : ( ID = ID ) ;", true},
    {"IF ( ID < INT_LITERAL ) { ID : INT_LITERAL ; }", true},
    {"IF ( ID ) { ID : TRUE ; } ELSE { IF ( NOT ID ) { ID : FALSE ; } }", true},
    {"ID : ( ( ID OR FALSE ) AND NOT ID ) = TRUE ;", true},
    {"INT ID : INT_LITERAL", false},
    {"ID : ID < ID < ID ;", false},
    {"IF ( ID ) { }", false},
    {"ELSE { ID : TRUE ; }", false},
    {"INT : INT_LITERAL ;", false},
    {"ID : ( ID OR TRUE ;", false},
};
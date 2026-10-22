#pragma once

#include <string>
#include "Nodo.hpp"

struct Resultado {
    bool aceptada = false;
    std::string error;
    NodoP raiz;
};

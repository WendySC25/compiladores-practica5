#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

struct Nodo {
    std::string etiqueta;
    std::vector<std::shared_ptr<Nodo> > hijos;
};

using NodoP = std::shared_ptr<Nodo>;

void imprimirAST(const NodoP& n, int nivel, std::ostream& os);

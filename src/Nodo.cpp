#include "Nodo.hpp"

void imprimirAST(const NodoP& n, int nivel, std::ostream& os) {
    os << std::string(nivel * 2, ' ') << n->etiqueta << "\n";
    for (auto h : n->hijos) 
        imprimirAST(h, nivel + 1, os);
}

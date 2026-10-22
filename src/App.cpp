#include "App.hpp"

#include <iostream>
#include <vector>

bool App::run(const std::string& texto) const {

    std::vector<int> ids;
    std::vector<std::string> lex;
    std::string err;

    if (!tokenizer.tokenizar(texto, ids, lex, err)) {
        std::cout << "RECHAZADA: " << err << "\n";
        return false;
    }

    Resultado r = parser.parsear(ids, lex);
    
    if (r.aceptada) {
        std::cout << "ACEPTADA\n";
        std::cout << "AST:\n";
        imprimirAST(r.raiz, 1, std::cout);
        return true;
    } else 
        std::cout << "RECHAZADA\n  " << r.error << "\n";

    return false;
}

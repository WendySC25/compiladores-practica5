#include "Tokenizer.hpp"

#include <sstream>
#include "tabla.hpp"

Tokenizer::Tokenizer() {
    for (int i = 0; i < NUM_TERMINALES; ++i) 
        mapa[NOMBRES_TERMINALES[i]] = i;
}

bool Tokenizer::tokenizar(const std::string& texto, std::vector<int>& ids, std::vector<std::string>& lex, std::string& err) const {

    std::istringstream in(texto);
    std::string w;

    ids.clear();
    lex.clear();

    while (in >> w) {                    
        auto it = mapa.find(w);
        if (it == mapa.end()) { 
            err = "Token raro: " + w + ""; 
            return false;
        }
        ids.push_back(it->second);
        lex.push_back(w);
    }
    ids.push_back(END);
    lex.push_back("$");

    return true;
}

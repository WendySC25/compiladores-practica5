#pragma once

#include <map>
#include <string>
#include <vector>

class Tokenizer {
    private:
        std::map<std::string, int> mapa;  

    public:
        Tokenizer();
        bool tokenizar(const std::string& texto, std::vector<int>& ids, std::vector<std::string>& lex, std::string& err) const;
};

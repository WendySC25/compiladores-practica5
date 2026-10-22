#pragma once

#include <string>
#include "LRParser.hpp"
#include "Tokenizer.hpp"

class App {
    public:
        bool run(const std::string& texto) const;

    private:
        Tokenizer tokenizer;
        LRParser parser;
};

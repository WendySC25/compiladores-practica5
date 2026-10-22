#pragma once

#include <string>
#include <vector>

#include "Resultado.hpp"

class LRParser {

    public:
        Resultado parsear(const std::vector<int>& entrada, const std::vector<std::string>& lexemas) const;
};

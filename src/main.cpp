#include <iostream>

#include "App.hpp"
#include "Prueba.hpp"

int main() {
    
    int ok = 0;
    int NUM_PRUEBAS = 12;

    App app;
    for (int i = 0; i < NUM_PRUEBAS; i++) {

        std::cout << "Prueba " << (i + 1) << ": " << PRUEBAS[i].tokens << "\n";
        bool r = app.run(PRUEBAS[i].tokens);
        std::cout << (r == PRUEBAS[i].resultado ? "ACC" : "WA") << "\n";
        ok += (r == PRUEBAS[i].resultado);
    }

    std::cout << "Resultados: " << ok << "/" << NUM_PRUEBAS;

    return 0;
}

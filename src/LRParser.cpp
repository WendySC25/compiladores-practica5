#include "LRParser.hpp"

#include <sstream>
#include <stack>
#include <memory>
#include "tabla.hpp"

Resultado LRParser::parsear(const std::vector<int>& entrada, const std::vector<std::string>& lexemas) const {

    Resultado res;
    
    std::stack<int> pilaEstados;
    pilaEstados.push(0);
    std::stack<NodoP> pilaNodos;

    int pos = 0;

    while (true) {

        int s = pilaEstados.top();
        int a = entrada[pos];

        Accion ac = ACCION[s][a];

        switch (ac.tipo) {

            case SHIFT: {
                auto hoja = std::make_shared<Nodo>();
                hoja->etiqueta = lexemas[pos];
                pilaEstados.push(ac.n);
                pilaNodos.push(hoja);
                pos++;
                break;
            }

            case REDUCE: {
                const Produccion& p = PRODUCCIONES[ac.n];
                auto nodo = std::make_shared<Nodo>();
                nodo->etiqueta = std::string(NOMBRES_NO_TERMINALES[p.izquierda]);
                
                nodo->hijos.resize(p.longitud);

                for (int i = p.longitud - 1; i >= 0; --i) {
                    nodo->hijos[i] = pilaNodos.top();
                    pilaNodos.pop();
                    pilaEstados.pop();
                }

                int destino = IR_A[pilaEstados.top()][p.izquierda];
                pilaEstados.push(destino);
                pilaNodos.push(nodo);
                break;
            }

            case ACCEPT: {
                res.aceptada = true;
                res.raiz = pilaNodos.top();
                return res;
            }

            case ERR:

            default:
                res.error = "Errror : token '" + lexemas[pos] + "' no hay transción en el estado " + std::to_string(s);
                return res;
        }
    }
}

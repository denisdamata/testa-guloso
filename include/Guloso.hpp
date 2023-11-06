// include/Guloso.hpp

#ifndef GULOSO_HPP
#define GULOSO_HPP

#include "Grafo.hpp"  // Certifique-se de incluir o arquivo correto para o seu grafo

class Guloso {
public:
    static bool testeGulosidade(const Grafo& grafo, const std::vector<int>& permutacao, const std::vector<int>& cores);
};

#endif // GULOSO_HPP

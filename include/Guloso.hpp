// include/Guloso.hpp

#ifndef GULOSO_HPP
#define GULOSO_HPP

class Grafo;  // Certifique-se de incluir o arquivo correto para o seu grafo

class Guloso {
public:
    static bool testeGulosidade(const Grafo& grafo, const int* arranjoCores, const int* cores);
};

#endif // GULOSO_HPP

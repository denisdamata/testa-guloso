// include/Grafo.hpp

// Interface da classe que defini um grafo. É o extremo inferior do programa, então se for ler o código de baixo para cima, o leitor deve começar por aqui. 

#ifndef GRAFO_HPP //Evita inclusão repetida. Existe o "#pragma once", mas "#ifndef #define #endif" é aceito por qualquer compilador C ou C++. ChatGPT.  
#define GRAFO_HPP

class Grafo { //Existe uma cultura de iniciar o nome das classes com letra maiúscula e os membros das classes com letra minúscula, não só em C++, mas também em outras linguagens OO. 
public: //"public" são os membros que podem ser acessados externamente. 
    Grafo(int numVertices); //Protótipo/declaração do membro construtor, que será definido em "Grafo.cpp". ChatGPT.
    void adicionarAresta(int u, int v);
    const int* obterVizinhos(int vertice) const;

private:
    int numVertices;
    int* listaAdjacencia;
};

#endif // GRAFO_HPP

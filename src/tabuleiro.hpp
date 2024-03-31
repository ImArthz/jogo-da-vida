#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP 

#include "FileManager.hpp"
#include <iostream>

using namespace std;

class Tabuleiro
{
private:
public:
    Tabuleiro();

    void show(int **tabuleiro, int tamanho = 5);
    void relatorio(int **tabuleiro, int tamanho = 5,  FileManager *arquivo= nullptr, string mensagem ="", bool transferir = false);

    void begin(int **tabuleiro, int interacao, FileManager *arquivo= nullptr);

};

#endif
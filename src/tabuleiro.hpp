#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
using namespace std;
class Tabuleiro {
    public :
    tabuleiro();
    tabuleiro(short int tamanho);
    void gerador_matriz(short int tamanho);
    void guardar_relatorio(int geracao,short int matriz_atual);
    void calcular_proxima_geracao(int n_geracoes);
    short int getTam();
    void setTam(short int tamanho);
    private :
    short int tamanho ;

};
#endif
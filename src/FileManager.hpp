#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class FileManager
  {
  private:
    string arq_entrada;
    string arq_saida;
    int tamanho;
  public:
    FileManager();
    int getTamanho() const;
    void setTamanho(int tamanho = 5);
    void setEntrada(string arq_entrada);
    void setsaida(string arq_saida);
    int **entrada();
    void saida(int **tabuleiro);
    int **generate();
};
#endif

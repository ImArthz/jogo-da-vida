
#include "tabuleiro.hpp"
#include "FileManager.hpp"

#define Arquivo_entrada "datasets/input.mps"
#define Arquivo_saida "src/geracoes.mps"

int main(){
  FileManager *arquivo = new FileManager();
  Tabuleiro *jogo= new Tabuleiro();

    int Interation_count;

    arquivo->setEntrada(Arquivo_entrada);
    arquivo->setsaida(Arquivo_saida);

    int **tabuleiro = arquivo->entrada();

    cout<<"============================================"<<endl;
    cout<<"Digite o numero de interações : "<<endl;
    cout<<"============================================"<<endl;
    cout<<"->";
    cin>>Interation_count;

    jogo->begin(tabuleiro, Interation_count, arquivo);

    delete arquivo;
    delete jogo;
    return 0;
}
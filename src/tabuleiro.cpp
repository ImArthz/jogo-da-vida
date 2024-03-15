#include "tabuleiro.hpp"
#include <iostream>
#include <fstream> // Para trabalhar com arquivos
#include <cstdlib> // Para a função rand()
#include <ctime>   // Para a função time()
using namespace std;
Tabuleiro::Tabuleiro(short int tamanho ):tamanho(tamanho){}
Tabuleiro::Tabuleiro();
short int Tabuleiro::getTam()
{
    return tamanho;
}
void Tabuleiro::setTam(short int tamanho)
{
    this->tamanho=tamanho;
}
void Tabuleiro::gerador_matriz(short int tamanho)
{
    int matriz[tamanho][tamanho];

    // Inicializa a semente para gerar números aleatórios
    std::srand(std::time(nullptr));

    // Preenche a matriz com valores aleatórios de 0 ou 1
    for (short int i = 0; i < tamanho; ++i) {
        for (short int j = 0; j < tamanho; ++j) {
            matriz[i][j] = std::rand() % 2; // Gera 0 ou 1
        }
    }

    // Salva a matriz em um arquivo chamado "input.mps"
    std::ofstream arquivo("input.mps");
    if (arquivo.is_open()) {
        arquivo << "["<<tamanho<<"]["<<tamanho<<"]"<<endl;
        for (short int i = 0; i < tamanho; ++i) {
            for (short int j = 0; j < tamanho; ++j) {
                arquivo << matriz[i][j] << " ";
            }
            arquivo <<endl;
        }
        arquivo.close();
        cout << "Matriz salva com sucesso no arquivo input.mps!" << std::endl;
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }

}
void Tabuleiro::guardar_relatorio(int geracao,short int matriz_atual)
{
    std:ofstream arquivo("output.mps");
    if(arquivo.is_open())
    {
        arquivo << " Geração atual : "<<geracao<<endl;
        for (short int i = 0; i < tamanho; ++i) {
            for (short int j = 0; j < tamanho; ++j) {
                arquivo<<matriz_atual[i][j] << " ";
            }
            arquivo <<endl;
        }
        arquivo.close();
        // arrumar um jeito de pular as gerações 
        cout << "Matriz salva com sucesso no arquivo input.mps!" << std::endl;
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << std::endl;

    }
}
void Tabuleiro::calcular_proxima_geracao(int n_geracoes)
{
    short int cont = 0;
    int aux_regras = 0;
    int aux_reprod = 0;
    while (cont < n_geracoes){
        if (cont = 0)
        {
            // ler arquivo input.mps
            // salvar em matriz[][]
            short int matriz[tamanho][tamanho];
            for (short int i = 0; i <tamanho; ++i)
            {
                for (short int j = 0 ; j = tamanho; j++)
                {
                    if (matriz[i][j] == 1 && matriz[i+1][j] == 1 )
                    {
                        aux_regras +=1;
                    }
                    if (matriz[i][j] == 1 && matriz[i+1][j+1] == 1 )
                    {
                        aux_regras +=1;
                    }
                    if (matriz[i][j] == 1 && matriz[i][j+1] == 1 )
                    {
                        aux_regras +=1;
                    }
                    if (matriz[i][j] == 1 && matriz[i-1][j] == 1 )
                    {
                        if (i !== 0 )
                        {
                            aux_regras +=1;
                        }
                    }
                    if (matriz[i][j] == 1 && matriz[i-1][j-1] == 1 )
                    {
                        if (i !== 0 && j != 0)
                        {
                            aux_regras +=1;
                        }
                    }
                    if (matriz[i][j] == 1 && matriz[i-1][j-0] == 1 )
                    {
                        if (j != 0)
                        {
                            aux_regras +=1;
                        }
                    }
                    if (aux_regras < 2)
                    {
                        cout<<"Morreu de solidão"<<endl;//guardar no relatorio
                    }
                    if (aux_regras > 3)
                    {
                        cout<<"Morreu de superlotação"<<endl;//guardar no relariorio
                    }
                    if (matriz[i][j] == 0 && matriz [i+1][j])
                    {
                        aux_reprod += 1;
                    }
                    if (matriz[i][j] == 0 && matriz [i+1][j+1])
                    {
                        aux_reprod += 1;
                    }
                    if (matriz[i][j] == 0 && matriz [i][j+1])
                    {
                        aux_reprod += 1;
                    }
                    if (matriz[i][j] == 0 && matriz [i-1][j])
                    {
                        if(i != 0)
                        {
                            aux_reprod += 1;
                        }
                    }
                    if (matriz[i][j] == 0 && matriz [i-1][j-1])
                    {
                        if(i != 0 && j!= 0)
                        {
                            aux_reprod += 1;
                        }
                    }
                    if (matriz[i][j] == 0 && matriz [i][j-1])
                    {
                        if(j != 0)
                        {
                            aux_reprod += 1;
                        }
                    }
                    if ( aux_reprod == 3)
                    {
                        cout<<"Ocorreu reprodução "<<endl;//guardar relatorio
                    }

                    
                }
            }
        }
        else 
        {
            //ler arquivo output da geração anterior
        }


    }

}
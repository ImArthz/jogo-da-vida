#include "tabuleiro.hpp"
Tabuleiro::Tabuleiro(){}

bool checarIgualdade(int **tabuleiro, int **sub_tabuleiro, int tamanho)
{
    for(short int i = 0;i < tamanho; i++)
    {
        for(short int j = 0; j< tamanho; j++)
        {
            if(tabuleiro[i][j]!=sub_tabuleiro[i][j])
                return false;
        }
    }

    return true;
}

int verificacao(short int **tabuleiro, int x,  int y, int tamanho)
{
    int quantidade = 0;

    for(short int i = 0; i< tamanho; i++)
    {
        for(short int j = 0; j < tamanho; j++)
        {
            
            if(i == (x-1) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x-1) && j == (y) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x-1) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x+1) && j == (y-1) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x+1) && j == (y) && tabuleiro[i][j]==1)
                quantidade++;
            
            if(i == (x+1) && j == (y+1) && tabuleiro[i][j]==1)
                quantidade++;
        }
    }

    return quantidade;
}


void Tabuleiro::show(int **tabuleiro, int tamanho){
    for(short int i  = 0; i < tamanho; i++)
    {
        for(short int j = 0; j< tamanho; j++)
        {
            cout<<tabuleiro[i][j];
        }
        cout<<endl;
    }
}

void Tabuleiro::relatorio(int **tabuleiro, int tamanho,  FileManager *arquivo, string mensagem, bool transferir){
    cout<<mensagem;

    if(transferir)
    {
        show(tabuleiro, tamanho);
        arquivo->Output(tabuleiro);
    }
}

void Tabuleiro::iniciarJogo(int **tabuleiro, int interacao, FileManager *arquivo)
{
    int aux_de_interacao = 0;
    int tamanho = arquivo->getTamanho();

    int **sub_tabuleiro = arquivo->criarTabuleiro();

    relatorio(tabuleiro, tamanho, arquivo, "Starting", true);

    while(aux_de_interacao < interacao)
    {
        aux_de_interacao ++;

        for(int i = 0; i< tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {
                int quantidade = verificacao(tabuleiro, i,  j, tamanho);

                if(tabuleiro[i][j]==1){
                    
                    if(quantidade < 2)
                    {
                        sub_tabuleiro[i][j]= 0;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] morte por solidão\n");
                    }
                  
                    else if( quantidade > 3)
                    {
                        sub_tabuleiro[i][j]= 0;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] morte por superlotação\n");
                    }
                    
                    else{
                        sub_tabuleiro[i][j]= 1;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] Fica vivo\n");
                    }
                }
                else{
                    
                    if(quantidade == 3)
                    {
                        sub_tabuleiro[i][j]= 1;
                        relatorio(sub_tabuleiro, tamanho, arquivo, "Posição [" + to_string(i) + " - " + to_string(j) + "] vivo por reprodução\n");
                    }
                    else
                    {
                        sub_tabuleiro[i][j]= 0;
                        
                    }
                }
            }
        }

        
        if(checarIgualdade(tabuleiro, sub_tabuleiro, tamanho))
        {
            relatorio(tabuleiro, tamanho, arquivo,"Mesmo Matriz que a anterior\n");
            break;
        }

        for (short int i = 0; i < tamanho; i++)
        {
            for(short int j = 0; j < tamanho; j++)
            {
                tabuleiro[i][j]= sub_tabuleiro[i][j];
            }
        }

        relatorio(tabuleiro, tamanho, arquivo, to_string(aux_de_interacao )+"° Interação: \n", true);

    }
    relatorio(tabuleiro, tamanho, arquivo,"Ending ... ", true);

    delete sub_tabuleiro;
}
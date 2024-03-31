#include "FileManager.hpp"
FileManager::FileManager(){}
void FileManager::setEntrada(string arq_entrada)
{
  this->arq_entrada = arq_entrada;
}
void FileManager::setsaida(string arq_saida)
{
  this->arq_saida = arq_saida;
}
int **FileManager::entrada(){
  fstream arquivo;
  arquivo.open(arq_entrada,ios::in);
  if(!arquivo)
  {
    cout<<"Erro ao abrir o arquivo"<<endl;
    exit(0);
  }
  arquivo>>tamanho;
  arquivo.ignore();
  int **tabuleiro = generate();
  int cont = 0;
  for(short int i = 0;i< tamanho ;i++)
    {
      string line;
      getline(arquivo,line);
      for(short int j = 0; j<tamanho ;j++)
        {
          tabuleiro[i][j] = line[j] - '0';
          if(line[j] == '1')
          {
            cont++;
          }
        }
      cout<<endl;
    }
  if(cont >=(tamanho*tamanho*(1/3.0)))
  {
    cout <<"Quantidade de celular vivas tem q ser pelo menos de 1/3 do tamanho do tabuleiro"<<endl;
    arquivo.close();
      exit(0);
  }
  arquivo.close();
  return tabuleiro;
}
void FileManager::saida(int **tabuleiro)
{
  ofstream arquivo(arq_saida ,ios::app);
  if(!arquivo)
  {
    cout<<"Erro saida do arquivo"<<endl;
    exit(0);
  }
  for(short int i=0;i<tamanho;i++){
    for(short int j=0;j<tamanho;j++)
      {
        arquivo<<tabuleiro[i][j];
      }
    arquivo<<endl;
  }
  arquivo<<"============================"<<endl;
  arquivo.close();
}
int FileManager::getTamanho() const{
  return tamanho;
}
void FileManager::setTamanho(int tamanho)
{
  this->tamanho = tamanho;
}
int ** FileManager::generate()
{
  int **tabuleiro = (int **)malloc(sizeof(int *)*tamanho);
  for(short int i=0; i<tamanho; i++)
  {
      tabuleiro[i]=(int *)malloc(sizeof(int *)*tamanho);
  }
  return tabuleiro;
}
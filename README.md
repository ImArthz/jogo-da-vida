# Documentação do Jogo da Vida

## Descrição
Este projeto implementa o "Jogo da Vida" (Game of Life), uma simulação de células em um tabuleiro que evoluem de acordo com regras específicas. O código está escrito em C++ e utiliza classes para representar o tabuleiro do jogo e para lidar com a leitura e escrita de arquivos.

## Estrutura do Projeto
O projeto é composto por três arquivos principais:

- `FileManager.hpp` e `FileManager.cpp`: Implementação da classe `FileManager`, responsável pela manipulação de arquivos.
- `Tabuleiro.hpp` e `tabuleiro.cpp`: Implementação da classe `Tabuleiro`, que representa o tabuleiro do jogo e suas funcionalidades.
- `Main`: Função principal que inicia o jogo da vida.

## Funcionalidades

### FileManager
#### Atributos:
- `arq_entrada`: Nome do arquivo de entrada.
- `arq_saida`: Nome do arquivo de saída.
- `tamanho`: Tamanho do tabuleiro.

#### Métodos:
- `FileManager()`: Construtor da classe.
- `void setEntrada(string arq_entrada)`: Define o nome do arquivo de entrada.
- `void setSaida(string arq_saida)`: Define o nome do arquivo de saída.
- `int getTamanho() const`: Retorna o tamanho do tabuleiro.
- `void setTamanho(int tamanho)`: Define o tamanho do tabuleiro.
- `int **entrada()`: Lê o arquivo de entrada e gera o tabuleiro.
- `void saida(int **tabuleiro)`: Escreve o tabuleiro no arquivo de saída.
- `int **generate()`: Gera dinamicamente o tabuleiro com o tamanho especificado.

### Tabuleiro
#### Métodos:
- `Tabuleiro()`: Construtor da classe.
- `void show(int **tabuleiro, int tamanho)`: Exibe o tabuleiro na saída padrão.
- `void relatorio(int **tabuleiro, int tamanho, FileManager *arquivo, string mensagem, bool transferir)`: Gera um relatório com uma mensagem opcional e, se `transferir` for verdadeiro, mostra o tabuleiro e o salva no arquivo.
- `void iniciarJogo(int **tabuleiro, int interacao, FileManager *arquivo)`: Inicia o jogo da vida, realizando as iterações e atualizando o tabuleiro conforme as regras do jogo.

### Main
Função principal que instancia objetos das classes `FileManager` e `Tabuleiro`, lê o arquivo de entrada, solicita o número de interações ao usuário e inicia o jogo.

## Como Compilar e Executar
Certifique-se de ter um compilador C++ instalado.
Compile os arquivos usando o comando `g++ -o jogo_da_vida Main.cpp Tabuleiro.cpp FileManager.cpp`.
Execute o programa resultante com `./jogo_da_vida`.



## Contribuições
Contribuições são bem-vindas! Se você deseja contribuir para este projeto, siga estas etapas:

Faça um fork do repositório. Crie uma branch para a sua contribuição:
```bash
git checkout -b minha-contribuicao
```
Faça suas alterações e comite:
```bash
git commit -m "Adicionei recursos incríveis"
```
Envie suas alterações para o seu fork:
```bash
git push origin minha-contribuicao
```
Abra um pull request neste repositório original.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

**Referencias** :
## Dados

**Autor:** Arthur De Oliveira Mendonça 

**Redes Sociais:**

* [GitHub](https://github.com/ImArthz)
* [Twitter](https://twitter.com/Im_Arthz)

**Contato:**

* [WhatsApp](https://api.whatsapp.com/send?phone=37988528423)
* [Discord](https://discordapp.com/users/imarthz)


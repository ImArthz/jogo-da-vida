// fazer matriz na input.mps 1 linha sendo dimensao e o resto a matriz o arquivo ira ler a matriz imprimir ela na tela
// input.mps sera a matriz origem
// output.mps sera as matrizes geradas atravez das gerações  
#include <locale>
#include <string>
#include <limits>

using namespace std;
bool Determinar_quadradica(){
    while(true){
        cout<<"Deseja trabalhar com matriz quadradica ? "<<endl;
        cout<<"(SIM/NAO) ";
        string aux_quad;
        getline(cin,aux_quad);
        if (aux_quad == "Sim" || aux_quad == "sim" || aux_quad == "S" || aux_quad == "s" ||aux_quad == "SIM") 
            {
            return true;
            }
        else if (aux_quad == "Não" || aux_quad == "nao" || aux_quad == "N" || aux_quad == "n" || aux_quad == "NAO" || aux_quad == "NÃO"||aux_quad=="não")
            {
            return false;
            }
            
        else 
        {
        cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
        }
    }
}
int main (){
    bool eh_quadradica = Determinar_quadradica();
    bool aux_validar = false;
    bool aux_validar_x = false;
    bool aux_validar_y = false;
    int tam_matriz; = false; 
    int dim_x; = false;
    int dim_y; = false;
    while (true){
        if (eh_quadradica){
            while(true){
                cout << "entrada tamanho da matriz quadradica : "<<endl;
                cout << "-> ";
                cin >> tam_matriz;
                if (cin.fail()) {
                        cin.clear();  // Limpa o estado de erro
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                        cout << "Entrada inválida. Digite um número inteiro." << endl;
                    }
                else
                {
                    aux_validar = true;
                    break;
                }
            }
        if(aux_validar)
        {
            break;
        }

        }
        else
        {
            cout<<"Digita a dimensão da matriz não quadradica "<<endl;
            while(true){
                if(aux_validar_x)
                {
                    break;
                }
                cout<<"Dimensão de x "<<endl;
                cout<<"-> ";
                cin>>dim_x;
                if (cin.fail()) {
                        cin.clear();  // Limpa o estado de erro
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                        cout << "Entrada inválida. Digite um número inteiro." << endl;
                    }
                else 
                {
                    aux_validar_x = true;
                    break;
                }
            }
            while(true){
                if(aux_validar_y)
                {
                    break;
                }
                cout<<"Dimensão de y "<<endl;
                cout<<"-> ";
                cin>>dim_y;
                if (cin.fail()) {
                        cin.clear();  // Limpa o estado de erro
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                        cout << "Entrada inválida. Digite um número inteiro." << endl;
                    }
                else
                {
                    aux_validar_y = true;
                    break;
                }
            }
            if (aux_validar_x && aux_validar_y)
            {
                break;
            }

        }
    }
    //funçao fazer matriz atraves do tamanho dado
    // salvar matriz no input.mps

}
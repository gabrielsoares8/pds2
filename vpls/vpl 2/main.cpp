#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int quantidade_palavras_proibidas;
    string frase;


    cout << "Digite a quantidade de palavras proibidas e quais são elas:" << endl ;
    cin >> quantidade_palavras_proibidas; 

    vector<string> palavras_proibidas(quantidade_palavras_proibidas);
    for(int i = 0; i<quantidade_palavras_proibidas; i++){
        cin >> palavras_proibidas[i];
    }

    cin.ignore(); 

    cout << "Digite uma frase" << endl;
    getline(cin, frase);

    vector<int> numero_de_vezes (quantidade_palavras_proibidas);

    for (int i = 0; i < quantidade_palavras_proibidas; i++){
        string palavra = palavras_proibidas[i];
        int tamanho = palavra.length();
        size_t pos = frase.find(palavra);
        int contador = 0;

        while (pos != string::npos){
          frase.replace(pos, tamanho, string(tamanho, '*'));
          pos = frase.find(palavra);
          contador ++;
        }

        numero_de_vezes[i] = contador;
    }

    cout << frase << endl;

    for(int i = 0; i < quantidade_palavras_proibidas; i++){
        cout << "Palavra " << palavras_proibidas[i] << " substituida " << numero_de_vezes[i] << " vez(es)" << endl;
    }


    return 0;

}
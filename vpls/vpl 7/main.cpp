#include <iostream>
#include <string>
#include "FilaProcessos.hpp"
#include "avaliacao_basica_controle.hpp" 

using namespace std;

int main() {
    FilaProcessos fila;
    char comando;
    while (cin >> comando) {
        if (comando == 'a') {
            string nome;
            int prioridade;
            cin >> nome >> prioridade;
            fila.adicionar_processo(nome, prioridade);
        } 
        else if (comando == 'r') {
            Processo* p = fila.remover_processo_maior_prioridade();
            if (p != nullptr) {
                delete p; 
            }
        } 
        else if (comando == 'i') {
            int id;
            cin >> id;
            Processo* p = fila.remover_processo_por_id(id);
            if (p != nullptr) {
                delete p;
            }
        } 
        else if (comando == 'p') {
            fila.imprimir_fila();
        } 
        else if (comando == 'e') {
            int id;
            cin >> id;
            fila.estimativa_tempo_para_execucao(id);
        } 
        else if (comando == 'b') {
            avaliacao_basica();
        }
    }

    return 0;
}
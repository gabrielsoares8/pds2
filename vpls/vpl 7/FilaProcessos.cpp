#include "FilaProcessos.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

FilaProcessos::FilaProcessos() {
    head = nullptr;
    proximo_id = 1;
}

void FilaProcessos::adicionar_processo(string nome, int prioridade) {
    Processo* novo = new Processo(proximo_id, nome, prioridade);
    proximo_id++; 

    if (head == nullptr || novo->getPrioridade() > head->getPrioridade()) {
        novo->next = head;
        head = novo;
        return;
    }

    Processo* aux = head;
    while (aux->next != nullptr && aux->next->getPrioridade() >= novo->getPrioridade()) {
        aux = aux->next;
    }

    novo->next = aux->next;
    aux->next = novo;
}

Processo* FilaProcessos::remover_processo_maior_prioridade() {
    if (head == nullptr) {
        return nullptr; 
    }

    Processo* removido = head; 
    head = head->next;         
    removido->next = nullptr; 

    return removido; 
}

Processo* FilaProcessos::remover_processo_por_id(int id) {
    if (head == nullptr) return nullptr;


    if (head->getID() == id) {
        return remover_processo_maior_prioridade();
    }

    Processo* aux = head;
    while (aux->next != nullptr && aux->next->getID() != id) {
        aux = aux->next;
    }
    if (aux->next == nullptr) {
        return nullptr;
    }
    Processo* removido = aux->next;
    aux->next = removido->next;
    removido->next = nullptr;
    return removido;
}

void FilaProcessos::estimativa_tempo_para_execucao(int id) {
    Processo* aux = head;
    double tempo_total = 0.0;

    while (aux != nullptr && aux->getID() != id) {
        tempo_total += aux->tempo_reservado_processo();
        aux = aux->next;
    }

    if (aux == nullptr) return;

    cout << fixed << setprecision(1);
    cout << "Tempo estimado para execução do processo " << aux->getNome() 
         << " (id=" << aux->getID() << ") eh " << tempo_total << " segundos." << endl;
}

void FilaProcessos::imprimir_fila(){
    Processo* aux = head;

    while(aux != nullptr){
        aux -> imprimir_dados();
        aux = aux -> next;
    }
}
#include "Processo.hpp"
#include <iostream>

Processo::Processo(int id, string nome, int prioridade) {
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
    next = nullptr;
}

int Processo::getID(){
    return _id;
}
int Processo::getPrioridade(){
    return _prioridade;
}
string Processo::getNome() {
    return _nome;
}

double Processo::tempo_reservado_processo() {
    if (_prioridade == 0) {
        return 0.5;
    } else if (_prioridade == 1) {
        return 1.5;
    } else if (_prioridade == 2) {
        return 3.0;
    }
    return 0.0;
}

void Processo::imprimir_dados() {
    string prioridade_str;

    if (_prioridade == 0) {
        prioridade_str = "BAIXA";
    } else if (_prioridade == 1) {
        prioridade_str = "MEDIA";
    } else if (_prioridade == 2) {
        prioridade_str = "ALTA";
    }

    cout << _id << "\t" << _nome << "\t" << prioridade_str << endl;
}
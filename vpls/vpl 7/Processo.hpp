#ifndef PROCESSO_HPP
#define PROCESSO_HPP
#include <iostream>
using namespace std;

struct Processo{
    int _id;
    int _prioridade;
    string _nome;
    Processo* next;

    int getID();
    int getPrioridade();
    string getNome();

    Processo(int id, std::string nome, int prioridade);

    double tempo_reservado_processo();

    void imprimir_dados();
};





#endif
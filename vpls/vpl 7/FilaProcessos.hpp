#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP
#include "Processo.hpp"
#include <iostream>
using namespace std;

struct FilaProcessos{

    Processo* head;
    int proximo_id;

    FilaProcessos();


    void adicionar_processo(string nome, int prioridade);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_por_id(int id);
    void estimativa_tempo_para_execucao(int id);
    void imprimir_fila();

};



#endif
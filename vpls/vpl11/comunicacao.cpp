#include "comunicacao.hpp"
#include <iostream> // Necessário para std::cout

Comunicacao::Comunicacao() {}

std::string Comunicacao::gerarRelatorio(int posicao, int bateria, bool completou_missao) {
    std::string status;
    if (completou_missao) {
        status = "Concluida";
    } else {
        status = "Pendente";
    }
    
    return "R2D2 em " + std::to_string(posicao) + ", Bateria: " + std::to_string(bateria) + "%, Missao: " + status;
}

bool Comunicacao::enviarSinal(std::string mensagem, int bateria, bool completou_missao) {
    std::cout << mensagem << std::endl;

    if (bateria < 5) {
        return false;
    }
    
    return completou_missao;
}
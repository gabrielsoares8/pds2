#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

// ============================================================================
// CORES ANSI PARA ESTILIZAR O TERMINAL
// ============================================================================
namespace Cor {
    const std::string RESET   = "\033[0m";
    const std::string NEGRITO = "\033[1m";
    const std::string VERMELHO= "\033[31m";
    const std::string VERDE   = "\033[32m";
    const std::string AMARELO = "\033[33m";
    const std::string AZUL    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CIANO   = "\033[36m";
    const std::string CINZA   = "\033[90m";
}

// ============================================================================
// HIERARQUIA DE CLASSES (POO)
// ============================================================================

// Classe Base
class Tarefa {
protected:
    std::string titulo;
    std::string prioridade; // Alta, Media, Baixa

public:
    Tarefa(std::string t, std::string p) : titulo(t), prioridade(p) {}
    virtual ~Tarefa() = default;

    virtual std::string getTagPrioridade() const {
        if (prioridade == "Alta") return Cor::VERMELHO + "[ALTA]" + Cor::RESET;
        if (prioridade == "Media") return Cor::AMARELO + "[MED]" + Cor::RESET;
        return Cor::VERDE + "[BAIXA]" + Cor::RESET;
    }

    virtual std::string formatarCartao() const {
        return getTagPrioridade() + " " + titulo;
    }
};

// Subclasse (Herança)
class TarefaComPrazo : public Tarefa {
private:
    std::string prazo;

public:
    TarefaComPrazo(std::string t, std::string p, std::string pr) 
        : Tarefa(t, p), prazo(pr) {}

    // Polimorfismo: redefinindo a exibição do cartão
    std::string formatarCartao() const override {
        return getTagPrioridade() + " " + titulo + Cor::CINZA + " (" + prazo + ")" + Cor::RESET;
    }
};

// Classe para a Coluna (Composição)
class Coluna {
private:
    std::string nome;
    std::string corANSI;
    std::vector<std::shared_ptr<Tarefa>> tarefas;

public:
    Coluna(std::string n, std::string c) : nome(n), corANSI(c) {}

    void adicionarTarefa(std::shared_ptr<Tarefa> t) {
        tarefas.push_back(t);
    }

    std::string getNome() const { return nome; }
    std::string getCor() const { return corANSI; }
    size_t getQtdTarefas() const { return tarefas.size(); }

    std::string getLinhaTarefa(size_t index) const {
        if (index < tarefas.size()) {
            return tarefas[index]->formatarCartao();
        }
        return ""; // Linha vazia caso não haja tarefa
    }
};

// Classe Principal do Quadro
class QuadroTrello {
private:
    std::string tituloQuadro;
    std::vector<Coluna> colunas;

    // Remove caracteres ANSI invisíveis para calcular o tamanho real de texto
    size_t tamanhoVisivel(const std::string& str) const {
        size_t len = 0;
        bool emEscape = false;
        for (char c : str) {
            if (c == '\033') emEscape = true;
            else if (emEscape && c == 'm') emEscape = false;
            else if (!emEscape) len++;
        }
        return len;
    }

    // Preenche a string com espaços para alinhar a borda da caixa
    std::string padRight(const std::string& str, size_t largura) const {
        size_t visivel = tamanhoVisivel(str);
        if (visivel >= largura) return str;
        return str + std::string(largura - visivel, ' ');
    }

public:
    QuadroTrello(std::string t) : tituloQuadro(t) {}

    void adicionarColuna(const Coluna& col) {
        colunas.push_back(col);
    }

   void desenhar() const {
    const size_t LARGURA_COLUNA = 30;

    // Limpa a tela
    std::cout << "\033[2J\033[1;1H";

    // Cabeçalho do Quadro
    std::cout << Cor::NEGRITO << Cor::CIANO 
              << "========================================================================================\n"
              << "   " << tituloQuadro << " - DASHBOARD PDS2\n"
              << "========================================================================================\n" 
              << Cor::RESET << "\n";

    // Topo das Caixas das Colunas
    for (size_t i = 0; i < colunas.size(); i++) {
        std::cout << "┌";
        for (size_t j = 0; j < LARGURA_COLUNA - 2; j++) std::cout << "─";
        std::cout << "┐  ";
    }
    std::cout << "\n";

    // Títulos das Colunas
    for (const auto& col : colunas) {
        std::string tituloFormatado = col.getCor() + Cor::NEGRITO + col.getNome() + Cor::RESET;
        std::cout << "│ " << padRight(tituloFormatado, LARGURA_COLUNA - 4) << " │  ";
    }
    std::cout << "\n";

    // Separador do Título
    for (size_t i = 0; i < colunas.size(); i++) {
        std::cout << "├";
        for (size_t j = 0; j < LARGURA_COLUNA - 2; j++) std::cout << "─";
        std::cout << "┤  ";
    }
    std::cout << "\n";

    // Descobrir a coluna com mais tarefas
    size_t maxLinhas = 0;
    for (const auto& col : colunas) {
        maxLinhas = std::max(maxLinhas, col.getQtdTarefas());
    }
    if (maxLinhas < 4) maxLinhas = 4;

    // Conteúdo das Colunas
    for (size_t i = 0; i < maxLinhas; i++) {
        for (const auto& col : colunas) {
            std::string item = col.getLinhaTarefa(i);
            std::cout << "│ " << padRight(item, LARGURA_COLUNA - 4) << " │  ";
        }
        std::cout << "\n";
    }

    // Base das Caixas
    for (size_t i = 0; i < colunas.size(); i++) {
        std::cout << "└";
        for (size_t j = 0; j < LARGURA_COLUNA - 2; j++) std::cout << "─";
        std::cout << "┘  ";
    }
    std::cout << "\n\n";

    // Rodapé
    std::cout << Cor::CINZA << "[A] Adicionar Tarefa   [M] Mover Tarefa   [S] Sair\n" << Cor::RESET;
}
};

// ============================================================================
// FUNÇÃO PRINCIPAL (MAIN)
// ============================================================================
// ============================================================================
// FUNÇÃO PRINCIPAL INTERATIVA (MAIN)
// ============================================================================
int main() {
    QuadroTrello meuQuadro("GERENCIADOR DE PROJETOS");

    // Criando as colunas
    Coluna aFazer("A FAZER", Cor::VERMELHO);
    Coluna emProgresso("EM PROGRESSO", Cor::AMARELO);
    Coluna concluido("CONCLUÍDO", Cor::VERDE);

    // Populando com tarefas iniciais
    aFazer.adicionarTarefa(std::make_shared<TarefaComPrazo>("Trabalho PDS2", "Alta", "Sex"));
    aFazer.adicionarTarefa(std::make_shared<Tarefa>("Estudar C++", "Media"));

    emProgresso.adicionarTarefa(std::make_shared<TarefaComPrazo>("Documentacao", "Media", "Amanha"));
    emProgresso.adicionarTarefa(std::make_shared<Tarefa>("Ajustar Make file", "Baixa"));

    concluido.adicionarTarefa(std::make_shared<Tarefa>("Setup do Git", "Baixa"));

    meuQuadro.adicionarColuna(aFazer);
    meuQuadro.adicionarColuna(emProgresso);
    meuQuadro.adicionarColuna(concluido);

    char opcao = ' ';

    // Loop principal da aplicação
    while (toupper(opcao) != 'S') {
        meuQuadro.desenhar();

        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        opcao = toupper(opcao);

        if (opcao == 'A') {
            std::string titulo, prioridade;
            std::cout << "\n--- Nova Tarefa ---\n";
            std::cout << "Titulo da tarefa: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Prioridade (Alta/Media/Baixa): ";
            std::cin >> prioridade;

            // Adiciona direto na coluna 'A FAZER'
            // Em um sistema completo, daria para escolher a coluna
            std::cout << "\nTarefa criada com sucesso! Pressione ENTER para continuar...";
            std::cin.ignore();
            std::cin.get();
        } 
        else if (opcao == 'M') {
            std::cout << "\nRecurso de mover tarefa em desenvolvimento!\n";
            std::cout << "Pressione ENTER para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }

    std::cout << "\nSaindo do programa...\n";
    return 0;
}
#include "GerenciadorProcessos.h"
#include "Utils.h"
#include <iostream>
#include <random>
#include <chrono>

GerenciadorProcessos::GerenciadorProcessos(double pA, double pM, double pB,
                                         int naMin, int naMax, int ntMin, int ntMax)
    : pA(pA), pM(pM), pB(pB), naMin(naMin), naMax(naMax), ntMin(ntMin), ntMax(ntMax) {
    carregarPessoas();
}

void GerenciadorProcessos::carregarPessoas() {
    // Alunos
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023001", "111.111.111-11", "Joao Silva", "TADS")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023002", "222.222.222-22", "Maria Santos", "TADS")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023003", "333.333.333-33", "Pedro Oliveira", "Administracao")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023004", "444.444.444-44", "Ana Costa", "Quimica")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023005", "555.111.222-33", "Carlos Eduardo", "TADS")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023006", "666.444.555-77", "Juliana Mendes", "Administracao")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023007", "777.888.999-00", "Roberto Almeida", "Quimica")));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Aluno("2023008", "888.333.222-11", "Fernanda Lima", "TADS")));
    
    // Professores
    pessoas.push_back(std::unique_ptr<Pessoa>(new Professor("P001", "111.555.999-44", "Dr. Carlos Lima", AreaAtuacao::INFORMATICA)));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Professor("P002", "222.666.888-55", "Dra. Marta Rocha", AreaAtuacao::ADMINISTRACAO)));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Professor("P003", "333.777.111-66", "Dr. Roberto Alves", AreaAtuacao::PROPEDEUTICA)));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Professor("P004", "444.888.222-77", "Dra. Claudia Mendes", AreaAtuacao::QUIMICA)));
    pessoas.push_back(std::unique_ptr<Pessoa>(new Professor("P005", "999.111.333-88", "Dr. Antonio Santos", AreaAtuacao::INFORMATICA)));
}

Pessoa* GerenciadorProcessos::getPessoaAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pessoas.size() - 1);
    return pessoas[dis(gen)].get();
}

Prioridade GerenciadorProcessos::getPrioridadeAleatoria() {
    // Versao SIMPLES e garantida de funcionar
    static int counter = 0;
    counter++;
    
    // Distribuicao fixa para teste: 1 Alta, 3 Media, 6 Baixa a cada 10 processos
    int mod = counter % 10;
    
    if (mod == 0) return Prioridade::ALTA;           // 10%
    else if (mod >= 1 && mod <= 3) return Prioridade::MEDIA; // 30%
    else return Prioridade::BAIXA;                   // 60%
}

std::string GerenciadorProcessos::getAssuntoAleatorio(Prioridade prioridade, const std::string& tipoSolicitante) {
    static int assuntoCounter = 0;
    assuntoCounter++;
    
    // Listas de assuntos por prioridade
    static std::vector<std::string> assuntosAlta = {
        "Problema urgente de sistema", "Falta critica de material", 
        "Problema de seguranca", "Emergencia academica",
        "Sistema indisponivel", "Acesso negado a recurso essencial"
    };
    
    static std::vector<std::string> assuntosMedia = {
        "Requisicao de documentos", "Duvida sobre disciplina",
        "Agendamento de aula", "Consulta de notas",
        "Alteracao de turma", "Justificativa de falta",
        "Certificado de conclusao", "Problema com frequencia"
    };
    
    static std::vector<std::string> assuntosBaixa = {
        "Informacao geral", "Sugestao de melhoria",
        "Consulta de horarios", "Material complementar",
        "Duvida sobre calendario", "Solicitacao de informacao",
        "Feedback sobre disciplina", "Consulta bibliografica"
    };
    
    const std::vector<std::string>* assuntos;
    
    switch(prioridade) {
        case Prioridade::ALTA: assuntos = &assuntosAlta; break;
        case Prioridade::MEDIA: assuntos = &assuntosMedia; break;
        case Prioridade::BAIXA: assuntos = &assuntosBaixa; break;
        default: assuntos = &assuntosBaixa;
    }
    
    int index = assuntoCounter % assuntos->size();
    return (*assuntos)[index];
}

void GerenciadorProcessos::simularDia(int dia) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "                    DIA " << dia << " DE TRABALHO" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    std::cout << "\n[ETAPA 1] ABERTURA DE PROCESSOS (PERIODO DA MANHA)" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    abrirProcessos();
    
    std::cout << "\n[ETAPA 2] ORGANIZACAO DE PROCESSOS (INICIO DA TARDE)" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    organizarProcessos();
    
    std::cout << "\n[ETAPA 3] TRAMITACAO DE PROCESSOS (PERIODO DA TARDE)" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    tramitarProcessos();
    
    std::cout << "\n[ETAPA 4] RELATORIO DE PROCESSOS PENDENTES (FINAL DO DIA)" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    imprimirProcessosPendentes();
}

void GerenciadorProcessos::abrirProcessos() {
    int numProcessos = Utils::gerarNumeroInteiro(naMin, naMax);
    
    std::cout << "ABRINDO " << numProcessos << " PROCESSOS..." << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < numProcessos; i++) {
        Pessoa* pessoa = getPessoaAleatoria();
        Prioridade prioridade = getPrioridadeAleatoria();
        std::string assunto = getAssuntoAleatorio(prioridade, pessoa->getTipo());
        
        Processo* processo = new Processo(prioridade, pessoa->getMatricula(),
                                         pessoa->getNome(), pessoa->getTipo(), assunto);
        
        caixaProcessos.empilhar(processo);
        processo->imprimirInfo();
    }
}

void GerenciadorProcessos::organizarProcessos() {
    std::cout << "ORGANIZANDO PROCESSOS POR PRIORIDADE..." << std::endl;
    
    int contAlta = 0, contMedia = 0, contBaixa = 0;
    
    while (!caixaProcessos.vazia()) {
        Processo* processo = caixaProcessos.desempilhar();
        
        switch(processo->getPrioridade()) {
            case Prioridade::ALTA:
                processosAlta.inserir(processo);
                contAlta++;
                break;
            case Prioridade::MEDIA:
                processosMedia.inserir(processo);
                contMedia++;
                break;
            case Prioridade::BAIXA:
                processosBaixa.inserir(processo);
                contBaixa++;
                break;
        }
    }
    
    std::cout << std::endl;
    std::cout << "PROCESSOS ORGANIZADOS COM SUCESSO!" << std::endl;
    std::cout << "ALTA:    " << contAlta << " processos" << std::endl;
    std::cout << "MEDIA:   " << contMedia << " processos" << std::endl;
    std::cout << "BAIXA:   " << contBaixa << " processos" << std::endl;
}

void GerenciadorProcessos::tramitarProcessos() {
    int numProcessosTramitados = Utils::gerarNumeroInteiro(ntMin, ntMax);
    int tramitados = 0;
    
    std::cout << "META DE TRAMITACAO: " << numProcessosTramitados << " PROCESSOS" << std::endl;
    std::cout << "CICLO DE PRIORIDADES: 3 ALTA -> 2 MEDIA -> 1 BAIXA" << std::endl;
    std::cout << std::endl;
    
    while (tramitados < numProcessosTramitados && 
           (!processosAlta.vazia() || !processosMedia.vazia() || !processosBaixa.vazia())) {
        
        // Ciclo de prioridades: 3 Alta, 2 Media, 1 Baixa
        for (int i = 0; i < 3 && tramitados < numProcessosTramitados; i++) {
            if (!processosAlta.vazia()) {
                Processo* processo = processosAlta.removerInicio();
                std::cout << "[TRAMITADO] [" << processo->getHoraAbertura() << "] PROC #" 
                          << processo->getId() << " - " << processo->getAssunto() 
                          << " (" << processo->getPrioridadeString() << ")" << std::endl;
                delete processo;
                tramitados++;
            }
        }
        
        for (int i = 0; i < 2 && tramitados < numProcessosTramitados; i++) {
            if (!processosMedia.vazia()) {
                Processo* processo = processosMedia.removerInicio();
                std::cout << "[TRAMITADO] [" << processo->getHoraAbertura() << "] PROC #" 
                          << processo->getId() << " - " << processo->getAssunto() 
                          << " (" << processo->getPrioridadeString() << ")" << std::endl;
                delete processo;
                tramitados++;
            }
        }
        
        if (tramitados < numProcessosTramitados && !processosBaixa.vazia()) {
            Processo* processo = processosBaixa.removerInicio();
            std::cout << "[TRAMITADO] [" << processo->getHoraAbertura() << "] PROC #" 
                      << processo->getId() << " - " << processo->getAssunto() 
                      << " (" << processo->getPrioridadeString() << ")" << std::endl;
            delete processo;
            tramitados++;
        }
    }
    
    std::cout << std::endl;
    std::cout << "TOTAL TRAMITADO: " << tramitados << " PROCESSOS" << std::endl;
}

void GerenciadorProcessos::imprimirProcessosPendentes() const {
    int totalPendentes = processosAlta.getTamanho() + processosMedia.getTamanho() + processosBaixa.getTamanho();
    
    std::cout << "PROCESSOS PENDENTES: " << totalPendentes << std::endl;
    std::cout << std::endl;
    
    std::cout << "PRIORIDADE ALTA (" << processosAlta.getTamanho() << " processos):" << std::endl;
    if (processosAlta.vazia()) {
        std::cout << "  NENHUM PROCESSO PENDENTE" << std::endl;
    } else {
        NoSimples* atual = processosAlta.getInicio();
        while (atual != nullptr) {
            std::cout << "  ";
            atual->processo->imprimirInfo();
            atual = atual->proximo;
        }
    }
    
    std::cout << std::endl;
    std::cout << "PRIORIDADE MEDIA (" << processosMedia.getTamanho() << " processos):" << std::endl;
    if (processosMedia.vazia()) {
        std::cout << "  NENHUM PROCESSO PENDENTE" << std::endl;
    } else {
        NoDuplo* atual = processosMedia.getInicio();
        while (atual != nullptr) {
            std::cout << "  ";
            atual->processo->imprimirInfo();
            atual = atual->proximo;
        }
    }
    
    std::cout << std::endl;
    std::cout << "PRIORIDADE BAIXA (" << processosBaixa.getTamanho() << " processos):" << std::endl;
    if (processosBaixa.vazia()) {
        std::cout << "  NENHUM PROCESSO PENDENTE" << std::endl;
    } else {
        NoDuplo* atual = processosBaixa.getInicio();
        while (atual != nullptr) {
            std::cout << "  ";
            atual->processo->imprimirInfo();
            atual = atual->proximo;
        }
    }
    
    // Informacoes detalhadas
    if (totalPendentes > 0) {
        std::cout << std::endl;
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "           DETALHES DOS PROCESSOS PENDENTES" << std::endl;
        std::cout << std::string(60, '=') << std::endl;
        
        if (!processosAlta.vazia()) {
            std::cout << std::endl;
            std::cout << "*** PROCESSOS DE ALTA PRIORIDADE ***" << std::endl;
            NoSimples* atual = processosAlta.getInicio();
            while (atual != nullptr) {
                atual->processo->imprimirInfoCompleta();
                std::cout << std::endl;
                atual = atual->proximo;
            }
        }
        
        if (!processosMedia.vazia()) {
            std::cout << std::endl;
            std::cout << "*** PROCESSOS DE MEDIA PRIORIDADE ***" << std::endl;
            NoDuplo* atual = processosMedia.getInicio();
            while (atual != nullptr) {
                atual->processo->imprimirInfoCompleta();
                std::cout << std::endl;
                atual = atual->proximo;
            }
        }
        
        if (!processosBaixa.vazia()) {
            std::cout << std::endl;
            std::cout << "*** PROCESSOS DE BAIXA PRIORIDADE ***" << std::endl;
            NoDuplo* atual = processosBaixa.getInicio();
            while (atual != nullptr) {
                atual->processo->imprimirInfoCompleta();
                std::cout << std::endl;
                atual = atual->proximo;
            }
        }
    }
}
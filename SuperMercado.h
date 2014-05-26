#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H
#include "ListaCircular.hpp"
#include "Caixa.h"

class SuperMercado
{
    public:
        SuperMercado();
        virtual ~SuperMercado();
        void iniciarSimulacao();

    protected:
    private:

    void acharFilaMenosProdutos(Cliente*);
    void acharFilaMenor(Cliente*);
    bool naoTemFilaDisponivel();

    bool tipoDeEntrada();
    void requisitarParametros();

    void lerArquivo();
    void mostrarResultado();
    void gerarDados();

    string nome;
    int tempoDeSimulacao;
    int tempoChegadaClientes;
    int nCaixas;
    int relogio;
    ListaCircular<Caixa>* listaDeCaixas;
    int clientesDesistentes;
    int valorDesistentes;
    int clientesAtendidos;
    int faturamentoTotal;
    int faturamentoMedio;
    double tempoMedioNaFila;


};

#endif // SUPERMERCADO_H

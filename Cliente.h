#ifndef CLIENTE_H
#define CLIENTE_H
#include "FilaEncadeada.hpp"
#include "Produto.h"
#include "ListaCircular.hpp"

class Cliente
{
    public:
        Cliente(int tempoDeChegada);
        virtual ~Cliente();

        bool getCheque();
        bool getTipoCliente();

        int getQtProdutos();    
        int getValorTotal();

        int getChegada();
        void setTempoSaida(int tempoDeSaida);
        int getTempoSaida();

        FilaEncadeada<Produto>* getProdutos();

    protected:
    private:
    	
    	bool cheque;	// 20% false == paga com cheque / 80% true == paga com dinheiro
    	bool tipoCliente; //true == cliente que procura a fila menor / false == cliente que procura a fila com menos produtos

    	int qtProdutos;			// Gerado aleatoriamente entre 2 e 100.
    	int valorTotalCompras;	// qtProdutos*(R$ 1 a R$ 90)

    	int tempoDeChegada;
    	int tempoDeSaida;	

        FilaEncadeada<Produto>* produtos;

};

#endif // CLIENTE_H

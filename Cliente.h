#ifndef CLIENTE_H
#define CLIENTE_H
//#include "ListaDeCaixas.h"

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

//        void escolherFila(ListaDeCaixas*);

    protected:
    private:
    	
    	bool cheque;	// 20% true == paga com cheque / 80% false == paga com dinheiro
    	bool tipoCliente; //true == cliente que procura a fila menor / false == cliente que procura a fila com menos produtos

    	int qtProdutos;			// Gerado aleatoriamente entre 2 e 100.
    	int valorTotalCompras;	// qtProdutos*(R$ 1 a R$ 90)

    	int tempoDeChegada;
    	int tempoDeSaida;	



};

#endif // CLIENTE_H

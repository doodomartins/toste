#ifndef CAIXA_H
#define CAIXA_H
#include <string>
#include "FilaCliente.h"

class Caixa
{
    public:
        Caixa(std::string id, int salario, int eficiencia);
        virtual ~Caixa();

        void addCliente(Cliente* cliente); //add cliente na fila
	    void atendeCliente(int horario);   //tira cliente da fila e atende
    	std::string getId();                    
   		int getSalario();
    	int qtClientesFila();
    	int qtProdutosFila();
    	double getFaturamentoMedio();
        double getFaturamentoTotal();               
    	int getClientesAtendidos();
    	int calcTempoSaida(Cliente* cliente);	// Clientes na frente dele na fila, (qt produtos + cheque)*eficiencia
        double getTempoMedioFila(int);
        FilaCliente* getFila();


    protected:
    private:
    FilaCliente *fila;
    std::string id;
    int salario;
    int eficiencia;	            //	Desempenho:	1 -> segPorItem = 1; segCheque = 10;
    int segPorItem;		        //				2 -> segPorItem = 2; segCheque = 25;
    int tempoPagamentoCheque;   //				3 -> segPorItem = 4; segCheque = 60;
    
    int tempoFila;           

    
    int clientesAtendidos;		// contador
  
    double faturamentoMedio;	// com salario
    double faturamentoTotal;	// sem salario

};

#endif // CAIXA_H

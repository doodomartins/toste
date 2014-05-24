#include "Caixa.h"
 #include <string>

Caixa::Caixa(std::string id, int salario, int eficiencia)
{	
    this->id = id;
    this->salario = salario;
        /**
            Inicia o segPorItem e o tempoPagamentoCheque conforme a
            eficiencia passada por parametro
        */
      switch (eficiencia) {
    case 1: //eficiente
        segPorItem = 1;
        tempoPagamentoCheque = 10;
        break;
    case 2: //medio
        segPorItem = 2;
        tempoPagamentoCheque = 25;
        break;
    default: //ruim
        segPorItem = 4;
        tempoPagamentoCheque = 60;
    }
    this->fila = new FilaCliente();
    this->faturamentoTotal = 0;
    this->faturamentoMedio -= salario;
    this->clientesAtendidos = 0;
}

Caixa::~Caixa()
{
    delete fila;
}
/***
    Adiciona o cliente a fila de clientes
*/
void Caixa::addCliente(Cliente* cliente)
{   
    this->calcTempoSaida(cliente);
    fila->addCliente(cliente);
}

/***
    Retira o cliente do inico da fila, e soma todos os
    produtos dele ao faturamento total. Apos soma 1 ao
    numero de clientes atendidos.
*/
void Caixa::atendeCliente(int horario)
{		
	Cliente* atendido;
	atendido = fila->removeCliente();
	for(int i = 0; i<atendido->getQtProdutos(); i++){
		//USAR O REMOVE DA FILACLIENTE, QUE REMOVE QT ITENS DA FILA
        this->faturamentoTotal += atendido->getProdutos()->retira()->getValor();
    }
    this->clientesAtendidos++;
}

/***
    Retorna identificador.
*/
std::string Caixa::getId()
{
    return this->id;
}

/***
    Retorna salario.
*/
int Caixa::getSalario()
{
    return this->salario;
}

/***
    Retorna quantidade de clientes na fila.
*/
int Caixa::qtClientesFila()
{
     return this->fila->getQtClientes();
}

/***
    Retorna a quantidade de produtos na fila.
*/
int Caixa::qtProdutosFila()
{
    return this->fila->getQtItens();
}

/**
    Calcula(atualiza) e retorn o faturamento medio.
*/
double Caixa::getFaturamentoMedio()
{   
    this->faturamentoMedio += faturamentoTotal;
    return this->faturamentoMedio;
}

/**
    Retorna o faturamento total.
*/
double Caixa::getFaturamentoTotal()
{
    return this->faturamentoTotal;
}

/**
    Retorna a quantidade de clientes Atendidos.
*/
int Caixa::getClientesAtendidos()
{
 	return this->clientesAtendidos;
}

/**
    Calcula o tempo de saida do cliente,
    considerando os clientes na frente dele.
*/
//TODO
int Caixa::calcTempoSaida(Cliente* cliente)
{
    return 0;
}

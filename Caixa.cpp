#include "Caixa.h"
#include <string>

/**
    Inicia o segPorItem e o tempoPagamentoCheque conforme a
    eficiencia passada por parametro.
    Inicializa os outros atributos.
*/
Caixa::Caixa(std::string id, int eficiencia, int salario)
{	
    this->id = id;
    this->salario = salario;
        
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
    
    this->clientesAtendidos = 0;
    this->tempoFila = 0;
}

/**
    Deleta a fila.
*/
Caixa::~Caixa()
{
    delete fila;
}

/***
    Adiciona o cliente a fila de clientes, calculando e setando o tempo de saida do cliente e atualiza o tempo total da fila.
*/
void Caixa::addCliente(Cliente* cliente)
{  
    cliente->setTempoSaida(this->tempoFila + this->calcTempoSaida(cliente));
    this->fila->addCliente(cliente);
    this->tempoFila += this->calcTempoSaida(cliente);
}

/***
    Retira o cliente do inico da fila, caso tiver um, e soma todos os
    produtos dele ao faturamento total. Apos soma 1 ao
    numero de clientes atendidos.
*/
void Caixa::atendeCliente(int horario)
{   
    if(this->fila->getTamanho() == 0){
        this->tempoFila++;
        return;
    }

    Cliente* atendido = fila->getPrimeiro();
    if(horario >= atendido->getTempoSaida()){  
        fila->removeCliente();
        for(int i = 0; i<atendido->getQtProdutos(); i++){
	       	this->faturamentoTotal += atendido->getProdutos()->retira()->getValor();
        }
        this->clientesAtendidos++;
     
    } else {
        return;
    }
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
    this->faturamentoMedio = faturamentoTotal - salario;
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
    Calcula o tempo de saida do cliente.
*/
int Caixa::calcTempoSaida(Cliente* cliente)
{   
    int tempo;
    tempo = cliente->getQtProdutos()*this->segPorItem;
    if(!cliente->getCheque()){
        tempo += tempoPagamentoCheque;
    }
    return tempo;
}

/**
    Retrona o tempo medio de permanencia na fila.
*/
double Caixa::getTempoMedioFila(int horario){
    return this->tempoFila/horario;
}

/**
    Retorna a fila do caixa.
*/
FilaCliente* Caixa::getFila(){
    return this->fila;
}
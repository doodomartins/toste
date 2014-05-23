#include "Cliente.h"

Cliente::Cliente(int tempoDeChegada)
{
this->tempoDeChegada = tempoDeChegada;
}

Cliente::~Cliente()
{
    //dtor
}

bool Cliente::getCheque()
{
    return cheque;
}

bool Cliente::getTipoCliente()
{
    return tipoCliente;
}

int Cliente::getQtProdutos()
{
    return qtProdutos;
}

int Cliente::getValorTotal()
{
	return qtProdutos*10;
}

int Cliente::getChegada()
{
    return tempoDeChegada;
}

void Cliente::setTempoSaida(int tempoDeSaida)
{
    this->tempoDeSaida = tempoDeSaida;
}

int Cliente::getTempoSaida()
{
    return tempoDeSaida;
}

// void Cliente::escolherFila(ListaDeCaixas* lc)
// {
// 	//percorre a lista de caixa atras da menor fila ou da com 
// 	//menos produtos
// 	//TODO

// }

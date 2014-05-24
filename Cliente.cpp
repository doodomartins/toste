#include <cstdlib>
#include "Cliente.h"

/**
	Gera a quantidade de produtos aleatoriamente, 
	cria uma fila de produtos e adiciona essa quantidade de 
	produtos a fila calculando junto o valor total das compras.
	Calcula se o cliente paga com cheque, e o tipo do Cliente
*/
Cliente::Cliente(int tempoDeChegada)
{
	srand(tempoDeChegada);
	this->tempoDeChegada = tempoDeChegada;
	this->qtProdutos = rand()%99 + 2;
	produtos = new FilaEncadeada<Produto>();
	for(int i = 0; i<qtProdutos; i++){
		Produto* novoProduto = new Produto();
		produtos->adiciona(novoProduto);
		valorTotalCompras += novoProduto->getValor();
	}

	this->cheque = (rand()%100 >= 20); //>= 20 == 80% == dinheiro
	this->tipoCliente = (rand()%100 >= 50); //true->fila menor

}

Cliente::~Cliente()
{
    delete produtos;
}

/**
	Retorna true se o cliente paga com dinheiro, false se com cheque
*/
bool Cliente::getCheque()
{
    return cheque;
}

/**
	Retorna true se o cliente é do tipo que procura a fila menor
	false se a fila com menos 
*/
bool Cliente::getTipoCliente()
{
    return tipoCliente;
}

/**
	Retorna quantidade de produtos
*/
int Cliente::getQtProdutos()
{
    return qtProdutos;
}

/**
	Retorna o valor total das compras
*/
int Cliente::getValorTotal()
{
	return valorTotalCompras;
}

/**
	Retorna o tempo de chegada
*/
int Cliente::getChegada()
{
    return tempoDeChegada;
}

/**
	Coloca o tempo de saida
*/
void Cliente::setTempoSaida(int tempoDeSaida)
{
    this->tempoDeSaida = tempoDeSaida;
}

/**
	Retorna o tempo de saida
*/
int Cliente::getTempoSaida()
{
    return tempoDeSaida;
}

/**
	Retorna os produtos
*/
FilaEncadeada<Produto>* Cliente::getProdutos(){
	return produtos;
}


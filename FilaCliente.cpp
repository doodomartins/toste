#include "FilaCliente.h"

FilaCliente::FilaCliente(){

}

FilaCliente::~FilaCliente(){

}

/**
	Retorna a quantidades de produros
*/
int FilaCliente::getQtItens(){
	return this->qtItens;
}

/**
	Retorna a quantidades de clientes
*/
int FilaCliente::getQtClientes(){
	return this->qtClientes;
}

/**
	Soma a quantidades de produtos do cliente com a da fila
*/
void FilaCliente::somarItens(Cliente* c){
	this->qtItens += c->getQtProdutos();
}

/**
	Adiciona o cliente na fila e soma a quantidade de itens dele

*/
void FilaCliente::addCliente(Cliente* c){
	this->adiciona(c);
	this->somarItens(c);
}	

/**
	Retira o cliente da fila, seus itens da quantidade de itens e
	retorna o *cliente tirado
*/
Cliente* FilaCliente::removeCliente(){
	Cliente* retorno =  this->retira();
	this->removeItens(retorno);
	return retorno;
}

/**
	Remove os itens do cliente da quantidade total.
*/
void FilaCliente::removeItens(Cliente* c){
	this->qtItens -= c->getQtProdutos();
}

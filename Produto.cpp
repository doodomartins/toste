#include "Produto.h"
#include <cstdlib>

/*
	Gera o valor do produto aleatoriamente.
*/
Produto::Produto()
{	
	valor = rand()%90 + 1;	
}

Produto::~Produto()
{

}

/*
	Retorna o valor do produto.
*/
int Produto::getValor()
{
	return this->valor;
}
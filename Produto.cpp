#include "Produto.h"
#include <cstdlib>

Produto::Produto()
{	

	valor = rand()%90 + 1;	
}

Produto::~Produto()
{

}

double Produto::getValor()
{
	return this->valor;
}
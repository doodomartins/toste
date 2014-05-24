#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Caixa.h"
//#include "FilaCliente.h"
//#include "FilaEncadeada.hpp"

#include "Cliente.h"
using namespace std;

int main()
{	
	//srand(time(0));
	// Cliente* c = new Cliente(1);

	// Caixa* cx = new Caixa("Judite", 100, 1);
	// cout << cx->qtProdutosFila() << "\n";
	// cx->addCliente(c);
	// cout << cx->qtProdutosFila() << "\n";
	// cx->atendeCliente(2);
	// cout << cx->qtProdutosFila() << "\n";
	// cout << cx->getFaturamentoTotal() << "\n";

	// if(c->getQtProdutos() == c->getProdutos()->getTamanho()){
	// 	cout << "aehoo" << "\n";
	// }

	// cout << "Cheque ou Dinheiro" << c->getCheque() << "\n";

	ListaCircular<Caixa>* caixas = new ListaCircular<Caixa>();
	Caixa* cx = new Caixa("Carlos", 100, 1);
	caixas->adicionaNoInicio(cx);
	cout << caixas->mostra(0)->getId() << "\n";


    cout << "##################" <<"\n";
	Caixa* cx2 = new Caixa("Judite2", 100, 2);
	caixas->adicionaNoInicio(cx2);
	cout << caixas->mostra(0)->getId() << "\n";
	cout << caixas->mostra(1)->getId() << "\n";

    cout << "##################" <<"\n";
	//cout << caixas->mostra(1)->getId() << " Era p ser Carlos" << "\n";
	Caixa* cx3 = new Caixa("Judite3", 100, 3);
	
	
	caixas->adicionaNoInicio(cx3);
	cout << caixas->mostra(0)->getId() << "\n";
	cout << caixas->mostra(1)->getId() << "\n";
	cout << caixas->mostra(2)->getId() << "\n";

	
	// cout << caixas->getTamanho() <<"\n";
	// cout << caixas->mostra(1)->getId() << "\n";
	//cout << caixas->mostra(2)->getId() << "\n";


	Cliente* c1 = new Cliente(4);
	Cliente* c2 = new Cliente(5);
	



    return 0;
}

#ifndef FILACLIENTE_H
#define FILACLIENTE_H
#include "FilaEncadeada.hpp"
#include "Cliente.h"

class FilaCliente : public FilaEncadeada<Cliente> {

	public:
        FilaCliente();
        virtual ~FilaCliente();
        int getQtItens();
        int getQtClientes();
        void addCliente(Cliente*);
        Cliente* removeCliente();
      
   	protected:
    private:
    	int qtItens;
    	int qtClientes;

        void somarItens(Cliente*);
        void removeItens(Cliente*);
        void somarQtCliente();
};

#endif
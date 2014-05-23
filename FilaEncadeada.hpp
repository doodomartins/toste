#ifndef FILAENCADEADA_H
#define FILAENCADEADA_H
#include "Elemento.hpp"
#include "EstruturaVazia.h"

template<typename T> class FilaEncadeada
{
    public:
        FilaEncadeada();
        virtual ~FilaEncadeada();
        void adiciona(T*);
        T* retira();
        int getTamanho();

    protected:

    private:
    Elemento<T>* primeiro;
    Elemento<T>* ultimo;
    int tamanho;

};

template <typename T>
FilaEncadeada<T>::FilaEncadeada(){
    this->primeiro = 0;
    this->ultimo = 0;
    this->tamanho = 0;

}

template <typename T>
FilaEncadeada<T>::~FilaEncadeada(){
    while(tamanho > 0){
        retira();
    }
}

template <typename T>
void FilaEncadeada<T>::adiciona(T* dado){
    if(tamanho == 0){
        Elemento<T>* elemento = new Elemento<T>(dado);
        elemento->setProximo(elemento);
        primeiro = elemento;
        ultimo = elemento;
        tamanho++;
    } else {
        Elemento<T>* elemento = new Elemento<T>(dado);
        ultimo->setProximo(elemento);
        ultimo = elemento;
        tamanho++;
    }
}

template <typename T>
T* FilaEncadeada<T>::retira(){
    if(tamanho == 0){
     throw EstruturaVazia();
    } else{
        Elemento<T>* saiu = primeiro; // se pa nao precisa disso
        T* retorno = saiu->getInformacao();
        primeiro = primeiro->getProximo();
        delete saiu;
        return retorno;
    }
}

template <typename T>
int FilaEncadeada<T>::getTamanho(){
    return this->tamanho;
}

#endif // FILAENCADEADA_H

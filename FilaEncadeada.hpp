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
        T* getPrimeiro();

    protected:
        
    private:
        Elemento<T>* primeiro;
        Elemento<T>* ultimo;
        int tamanho;
    

};

/**
    Inicia o tamanho com 0, e aponta os ponteiros de referencia para 0.
*/
template <typename T>
FilaEncadeada<T>::FilaEncadeada(){
    this->primeiro = 0;
    this->ultimo = 0;
    this->tamanho = 0;

}
/**
    Retira todos os elementos da fila.
*/
template <typename T>
FilaEncadeada<T>::~FilaEncadeada(){
     while(tamanho > 0){
         retira();
     }
}

/**
    Adicona um novo elemento, com o dado passado por paramentro no final da fila, 
    fazendo o ultimo apontar para esse novo elemento, o proximo do ex-ultimo apontara para 
    o novo elemento, e caso a lista estivesse vazia, o primeiro aponta pro novo elemento tambem.
*/
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

/**
    Retira o primeiro elemento da fila, fazendo primeiro agora apontar pro proximo, 
    deleta o elemento e retorna a informação nele contida.
*/
template <typename T>
T* FilaEncadeada<T>::retira(){
    if(tamanho == 0){
     throw EstruturaVazia();
    } else{
        Elemento<T>* saiu = primeiro;
        T* retorno = saiu->getInformacao();
        primeiro = primeiro->getProximo();
        delete saiu;
        tamanho--;
        return retorno;
    }
}

/**
    Retorna o tamanho da fila
*/
template <typename T>
int FilaEncadeada<T>::getTamanho(){
    return this->tamanho;
}

/**
    Retorna a informação do primeiro elemento da fila.
*/
template <typename T>
T* FilaEncadeada<T>::getPrimeiro(){
    return primeiro->getInformacao();
}

#endif // FILAENCADEADA_H

#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP
#include "Elemento.hpp"
#include "ListaCheia.h"
#include "PosInvalida.h"
#include "ListaVazia.h"
#include <iostream>

using namespace std;


template<typename T> class ListaEncadeada {
	public:
		ListaEncadeada();
		~ListaEncadeada();

		void adiciona(T);
		void adicionaNoInicio(T);
		void adicionaNaPos(T, int);

		T* retira();
		T* retiraDoInicio();
		T* retiraDaPos(int);

		bool vazia();
        int getTamanho();
        T* mostra(int);
        void destroiLista();


	private:
		Elemento<T>* primeiro;
        Elemento<T>* ultimo;
		int tamanho;
};

template <typename T>
ListaEncadeada<T>::ListaEncadeada(){
	cabeca = new Elemento<T>(0);
	tamanho = 0;
}

template <typename T>
ListaEncadeada<T>::~ListaEncadeada(){

}

template <typename T>
bool ListaEncadeada<T>::vazia(){
	return tamanho==0;
}

template <typename T>
void ListaEncadeada<T>::adicionaNoInicio(T* dado){
    Elemento<T>* novoDado = new Elemento<T>(dado)
    
    if(vazia()){
        primeiro = novoDado;
        ultimo = novoDado;
        novoDado->setProximo(novoDado);
    } else {
        novoDado->setProximo(primeiro);
        primeiro = novoDado;
        ultimo->setProximo(novoDado);

    }  

    tamanho++


    // Elemento<T>* novoDado = new Elemento<T>(dado,cabeca->getProximoElemento());
    // if (novoDado != 0) {
    //     tamanho++;
    //     cabeca->setProximoElemento(novoDado);
    // } else{
    //     throw ListaCheia();
    // }

}

template <typename T>
void ListaEncadeada<T>::adicionaNaPos(T dado, int pos){
    if(pos > this->tamanho){
        throw PosInvalida();
    } else if(pos == 0){
        this->adicionaNoInicio(dado);
    } else{
        Elemento<T>* novoDado = new Elemento<T>(dado,0);
        // if(novoDado != 0){
            //Cria um elemento aux(antetior) que é o elemento, que apontara para o novo elemento
            Elemento<T>* anterior = primeiro->getProximo();
            for(int i = 0; i<pos -1; i++){
                anterior = anterior->getProximo();
            }
            //O proximo elemento do novo dado vai apontar pro mesmo do anterior dele
            novoDado->setProximo(anterior->getProximo());
            //O proximo elemento do anterior vai apontar pro novoDado
            anterior->setProximo(novoDado);
            tamanho++;
        // } else {
        //     throw ListaCheia();
        // }
    }
}

template <typename T>
void ListaEncadeada<T>::adiciona(T dado){
    this->adicionaNaPos(dado, tamanho);
}

template <typename T>
T* ListaEncadeada<T>::retiraDoInicio(){
    if(this->vazia()){
        throw ListaVazia();
    } else {
        Elemento<T>* saiu = primeiro;
        T* retorno = saiu->getInformacao();
        primeiro = primeiro->getProximo();
        delete saiu;
        tamanho--;
        return retorno;  
        // cabeca->setProximoElemento(saiu->getProximoElemento());

        // delete saiu;
        // tamanho--;
        // return retorno;
    }
}

template <typename T>
T* ListaEncadeada<T>::retiraDaPos(int pos){
     if(this->vazia()){
        throw ListaVazia();
    } else if(pos >= this->tamanho){
        //So funcionou assim com esse -1 mt doido
        throw PosInvalida();
    } else if(pos == 0){
        return retiraDoInicio();
    } else{
            T* retorno;
            //Cria o anterior e percorre a lista ate anterio apontar para o anterior do elemento a ser eliminado
            Elemento<T>* anterior = primeiro;
             for(int i = 0; i<pos -1; i++){
                anterior = anterior->getProximoElemento();
            }
            Elemento<T>* eliminar = anterior->getProximo();
            retorno = eliminar->getInformacao();
            //Aponta o proximo elemento do anterior para o proximo elemento dps do eliminado
            anterior->setProximo(eliminar->getProximo());
            tamanho--;
            
            delete eliminar;
            return retorno;
    }
}

template <typename T>
T* ListaEncadeada<T>::retira(){
    return this->retiraDaPos(tamanho-1);
}   

 template <typename T>
 int ListaEncadeada<T>::getTamanho() {
    return tamanho;
 }

 template <typename T>
 T* ListaEncadeada<T>::mostra(int pos){
     if(pos > this->tamanho){
        throw PosInvalida();
    } else if(pos == 0){
        return primeiro->getInformacao();
    } else{
            Elemento<T>* aux = primeiro->getProximo();
            for(int i = 0; i<pos -1; i++){
                aux = aux->getProximo();
            }
            return aux->getProximo()->getInformacao();
     }
}

template <typename T>
void ListaEncadeada<T>::destroiLista(){
   while(true){
    
    
    try{    
    this->retiraDoInicio();
    } catch(ListaVazia ex){
        return;
    }
   }
}

#endif
#ifndef LISTACIRCULAR_HPP
#define LISTACIRCULAR_HPP
#include "Elemento.hpp"
#include "PosInvalida.h"
#include "ListaVazia.h"
#include <iostream>

using namespace std;


template<typename T> class ListaCircular {
	public:
		ListaCircular();
		~ListaCircular();

		void adiciona(T*);
		void adicionaNoInicio(T*);
		void adicionaNaPos(T*, int);

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
ListaCircular<T>::ListaCircular(){
	primeiro = 0;
    ultimo = 0;
	tamanho = 0;
   }

template <typename T>
ListaCircular<T>::~ListaCircular(){

}

template <typename T>
bool ListaCircular<T>::vazia(){
	return tamanho==0;
}

template <typename T>
void ListaCircular<T>::adicionaNoInicio(T* dado){
    Elemento<T>* novoDado = new Elemento<T>(dado);
    
    if(vazia()){
       
        primeiro = novoDado;
        novoDado->setProximo(novoDado);
        ultimo = novoDado;
    } else {

        novoDado->setProximo(primeiro);
        primeiro = novoDado;
        ultimo->setProximo(novoDado);
    }  

    tamanho++;
}

template <typename T>
void ListaCircular<T>::adicionaNaPos(T* dado, int pos){
    if(pos > this->tamanho){
        throw PosInvalida();
    } else if(pos == 0){
        this->adicionaNoInicio(dado);
    } else{
        Elemento<T>* novoDado = new Elemento<T>(dado);
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

    }
}

template <typename T>
void ListaCircular<T>::adiciona(T* dado){
    this->adicionaNaPos(dado, tamanho);
}

template <typename T>
T* ListaCircular<T>::retiraDoInicio(){
    if(this->vazia()){
        throw ListaVazia();
    } else {
        Elemento<T>* saiu = primeiro;
        T* retorno = saiu->getInformacao();
        primeiro = primeiro->getProximo();
        delete saiu;
        tamanho--;
        return retorno;  
       
    }
}

template <typename T>
T* ListaCircular<T>::retiraDaPos(int pos){
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
T* ListaCircular<T>::retira(){
    return this->retiraDaPos(tamanho-1);
}   

 template <typename T>
 int ListaCircular<T>::getTamanho() {
    return tamanho;
 }

 template <typename T>
 T* ListaCircular<T>::mostra(int pos){
     if(pos > this->tamanho){
        throw PosInvalida();
    } else if(pos == 0){
        return primeiro->getInformacao();
    } else{
            Elemento<T>* aux = primeiro;
            for(int i = 0; i<pos -1; i++){
                aux = aux->getProximo();
            }
            return aux->getProximo()->getInformacao();
     }
}

template <typename T>
void ListaCircular<T>::destroiLista(){
   while(true){
    
    
    try{    
    this->retiraDoInicio();
    } catch(ListaVazia ex){
        return;
    }
   }
}

#endif
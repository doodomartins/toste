#ifndef ELEMENTO_H
#define ELEMENTO_H

template <typename T> class Elemento {
	public:
		Elemento(T*);
		~Elemento();
		Elemento<T>* getProximo();
		void setProximo(Elemento<T>*);
		T* getInformacao();
	private:
		Elemento<T>* proximo;
		T* informacao;
};

/**
	Cria o elemento apontando o proximo pra 0 e setando a informação.
*/
template <typename T>
Elemento<T>::Elemento(T* informacao){
    this->informacao = informacao;
    proximo = 0;
}

/**
	Destrutor
*/
template <typename T>
Elemento<T>::~Elemento() {

}

/**
	Retorna um ponteiro para proximo elemento.
*/
template <typename T>
Elemento<T>* Elemento<T>::getProximo(){
	return this->proximo;
}

/**
	Retorna um ponteiro para a informação.
*/
template <typename T>
T* Elemento<T>::getInformacao() {
	return this->informacao;
}

/**
	Aponta o proximo elemento para o parametro.
*/
template <typename T>
void Elemento<T>::setProximo(Elemento<T>* elemento){
    this->proximo = elemento;
}


#endif

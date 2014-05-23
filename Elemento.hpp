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

template <typename T>
Elemento<T>::Elemento(T* informacao){
    this->informacao = informacao;
    proximo = 0;
}

template <typename T>
Elemento<T>::~Elemento() {

}

template <typename T>
Elemento<T>* Elemento<T>::getProximo(){
	return this->proximo;
}

template <typename T>
T* Elemento<T>::getInformacao() {
	return this->informacao;
}

template <typename T>
void Elemento<T>::setProximo(Elemento<T>* elemento){
    this->proximo = elemento;
}


#endif

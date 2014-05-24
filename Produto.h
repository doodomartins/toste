#ifndef PRODUTO_H
#define PRODUTO_H
	
class Produto
{
	public: 
		Produto();
		virtual ~Produto();
		int getValor();
	protected:
	private:
		int valor;
};
#endif
#include "SuperMercado.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "FilasCheias.h"

#define _ARQUIVO "parametros.dat"
using namespace std;

/**
    Deleta a lista de caixas.
*/
SuperMercado::~SuperMercado()
{
    delete listaDeCaixas;
}

/**
    Inicia o relogio com 0, e a lista de caixa.
*/
SuperMercado::SuperMercado()
{
    relogio = 0;
    listaDeCaixas = new ListaCircular<Caixa>();
}

/**
    Le o arquivo de parametros, e enquanto o relogio for menor que o tempo de simulacao, 
    verifica se é hora de entrar um cliente no supermercado, ve se é possivel colocar ele em 
    uma fila, caso contrario ele sai, e os custos disso sao computados.
    Percorre a lista de caixas atentendo, se for hora, os clientes. Ao final gera os dados e mostra os resultados. 
*/
void SuperMercado::iniciarSimulacao()
{   if(tipoDeEntrada()){
        requisitarParametros();
    } else {
    lerArquivo();
    }   

    while(this->relogio < tempoDeSimulacao)
    {
        if(this->relogio%tempoChegadaClientes == 0)
        {
            Cliente* novoCliente = new Cliente(this->relogio);
            if(this->naoTemFilaDisponivel()){
                clientesDesistentes++;
                valorDesistentes += novoCliente->getValorTotal()*3;
                delete novoCliente;
                cout << relogio << "\n";

            } else{
                
                if(novoCliente->getTipoCliente()){
                //    cout << "Novo cliente aos "<< relogio << " Procurador de fila menor";
                    this->acharFilaMenor(novoCliente);
                }else{
                //    cout << "Novo cliente aos "<< relogio << " Procurador de fila com menos produtos";
                    this->acharFilaMenosProdutos(novoCliente);
                }
            }
            
        }
        for(int i = 0; i<listaDeCaixas->getTamanho(); i++)
        {   
           
            this->listaDeCaixas->mostra(i)->atendeCliente(relogio);
            //cout<<listaDeCaixas->mostra(i)->qtClientesFila()<< " Clientes na fila de 0 a 3"<<"\n";
        }
        this->relogio++;
    }

    this->gerarDados();
    this->mostrarResultado();
}

/**
    Cria um arquivo e abre para leitura, verifica se foi abertom, apos disso le linha por linha, 
    e inicia os atributos do supermercado conforme cada linha. Ao final fecha o arquivo.
*/
void SuperMercado::lerArquivo()
{
    FILE* arquivo = fopen(_ARQUIVO, "r");   //abre arquivo pra leitura
    if (arquivo == NULL)                    //verifica se conseguiu abrir
    {
        cout << "Arquivo nao lido, fim do programa."<< "\n";
        fclose(arquivo);
        exit(1);
    }
    else
    {
        char linhaLida[100];                    //criar um char[] pra receber as linhas do arquivo
        int cont = 0;
        while (true)
        {
            if(fgets(linhaLida, 100, arquivo) == NULL)  //le a linha
            {
                break;
            }
            if (linhaLida[0] == '#' || linhaLida[0] == '\n' || linhaLida[0] == ' ')
            {
                continue;
            }
            switch (cont)
            {
            case 0:
                nome = string(linhaLida);
                break;
            case 1:
                this->tempoDeSimulacao = atoi(linhaLida)*60*60;
                break;
            case 2:
                this->tempoChegadaClientes = atoi(linhaLida);
                break;
            case 3:
                this->nCaixas = atoi(linhaLida);
                break;
            default:
                char nomeCaixa[50];
                int eficiencia;
                int salario;
                sscanf(linhaLida, "%s %d %d", nomeCaixa, &eficiencia, &salario);
                Caixa *cx = new Caixa(string(nomeCaixa), eficiencia, salario);
                this->listaDeCaixas->adicionaNoInicio(cx);
                break;
            }
            cont += 1;
        }
    }

    fclose(arquivo);
}
/**
    Mostra os resultados da simulação na tela.
*/

void SuperMercado::mostrarResultado(){
    cout << "SuperMercado: " << this->nome << "\n\n";
    cout << "Tempo de simulacao: " << this->tempoDeSimulacao /(60*60) << " hora(s)" << "\n";
    cout << "Tempo medio de chegada de cliente: " << this->tempoChegadaClientes << " segundo(s)" << "\n";
    cout << "Caixas: " << this->nCaixas << "\n\n";

    cout << "Numero de clientes atendidos: " << this->clientesAtendidos << "\n";
    cout << "Numero de clientes desistentes: " << this->clientesDesistentes << "\n\n";

    for(int i = 0; i<this->listaDeCaixas->getTamanho(); i++){
        cout << "Caixa: "<< this->listaDeCaixas->mostra(i)->getId() << "\n";

        cout << "Total de clientes atendidos: " << this->listaDeCaixas->mostra(i)->getClientesAtendidos() << "\n";

        cout << "Faturamento total: " 
        << this->listaDeCaixas->mostra(i)->getFaturamentoTotal() << "\n";

        cout << "Faturamento com descontos: "
        << this->listaDeCaixas->mostra(i)->getFaturamentoMedio() << "\n\n";

    }
        cout << "Faturamento total do supermercado: " << this->faturamentoTotal << "\n";
        cout << "Faturamento com descontos do supermercado: " << this->faturamentoMedio << "\n";

        cout << "Media do faturamento total do supermercado por caixa: " << this->faturamentoTotal/this->nCaixas << "\n";
        cout << "Media do faturamento com descontos do supermercado por caixa: " << this->faturamentoMedio/this->nCaixas << "\n";

        cout << "Valor deixado de ganhar com desistentes: " << this->valorDesistentes << "\n\n\n" << "FIM DE SIMULACAO" << "\n";


}
/**
    Calcula alguns dados da sumilação, feito ao final da mesma.
*/
void SuperMercado::gerarDados()
{
    for(int i = 0; i<listaDeCaixas->getTamanho(); i++)
        {
            this->faturamentoTotal += this->listaDeCaixas->mostra(i)->getFaturamentoTotal();
            this->faturamentoMedio += this->listaDeCaixas->mostra(i)->getFaturamentoMedio();
            this->tempoMedioNaFila += this->listaDeCaixas->mostra(i)->getTempoMedioFila(this->tempoDeSimulacao);
            this->clientesAtendidos += this->listaDeCaixas->mostra(i)->getClientesAtendidos();
        }
    //this->faturamentoMedio -= this->valorDesistentes;
    this->tempoMedioNaFila /= this->nCaixas;

}
/**
    Procura e coloca o cliente na fila com a menor quantidade de clientes.
*/
void SuperMercado::acharFilaMenor(Cliente* cliente)
{
    int menor = 0;
    for(int i = 0; i<listaDeCaixas->getTamanho(); i++){
        if(listaDeCaixas->mostra(i)->qtClientesFila() < listaDeCaixas->mostra(menor)->qtClientesFila())
        {
            menor = i;
        }
    }
       listaDeCaixas->mostra(menor)->addCliente(cliente);
}

/**
    Procura e coloca o cliente na fila com a menor quantidade de produtos.
*/
void SuperMercado::acharFilaMenosProdutos(Cliente* cliente)
{
    int menor = 0;
    for(int i = 0; i < listaDeCaixas->getTamanho(); i++){
        if(listaDeCaixas->mostra(i)->qtProdutosFila() < listaDeCaixas->mostra(menor)->qtProdutosFila())
        {
            menor = i;
        }
    }
    listaDeCaixas->mostra(menor)->addCliente(cliente);

}

/**
    Retorna true se não ha fila com menos de 10 clientes.
*/
bool SuperMercado::naoTemFilaDisponivel(){
    
    for(int i = 0; i < listaDeCaixas->getTamanho(); i++)
    {
        if(listaDeCaixas->mostra(i)->qtClientesFila() < 10){
            return false;
        }
    }
    return true;
}

/**
    Retorna true se o operador desejar inserir os parametros manualmente, false caso queira ler 
    o arquivo de configuração "parametros.dat". 
*/
bool SuperMercado::tipoDeEntrada(){
    cout << "Bem vindo!" << "\n" << "Entre com 1 se deseja ler o arquivo de configuracao." 
    << "\n" << "Entre com 2 se deseja inserir parametros manualmente." << "\n";
    int x;
    cin >> x;

    switch (x)
    {
        case 1:
        return false;

        default:
        return true;
    }
}

void SuperMercado::requisitarParametros(){
    cout << "Entre com o nome do supermercado " << "\n";
    cin >> this->nome;
    cout << "Entre com o tempo de simulacao, em horas" << "\n";
    cin >> this->tempoDeSimulacao;
    cout << "Entre com intervalo de tempo, em segundos, de chegada de cada cliente " << "\n";
    cin >> this->tempoDeSimulacao;
    cout << "Entre com o numero de caixas" << "\n";
    cin >> this->nCaixas;

    for(int i = 0; i<this->nCaixas; i++)
    {   
        cout <<"aaaqqqq" << i;
        char nomeCaixa[50];
        int eficiencia;
        int salario;

        cout << "Entre com o nome do caixa " << i << "\n";
        cin >> nomeCaixa;
        cout << "Entre com a eficiencia do caixa " << i << "\n";
        cin >> eficiencia;
        cout << "Entre com o salario do caixa " << i << "\n";
        cin >> salario;

        Caixa* cx = new Caixa(string(nomeCaixa), eficiencia, salario);
        cout << "Caixa criado com sucessagem" << cx->getId() << "\n";
         cout << "Caixa adicionado com sucessagem" << listaDeCaixas->getTamanho() << "\n";
    
        this->listaDeCaixas->adicionaNoInicio(cx);
        cout << "Caixa adicionado com sucessagem" << listaDeCaixas->getTamanho() << "\n";
        cout << i << "i\n";
        cout << nCaixas << "nCaixas\n";
    }
    cout << "aq";
}


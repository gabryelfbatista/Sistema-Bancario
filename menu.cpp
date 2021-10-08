#include "menu.h"
#include "contabancaria.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include <iostream>
#include <string>

Menu::Menu(){
  int opcao; //variavel pra pegar opcao desejada do menu
  bool opcaoValida = false;
  int numConta=0; //variavel pra pegar o numero da conta que o usuario digitar 
  std::string nomeConta; //apenas para pegar um nome e o usuario adicionar 
  double valor;
  
  //para pegar qual tipo de conta o usuario quer criar 
  int tipoDeConta; 

  //ponteiro de conta para apontar para conta que é retornada quando executamos a funcao procurar conta
  ContaBancaria* ptrConta = 0;  
  ContaBancaria* ptrConta2 = 0;

  Banco meuBanco; //instanciando banco

  do {
    system("cls");

    std::cout << "######################################################################" << std::endl;
    std::cout << "#         BBBBBB      AAA      NN     N   CCCCCC    OOOOOO           #" << std::endl;
    std::cout << "#         B     B    A   A     N  N   N   CC        OO  OO           #" << std::endl;
    std::cout << "#         BBBBBB    AAAAAAA    N   N  N   CC        OO  OO           #" << std::endl;
    std::cout << "#         B     B  A       A   N    N N   CC        OO  OO           #" << std::endl;
    std::cout << "#         BBBBBB  A         A  N     NN   CCCCCC    OOOOOO           #" << std::endl;
    std::cout << "######################################################################" << std::endl;

    std::cout << std::endl;

    std::cout << "1. Criar conta" << std::endl;
    std::cout << "2. Selecionar conta" << std::endl;
    std::cout << "3. Remover conta" << std::endl;
    std::cout << "4. Gerar relatorio" << std::endl;
    std::cout << "5. Finalizar" << std::endl;
    std::cout << std::endl;
    fflush(stdin);
    std::cout << "Digite a opcao desejada: ";
    std::cin >> opcao;
    std::cout << std::endl;

    switch (opcao){
      case (1): //adicionar conta
        std::cout << "Informe o tipo de conta: " << std::endl;
        std::cout << "1. Poupanca " << std::endl;
        std::cout << "2. Corrente " << std::endl;
        std::cin >> tipoDeConta;
        if (tipoDeConta==1){  // se for o tipo 1 e poupanca
          fflush(stdin);
          std::cout << "Informe o numero da conta: ";
          std::cin >> numConta;
          //se a conta nao existir, cria uma nova conta e insere no vetor de contas do banco
          if (meuBanco.procurarConta(numConta)==NULL){
            ContaPoupanca* novaConta = new ContaPoupanca(numConta);
            meuBanco.inserir(novaConta);
            system("PAUSE");
          }else {
              std::cout << "Ja existe uma conta com esse numero" << std::endl;
              system("PAUSE");
            }
        }else {
          if (tipoDeConta==2){ //se for o tipo 2 e conta corrente
            fflush(stdin);
            std::cout << "Informe o numero da conta: ";
            std::cin >> numConta;
            //se a conta nao existir, cria uma nova conta e insere no vetor de contas do banco
            if (meuBanco.procurarConta(numConta)==NULL){
              ContaCorrente* novaConta = new ContaCorrente(numConta);
              meuBanco.inserir(novaConta);
              system("PAUSE");
            }else {
              std::cout << "Ja existe uma conta com esse numero" << std::endl;
              system("PAUSE");
            }
          }else {
            std::cout << "Tipo de conta invalido" << std::endl;
          }
        }
        break;
      case (2): //selecionar conta
        fflush(stdin);
        std::cout << "Informe o numero da conta: ";       //pega o numero da conta
        std::cin >> numConta;                             
        if (meuBanco.procurarConta(numConta)==NULL){       // se nao encontrar, avisa q nao encontrou
          std::cout<< "Conta inexistente" << std::endl;
          system("PAUSE");
        }else {
          std::cout << "Conta encontrada!" << std::endl;    //se encontrar salva no nosso vetor de conta e abre o segundo menu
          ptrConta = meuBanco.procurarConta(numConta);
          int opcao2;
          do {
            system("cls");
            std::cout << "Conta selecionada: " << ptrConta->getNumConta() << std::endl; //so pra mostrar o numero da conta selecionada
            std::cout << std::endl;
            std::cout << "1. Depositar" << std::endl;
            std::cout << "2. Sacar" << std::endl;
            std::cout << "3. Transferir" << std::endl;
            std::cout << "4. Gerar relatorio" << std::endl;
            std::cout << "5. Retornar ao menu anterior" << std::endl;
            std::cout << std::endl;
            std::cout << "Digite a opcao desejada: ";
            std::cin >> opcao2;
            std::cout << std::endl;

            switch(opcao2){
              case 1: //depositar
                std::cout << "Informe o valor do deposito: ";
                std::cin >> valor;
                ptrConta->depositar(valor);
                system("PAUSE");
                break;
              case 2: //sacar
                fflush(stdin);
                std::cout << "Informe o valor do saque: ";
                std::cin >> valor;
                ptrConta->sacar(valor);
                system("PAUSE");
                break;
              case 3: //transferir
                fflush(stdin);
                std::cout << "Informe o valor de transferencia: ";
                std::cin >> valor;
                fflush(stdin);
                std::cout << "Informe o numero da conta para transferencia: ";
                std::cin >> numConta;
                if (meuBanco.procurarConta(numConta)==NULL){ //verifica se existe a conta que deseja transferir
                  std::cout<< "Conta inexistente" << std::endl;
                  system("PAUSE");
                }else {
                  ptrConta2 = meuBanco.procurarConta(numConta);
                  ptrConta->transferir(valor, ptrConta2);
                  system("PAUSE");
                }
                break;
              case 4: //gerar relatorio de uma conta
                ptrConta->mostrarDados();
                system("PAUSE");
                break;
              case 5: //retornar ao menu anterior
                break;
            }
          } while (opcao2!=5);
        }
        break;
      case (3): //remover uma conta
        fflush(stdin);
        std::cout << "Informe o numero da conta: ";
        std::cin >> numConta;
        if (meuBanco.procurarConta(numConta)==NULL){  //verifica se a conta existe antes de remover
          std::cout<< "Conta inexistente" << std::endl;
          system("PAUSE");
        }else {
          ptrConta = meuBanco.procurarConta(numConta);
          meuBanco.remover(ptrConta);
          system("PAUSE");
        }
        break;
      case (4): //gerar relatorio das contas
        meuBanco.mostrarDados();
        system("PAUSE");
        break;
      case (5): //finalizar
        break;
    }; 
  } while (opcao!=5);
  
}

Menu::~Menu(){};
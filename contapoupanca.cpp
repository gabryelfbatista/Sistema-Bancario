#include "contapoupanca.h"
#include <iostream>

ContaPoupanca::ContaPoupanca(int a):ContaBancaria(a){};
ContaPoupanca::~ContaPoupanca(){};


double ContaPoupanca::getLimite() const{
  return this->limite;
}

void ContaPoupanca::sacar(double quantia) {
  double meuLimite = this->getLimite();
  //se a quantidade que vc quer sacar for maior que o saldo + limite ele n permite o saque
  if ((this->saldo)+meuLimite < quantia){
    std::cout << "Saldo insuficiente" << std::endl;
  }else {
    this->saldo = (this->saldo) - quantia;
    //se o saldo for negativo, atualiza o limite disponivel
    if (this->saldo < 0){
      this->limite = 800+this->saldo;
    }
    std::cout << "Saque realizado" << std::endl; 
  }
}

//pega o saldo e atualiza com a quantia que será depositada
void ContaPoupanca::depositar(double quantia) {
  this->saldo = (this->saldo) + quantia;
  std::cout << "Deposito realizado" << std::endl; 
}

//mostra os dados da conta poupanca (inclusive o limite disponivel e limite maximo)
void ContaPoupanca::mostrarDados() const {
  std::cout << "Tipo de conta: Poupanca" << std::endl; 
  std::cout << "Numero da conta: " << this->getNumConta() << std::endl;
  std::cout << "Saldo na conta: " << this->getSaldo() << std::endl;
  std::cout << "Limite disponivel: " << this->getLimite() << std::endl;
}
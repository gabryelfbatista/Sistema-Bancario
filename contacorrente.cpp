#include "contacorrente.h"
#include <iostream>

ContaCorrente::ContaCorrente(int a):ContaBancaria(a){};
ContaCorrente::~ContaCorrente(){};

float ContaCorrente::getTaxaDeOperacao() const{
  return this->taxaDeOperacao;
}

void ContaCorrente::sacar(double valor) {
  //desconto será o tanto que sera descontado em cima do saldo da conta
  double desconto = (this->saldo)*(this->getTaxaDeOperacao());
  //se o saldo for menor que o valor + o desconto, n é possivel realizar o saque, caso contrario ele realiza o saque
  if (this->saldo < valor+desconto){
    std::cout << "Saldo insuficiente" << std::endl;
  }else {
    this->saldo = (this->saldo) - desconto - valor;
    std::cout << "Saque realizado" << std::endl; 
  }
}

//deposita a quantidade, descontando a taxa de operacao
void ContaCorrente::depositar(double valor) {
  double desconto = 0;
  desconto = (this->saldo)*(this->getTaxaDeOperacao());
  this->saldo = (this->saldo) - desconto + valor;
  std::cout << "Deposito realizado" << std::endl; 
}

//mostra os dados da conta corrente
void ContaCorrente::mostrarDados() const {
  std::cout << "Tipo de conta: Corrente" << std::endl; 
  std::cout << "Numero da conta: " << this->getNumConta() << std::endl;
  std::cout << "Saldo na conta: " << this->getSaldo() << std::endl;
  std::cout << "Taxa de operacao: " << this->getTaxaDeOperacao() << std::endl;
}
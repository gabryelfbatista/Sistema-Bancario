#include "contabancaria.h"
#include <iostream>

ContaBancaria::ContaBancaria(int a):numConta(a){};
ContaBancaria::~ContaBancaria(){};

double ContaBancaria::getSaldo() const {
  return this->saldo;
}

int ContaBancaria::getNumConta() const {
  return this->numConta;
}

void ContaBancaria::transferir(double valor, class ContaBancaria* conta) {
  //se o valor da conta atual for menor q o valor n deixa acontecer a transferencia
  if (this->saldo < valor){
    std::cout << "Saldo insuficiente" << std::endl;
  }else{
    this->sacar(valor);
    conta->depositar(valor);
  }
  
}

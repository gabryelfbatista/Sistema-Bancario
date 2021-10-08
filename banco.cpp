#include "banco.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include <iostream>

Banco::Banco(){};
Banco::~Banco(){};

//adiciona no vetor de contas a conta passada
void Banco::inserir(ContaBancaria* obj){
  this->minhasContas.push_back(obj);
  std::cout << "Conta adicionada!" << std::endl;
}

void Banco::remover(ContaBancaria* obj){
  //verifica no vetor se existe uma conta com o msm numero da conta passada e remove do vetor essa
  for (int i=0; i<minhasContas.size();i++){
    if (minhasContas[i]->getNumConta()==obj->getNumConta()){
      this->minhasContas.erase(minhasContas.begin()+i);
      std::cout << "Conta removida!" << std::endl;
      break;
    }
  }
}

ContaBancaria* Banco::procurarConta(int numConta){
  //procura no vetor minhasContas a conta com o numero passado e retorna o objeto se encontrar
  for (int i=0; i<this->minhasContas.size(); i++){
    if (numConta==this->minhasContas[i]->getNumConta()){
      return this->minhasContas[i];
    }
  }
  return (NULL);
}

//executa o mostrar dados de cada conta do vetor de contas
void Banco::mostrarDados() const {
  for (int i=0; i<this->minhasContas.size(); i++){
    minhasContas[i]->mostrarDados();
    std::cout << std::endl;
  }
}



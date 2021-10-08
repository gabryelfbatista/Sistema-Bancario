#ifndef BANCO_H
#define BANCO_H
#include "imprimivel.h"
#include "contabancaria.h"
#include <vector>

class Banco : public Imprimivel {
public:
  Banco();
  ~Banco();
  void inserir(ContaBancaria*);
  void remover(ContaBancaria*);
  ContaBancaria* procurarConta(int);
  void mostrarDados() const ;
protected:
  std::vector<ContaBancaria*> minhasContas;
};

#endif
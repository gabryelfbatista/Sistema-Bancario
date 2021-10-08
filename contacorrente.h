#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "contabancaria.h"

class ContaCorrente : public ContaBancaria{
public:
  ContaCorrente(int);
  ~ContaCorrente();
  float getTaxaDeOperacao() const;
  virtual void sacar(double);
  virtual void depositar(double);
  virtual void mostrarDados() const;
private:
  float taxaDeOperacao = 0.02;
};

#endif
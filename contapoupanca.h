#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "contabancaria.h"
#include "imprimivel.h"

class ContaPoupanca : public ContaBancaria, public Imprimivel {
public:
  ContaPoupanca(int);
  ~ContaPoupanca();
  double getLimite() const;
  virtual void sacar(double);
  virtual void depositar(double);
  virtual void mostrarDados() const;
protected:
  double limite = 800;
};

#endif
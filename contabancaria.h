#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

class ContaBancaria{
public:
  ContaBancaria(int);
  ~ContaBancaria();
  double getSaldo() const;
  int getNumConta() const;
  virtual void mostrarDados() const = 0;
  virtual void sacar(double) = 0;
  virtual void depositar(double)  = 0;
  virtual void transferir(double, ContaBancaria*);
private: 
  int numConta;
protected:
  double saldo = 0;
};

#endif
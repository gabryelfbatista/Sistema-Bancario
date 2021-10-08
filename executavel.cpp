#include "executavel.h"
#include "relatorio.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include "contabancaria.h"
#include <iostream>

Executavel::Executavel(){
  system("cls");
  //instanciando as contas e relatorio
  ContaCorrente* contaCorrente = new ContaCorrente(123);
  ContaPoupanca* contaPoupanca = new ContaPoupanca(1234);
  Relatorio* relatorio = new Relatorio;

  //deposita,saca e gera o relatorio pra conta corrente
  std::cout << "##### CONTA CORRENTE #####" << std::endl;
  contaCorrente->depositar(500);
  contaCorrente->sacar(300);
  relatorio->gerarRelatorio(contaCorrente);
  std::cout << std::endl;

   //deposita,saca e gera o relatorio pra conta poupanca
  std::cout << "##### CONTA POUPANCA #####" << std::endl;
  contaPoupanca->depositar(500);
  contaPoupanca->sacar(700);
  relatorio->gerarRelatorio(contaPoupanca);
  std::cout << std::endl;

  delete contaCorrente;
  delete contaPoupanca;
  delete relatorio;

}

Executavel::~Executavel(){};


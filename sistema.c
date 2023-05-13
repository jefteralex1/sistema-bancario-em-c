#include <stdio.h>

// Define o número máximo de contas que o cliente pode ter
#define MAX_CONTAS 4

// Define os tipos de conta que o cliente pode ter
enum TipoConta {
  CORRENTE,
  SALARIO,
  POUPANCA,
  INVESTIMENTO
};

// Define a estrutura que representa uma conta
struct Conta {
  enum TipoConta tipo;
  double saldo;
};

// Função que verifica se há saldo suficiente em todas as contas antes de liberar o saque
int realizarSaque(struct Conta contas[], int numContas, double valorSaque) {
  // Variável para armazenar o saldo total das contas
  double saldoTotal = 0;

  // Verifica se há saldo suficiente em cada conta
  for (int i = 0; i < numContas; i++) {
    // Verifica se o saldo atual é suficiente para o saque
    if (contas[i].saldo < valorSaque) {
      // Caso não haja saldo suficiente, gera uma mensagem de erro e retorna 0 indicando que o saque não pode ser realizado
      printf("Saldo insuficiente na conta %d\n", contas[i].tipo);
      return 0;
    }
    // Caso haja saldo suficiente, adiciona o saldo atual ao saldo total
    saldoTotal += contas[i].saldo;
  }

  // Verifica se o saldo total é suficiente para o saque
  if (saldoTotal < valorSaque) {
    // Caso não haja saldo suficiente, gera uma mensagem de erro e retorna 0 indicando que o saque não pode ser realizado
    printf("Saldo insuficiente em todas as contas\n");
    return 0;
  }

  // Caso haja saldo suficiente em todas as contas, realiza o saque e retorna 1 indicando que o saque foi realizado com sucesso
  for (int i = 0; i < numContas; i++) {
    contas[i].saldo -= valorSaque;
  }
  printf("Saque de %.2f realizado com sucesso!\n", valorSaque);
  return 1;
}

int main() {
  // Cria um vetor de contas com um exemplo de saldo em cada uma
  struct Conta contas[MAX_CONTAS] = {
    {CORRENTE, 1000.0},
    {SALARIO, 2000.0},
    {POUPANCA, 5000.0},
    {INVESTIMENTO, 10000.0}
  };
  int numContas = MAX_CONTAS;

  // Realiza alguns testes de saque
  realizarSaque(contas, numContas, 3000.0);
  realizarSaque(contas, numContas, 8000.0);
  realizarSaque(contas, numContas, 15000.0);

  return 0;
}

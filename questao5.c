// Questão 5 - Resolução
#include <stdio.h>

// Função: conta a quantidade de caracteres de uma string.
int quantidade_de_caracteres (char *string) {
  int i = 0;
  while (string[i] != '\0') {
    i += 1;  
  }

  return i;
}

int main (void) {
  
  char string[100];
  char invertida[100];
  int i, j;
  
  // Entrada de dados:
  printf("Entre com uma string: ");
  scanf("%[^\n]s",string);
  
  // Processamento de dados: invertendo a string
  int qtd = quantidade_de_caracteres(string); 
  for (i = 0, j = qtd - 1; j >= 0; i++, j--) {
    invertida[i] = string[j];
  }
  invertida[i] = '\0';
  
  // Saída de dados:
  printf("string original.: %s \n",string);
  printf("string invertida: %s \n",invertida);
  return 0;
}

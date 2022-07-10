// Questão 2 - Resolução:
#include <stdio.h>


// verifica se número informado é igual número de fibonacci atual (1 - true, 0 - false)
int verificar (int fibonacci, int x) {
  if (fibonacci == x) {
    return 1;
  } 
  
  return 0;
}

int main (void) {
  int numero = 34; // número informado
  
  int fib = 1, anterior = 0, flag = 0;
   
  if (numero != 0) printf("0, "); // primeiro número de fibonacci

  for (int i = 0; i < numero - 1; i++) {  
    
    if (flag == 0) flag = verificar (fib, numero);
    
    printf("%d, ",fib);
    fib = fib + anterior;
    anterior = fib - anterior;
  } 

  if (flag) printf("\nNúmero informado faz parte da sequência \n");
  else      printf("\nNúmero informado não faz parte da sequencia \n");  

  return 0;
}

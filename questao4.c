// Questão 4 - Resolução
#include <stdio.h>
#include <stdlib.h>
#define NOME_ARQUIVO "file.txt"

/*

  Obs: o formato do arquivo 'file.txt' deve está da seguinte forma 
  
  SP – R$67.836,43
  RJ – R$36.678,66
  MG – R$29.229,88
  ES – R$27.165,48
  Outros – R$19.849,53
 
*/



// Função: responsável por pegar a 'fatia' da string que possui o valor em R$, 
// logo em seguida transforma uma string em ponto flutuante (lembrando que precisamos substituir a ',' por '.'  pois
// o valor está em formato brasileiro).

float pegar_valor(char *linha) {
  int i = 0, j = 0;
  char buffer[100];

  while (linha[i] != '\0') {
    if (linha[i] >= 48 && linha[i] <= 57 || linha[i] == 44) { // ASCII ( [48-49] representa [0 até 9])
      if (linha[i] == ',') buffer[j] = '.';
      else buffer[j] = linha[i];
      j += 1;  
    }
    i += 1;
  }
  buffer[j] = '\0';

  return atof(buffer); // função atof - converte string em ponto flutuante.
}

int main (void) {
  FILE *arquivo;
  char linha[100];
  float valor, soma = 0;
  int i;
  
  // Abrir arquivo
  if (!(arquivo = fopen(NOME_ARQUIVO, "r"))) {
    printf("Erro na abertura de arquivo! \n");
    exit(1);
  }
  
  // Percorrer até final do arquivo, pegando cada 'linha'
  while (1) {
    fgets(linha, 100, arquivo);
    if (feof(arquivo)) {
      break;
    }
    valor = pegar_valor(linha); // obtem valor presente em cada 'linha'
    soma  = soma + valor;       // soma todos os valores presentes no arquivo
  }

  
  fseek(arquivo, 0, SEEK_SET); // volta para 'inicio' do arquivo
  
  char sigla[7];
  while (1) {
    fgets(linha, 100, arquivo);
    if (feof(arquivo)) {
      break;
    }
    valor = pegar_valor(linha);
    
    i = 0;
    while(linha[i] != 32) {
      sigla[i] = linha[i]; i+=1;
    }
    sigla[i] = '\0';
    
    printf("%s - %.2f: %.2f%%\n",sigla, valor, valor * 100.0 / soma); // Saída de dados
  }
  
  fclose(arquivo);
 
  return 0;
}

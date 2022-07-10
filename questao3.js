// Questão 2 - Resolução:

const data = require('./dados.json');  // Lendo arquivo JSON

let soma = 0, cont = 0;
let menor = data[0]["valor"], maior = menor;

for (let i = 0; i < data.length; i++) {
  soma += data[i]["valor"];
  if (data[i]["valor"] == 0) cont += 1; // contabilizando dias com faturamento Zero
}

let media = soma / (30 - cont); // Média, ignorando dias com faturamento Zero

cont = 0;
for (let i = 0; i < data.length; i++) {
  if (data[i]["valor"] > maior) maior = data[i]["valor"];
  if (data[i]["valor"] < menor && data[i]["valor"] != 0) menor = data[i]["valor"];
  if (data[i]["valor"] > media) cont += 1
}


console.log("Menor valor de faturamento: " + menor);
console.log("Maior valor de faturamento: " + maior);
console.log("Números de dias no mês com valor de faturamento superior à média mensal: " + cont);



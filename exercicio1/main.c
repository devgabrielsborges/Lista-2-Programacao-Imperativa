#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"
#include "functions.h"

// Gabriel Souza Borges - github.com/devgabrielsborges - gsb3@poli.br

/*
Considere que uma empresa precisa armazenar os seguintes dados de um cliente:
– Nome completo com no máximo 50 caracteres;
– renda mensal do cliente;
– ano de nascimento;
– possui ou não carro.
• Considerando esta estrutura, escreva um programa que leia os dados de
N clientes e imprima:
– quantos clientes têm renda mensal acima da média;
– quantos clientes têm carro;
– quantos clientes nasceram entre 1960 (inclusive) e 1980 (inclusive).
• Use ponteiros para manipular o vetor de estruturas
*/

int main() {
    bool adicionar_cliente;
    // Inicializando a linked list
    cliente *primeiro_cliente = NULL;
    cliente *ultimo_cliente = NULL;
    
    do{
        cliente *novo_cliente = (cliente *) malloc(sizeof(cliente));
        if(novo_cliente == NULL){
            printf("Erro ao alocar memória para o novo cliente\n");
            return 1;
        }

        printf("Digite o nome do cliente: ");
        scanf("%49s", novo_cliente->nome);

        printf("Digite a renda mensal do cliente: ");
        scanf("%f", &novo_cliente->renda_mensal);

        printf("Digite o ano de nascimento do cliente: ");
        scanf("%d", &novo_cliente->ano_nascimento);

        printf("O cliente possui carro? (1 para sim, 0 para não): ");
        scanf("%d", &novo_cliente->possui_carro);

        // linked list para armazenar os clientes
        novo_cliente->proximo_cliente = NULL;

        if (primeiro_cliente == NULL) {
            primeiro_cliente = novo_cliente;  // head da linked list
        } else {
            ultimo_cliente->proximo_cliente = novo_cliente;  // tail da linked list
        }
        ultimo_cliente = novo_cliente;

        printf("Deseja adicionar outro cliente? (1 para sim, 0 para não): ");
        scanf("%d", &adicionar_cliente);


    } while(adicionar_cliente);

    // Limpando a tela
    limpaTela();
    
    // Printando os resultados
    printf(
        "Quantidade de clientes com renda mensal acima da média: %d\n", 
        clientes_acima_da_renda_mensal_media(primeiro_cliente)
    );
    printf(
        "Quantidade de clientes que possuem carro: %d\n",
         clientes_com_carro(primeiro_cliente)
    );
    printf(
        "Quantidade de clientes que nasceram entre 1960 e 1980: %d\n",
         clientes_entre_1960_e_1980(primeiro_cliente)
    );

}
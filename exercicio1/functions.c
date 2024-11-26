#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void limpaTela() {
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para (Linux/Mac)
    #endif
}

float renda_media(cliente *primeiro_cliente){
    float soma = 0;
    int quantidade_clientes = 0;
    cliente *cliente_atual = primeiro_cliente;

    while(cliente_atual != NULL){
        // Percorrendo a lista de clientes
        soma += cliente_atual->renda_mensal;
        quantidade_clientes++;
        cliente_atual = cliente_atual->proximo_cliente;
    }
    printf("Renda media: %.2f\n", soma / quantidade_clientes);


    return soma / quantidade_clientes;
}

int clientes_com_carro(cliente *primeiro_cliente){
    int quantidade_clientes = 0;
    cliente *cliente_atual = primeiro_cliente;

    while(cliente_atual != NULL){
        // Percorrendo a lista de clientes
        if(cliente_atual->possui_carro){
            quantidade_clientes++;
        }
        cliente_atual = cliente_atual->proximo_cliente;
    }

    return quantidade_clientes;
}
int clientes_acima_da_renda_mensal_media(cliente *primeiro_cliente){
    float media = renda_media(primeiro_cliente);
    int quantidade_clientes = 0;
    cliente *cliente_atual = primeiro_cliente;

    while(cliente_atual != NULL){
        // Percorrendo a lista de clientes
        if(cliente_atual->renda_mensal > media){
            quantidade_clientes++;
        }
        cliente_atual = cliente_atual->proximo_cliente;
    }

    return quantidade_clientes;
}

int clientes_entre_1960_e_1980(cliente *primeiro_cliente){
    int quantidade_clientes = 0;
    cliente *cliente_atual = primeiro_cliente;

    while(cliente_atual != NULL){
        // Percorrendo a lista de clientes
        if(cliente_atual->ano_nascimento >= 1960 && cliente_atual->ano_nascimento <= 1980){
            quantidade_clientes++;
        }
        cliente_atual = cliente_atual->proximo_cliente;
    }

    return quantidade_clientes;
}
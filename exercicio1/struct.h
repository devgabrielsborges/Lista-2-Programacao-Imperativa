#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#define MAX_TAMANHO_NOME 50

typedef struct cliente{
    char nome[MAX_TAMANHO_NOME];
    float renda_mensal;
    int ano_nascimento;
    bool possui_carro;
    // linked list para armazenar os clientes
    struct cliente *proximo_cliente;  // ponteiro para o próximo cliente

} cliente;


#endif
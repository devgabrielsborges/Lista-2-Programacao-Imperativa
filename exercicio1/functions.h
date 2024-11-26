#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"

void limpaTela();
float renda_media(cliente *primeiro_cliente);
int clientes_com_carro(cliente *primeiro_cliente);
int clientes_acima_da_renda_mensal_media(cliente *primeiro_cliente);
int clientes_entre_1960_e_1980(cliente *primeiro_cliente);

#endif
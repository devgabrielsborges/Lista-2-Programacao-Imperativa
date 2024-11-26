#include <stdio.h>
#include <stdlib.h>

# define TAM 100

// Gabriel Souza Borges - github.com/devgabrielsborges - gsb3@poli.br

/*
Escreva um programa que grava um texto qualquer em um
arquivo e, em seguida, conta o número de caracteres do
arquivo

– Use a função rewind(FILE * p) para “rebobinar” o arquivo
*/

int main() {
    FILE *arquivo;
    char texto[TAM];
    

    arquivo = fopen("texto.txt", "w+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);

    fprintf(arquivo, "%s", texto);

    rewind(arquivo);

    int contador = 0;
    while (fgetc(arquivo) != EOF) {
        // Contando ate o final do arquivo
        contador++;
    }

    printf("O arquivo tem %d caracteres\n", contador);

    fclose(arquivo);

    return 0;
}
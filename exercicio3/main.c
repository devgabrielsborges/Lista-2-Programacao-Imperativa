#include <stdio.h>
#include <stdbool.h>

#define MAX_NOME 20

// Gabriel Souza Borges - github.com/devgabrielsborges - gsb3@poli.br

/*
Escreva um programa que grave o nome, 1a nota, 2a nota e
média dos alunos de uma turma em um arquivo. Após a
gravação do arquivo, ele deve ser novamente aberto para listar
os alunos com suas respectivas notas.
*/

int main() {
    FILE *arquivo;
    char nome[MAX_NOME];
    float nota1, nota2, media;

    arquivo = fopen("alunos.txt", "w+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    bool continuar = true;

    while (continuar)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", nome);
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        fprintf(arquivo, "%s %.2f %.2f %.2f\n", nome, nota1, nota2, media);

        printf("Deseja adicionar outro aluno? (1 - sim, 0 - nao): ");
        scanf("%d", &continuar);
    }

    rewind(arquivo);

    while (fscanf(arquivo, "%s %f %f %f", nome, &nota1, &nota2, &media) != EOF) {
        printf("Nome: %s\n", nome);
        printf("Nota 1: %.2f\n", nota1);
        printf("Nota 2: %.2f\n", nota2);
        printf("Media: %.2f\n", media);
    }

    fclose(arquivo);

    return 0;
}
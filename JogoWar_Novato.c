#include <stdio.h>
#include <string.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropa;
};

int main() {
    struct Territorio mapa[5];
    int c;//Variável para limpar o buffer do teclado

        printf("===================================\n");
        printf("         ---  JOGO WAR  ---        \n");
        printf("===================================\n");
        printf("\n");
        printf("Iniciando cadastro dos territórios...\n");
        printf("\n");


    for (int i = 0; i < 5; i++) {

        printf("----- Territorio %d-----\n", i + 1);
        printf("\n");

        printf("Digite o nome do território %d: ", i + 1);
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);

        printf("Digite a cor do Exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropa);
        printf("\n");
        
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\n");

    }

     for (int i = 0; i < 5; i++) {
        printf("\n--- TERRITORIO %d ---\n", i + 1);
        printf("- Nome: %s \n", mapa[i].nome);
        printf("- Dominado por: Exercito %s \n", mapa[i].cor);
        printf("- Quantidade de Tropas: %d \n", mapa[i].tropa);

     }

     return 0;
}

//biblioteca necessária para a implementação do jogo
#include <stdio.h> // Entrada e saída padrão
#include <string.h> // Manipulação de strings
#include <stdlib.h>// Alocação dinâmica de memória e funções utilitárias
#include <time.h> // Funções relacionadas ao tempo

//Definição das estruturas utilizadas no jogo
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

//Função para realizar o ataque entre dois territórios
//utilizei ponteiros para modificar diretamente os territórios envolvidos no ataque
void atacar (struct Territorio *atacante, struct Territorio *defensor) {
    int dado_atacante = (rand() % 6) + 1;  //Gera um número aleatório entre 1 e 6 para o atacante
    int dados_defensor = (rand() % 6) +1; //Gera um número aleatório entre 1 e 6 para o defensor
   
    
    //Exibe os resultados dos dados
    printf("\n--- RESULTADO DO ATAQUE ---\n");
    printf("Território Atacante tirou: %d\n", dado_atacante);
    printf("Território Defensor tirou: %d\n", dados_defensor);
    

    //Determina o vencedor do ataque
    if (dado_atacante > dados_defensor) {
        printf("Resultado ...\n\n");
        printf("VITORIA DO ATACANTE! O território foi conquistado!\n");

        strcpy(defensor->cor, atacante->cor);//usei o ponteiro seta (->) para acessar e modificar o campo cor do defensor

        int tropas_ocupacao = atacante->tropas / 2;
        defensor->tropas = tropas_ocupacao;
        atacante->tropas -= tropas_ocupacao;
    
    } else {
        printf("Resultado ...\n\n");
        printf("DEFENSOR VENCEU! o ataque falhou. \n");
        atacante->tropas = atacante->tropas - 1;
    }
}
//Função para liberar a memória alocada para o mapa
void liberarMemoria(struct Territorio *mapa) {
    free(mapa);
}
  //Usei a função time(NULL) para inicializar a semente do gerador de números aleatórios com o tempo atual, garantindo resultados diferentes a cada execução do programa.
int main() {
    srand(time(NULL));
    struct Territorio *mapa;
    int qtd_territorios;
    int c;//Variável para limpar o buffer do teclado
    

        printf("===================================\n");
        printf("         ---  JOGO WAR  ---        \n");
        printf("===================================\n");
        printf("\n");
        printf("Iniciando cadastro dos territórios...\n");
        printf("\n");
        

        printf("Quantos territórios deseja cadastrar? ");
        scanf("%d", &qtd_territorios);
        while ((c = getchar()) != '\n' && c != EOF);  ///LIMPA O BUFFER DO TECLADO
        printf("\n");

        mapa = (struct Territorio *) calloc(qtd_territorios, sizeof(struct Territorio));  //Aloca memória para o número de territórios especificado

    for (int i = 0; i < qtd_territorios; i++) {

        printf("----- Cadastro do Território %d -----\n", i + 1);
        printf("\n");
        
        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;

        printf("Digite a cor do Exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        while ((c = getchar()) != '\n' && c != EOF);  ///LIMPA O BUFFER DO TECLADO
        printf("\n");

    }
     printf("Iniciando batalha entre territórios...\n");
     printf("\n");

     //Exibe o mapa inicial com os territórios cadastrados
     for (int i = 0; i < qtd_territorios; i++) {
        printf("%d. %s (Exercito: %s) - Tropas: %d\n", i + 1, mapa[i]. nome, mapa[i].cor, mapa[i].tropas);
     }

        int id_atacante, id_defensor;

        printf("\n========================================");
        printf("\n            INICIANDO ATAQUE           \n");
        printf("\n========================================");


        printf("\nInforme o número do território ATACANTE: ");
        scanf("%d", &id_atacante);

        printf("Informe o número do território DEFENSOR: ");
        scanf("%d", &id_defensor);

        if (id_atacante > 0 && id_atacante <= qtd_territorios && id_defensor > 0 && id_defensor <= qtd_territorios) {
            atacar(&mapa[id_atacante - 1], &mapa[id_defensor - 1]);
        
        } else {
            printf("Territórios invalidos!\n");
        }

        printf("\n\n=== MAPA APOS A BATALHA ===\n");
        for (int i =0; i < qtd_territorios; i++) {
            printf("%d. %s (Exercito: %s) - Tropas: %d\n", i + 1, mapa[i]. nome, mapa[i].cor, mapa[i].tropas);
        }

        liberarMemoria(mapa);
        return 0;
        
     }

     

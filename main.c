#include "prontuario.h"

int main() {
    ListaProntuarios lista;
    inicializarLista(&lista); 

    int opcao;
    do {
        printf("\n=== SISTEMA MEDICO ===\n");
        printf("1. Inserir prontuario\n");
        printf("2. Buscar por CPF\n");
        printf("3. Remover prontuario\n");
        printf("4. Listar todos\n");
        printf("5. Sair\n");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer até o fim da linha
            continue;
        }
        getchar();
         

        switch (opcao) {
            case 1: { 
                Prontuario novo;
                lerProntuario(&novo);  

                if (inserirProntuario(&lista, novo)) {
                    printf("Cadastrado com sucesso!\n");
                } else {
                    printf("Erro ao cadastrar!\n");
                }
                break;
            }
            case 2: { 
                char cpf[12];
                printf("\nCPF para busca: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                No* encontrado = buscarProntuario(&lista, cpf);
                if (encontrado) {
                    imprimirProntuario(encontrado->dados);
                } else {
                    printf("Prontuario nao encontrado!\n");
                }
                break;
            }
            case 3: { 
                char cpf[12];
                printf("\nCPF para remover: ");
                fgets(cpf, 12, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                if (removerProntuario(&lista, cpf)) {
                    printf("Removido com sucesso!\n");
                } else {
                    printf("CPF nao encontrado!\n");
                }
                break;
            }
            case 4:
            if (lista.inicio == NULL) {
                printf("Nenhum prontuario cadastrado.\n");
            } else {
                imprimirProntuarios(&lista);
            }
                break;
            case 5:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcaoo invalida!\n");
        }
    } while (opcao != 5);

    No* atual = lista.inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}


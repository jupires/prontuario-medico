#include "prontuario.h"

int main() {
    ListaProntuarios lista;
    inicializarTabela(&lista);  // Inicializa a lista

    int opcao;
    do {
        printf("\n=== SISTEMA MÉDICO ===");
        printf("\n1. Inserir prontuário");
        printf("\n2. Buscar por CPF");
        printf("\n3. Remover prontuário");
        printf("\n4. Listar todos");
        printf("\n5. Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        getchar();  // Consumir o '\n' deixado pelo scanf

        switch (opcao) {
            case 1: { 
                Prontuario novo;
                lerProntuario(&novo);  // Lê os dados do prontuário

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
                fgets(cpf, 12, stdin);
                cpf[strcspn(cpf, "\n")] = '\0';

                No* encontrado = buscarProntuario(&lista, cpf);
                if (encontrado) {
                    imprimirProntuario(encontrado->dados);
                } else {
                    printf("Prontuário não encontrado!\n");
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
                    printf("CPF não encontrado!\n");
                }
                break;
            }
            case 4:
                imprimirProntuarios(&lista);
                break;
            case 5:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    // Liberar a memória alocada para a lista
    No* atual = lista.inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}


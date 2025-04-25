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
        if (scanf("%d", &opcao) != 1) { //le a opção do usuario
            printf("Entrada invalida! Por favor, digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer até o fim da linha
            continue;
        }
        getchar(); // consome o '\n' deixado pelo scanf
         

        switch (opcao) {
            case 1: { //insere novo prontuario
                Prontuario novo;
                lerProntuario(&novo); //coleta dados do novo pront

                if (inserirProntuario(&lista, novo)) {
                    printf("Cadastrado com sucesso!\n");
                } else {
                    printf("Erro ao cadastrar!\n");
                }
                break;
            }
            case 2: { //busca por cpf
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
            case 3: { //remoção por cpf
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
            case 4: //lista todos os pront
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
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5); 

    // libera memoria usada antes de encerrar 
    No* atual = lista.inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}


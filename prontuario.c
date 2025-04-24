#include "prontuario.h"

void inicializarLista(ListaProntuarios* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int inserirProntuario(ListaProntuarios* lista, Prontuario novo) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 0;
    }

    novoNo->dados = novo;
    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
    lista->tamanho++;
    return 1;
}

// Função para buscar um prontuário pela CPF
No* buscarProntuario(ListaProntuarios* lista, const char* cpf) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.cpf, cpf) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Função para remover um prontuário pela CPF
int removerProntuario(ListaProntuarios* lista, const char* cpf) {
    No* anterior = NULL;
    No* atual = lista->inicio;

    while (atual != NULL && strcmp(atual->dados.cpf, cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0;// nao encontrou o cpf

    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    lista->tamanho--;
    return 1;
}

// Função para imprimir todos os prontuários
void imprimirProntuarios(ListaProntuarios* lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    No* atual = lista->inicio;
    printf("\n=== PRONTUARIOS (%d) ===\n", lista->tamanho);

    while (atual != NULL) {
        imprimirProntuario(atual->dados);
        printf("\n\n");
        atual = atual->prox;
    }
}

// Função para imprimir a data
void imprimirData(const char* data) {
    printf("Data: %s\n", data);
}

// Função para imprimir um prontuário
void imprimirProntuario(Prontuario p) {
    printf("\nNome: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("Nascimento: %s\n", p.data_nasc);
    printf("Historico: %s\n", p.historico);
}

// Função para ler a data
void lerData(char* data) {
    printf("Data nascimento (DD/MM/AAAA): ");
    fflush(stdin);  // limpa o buffer
    fgets(data, 11, stdin);
    data[strcspn(data, "\n")] = '\0';
}

// Função para ler os dados de um prontuário
void lerProntuario(Prontuario* p) {
    printf("\nNome: ");
    fgets(p->nome, 100, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(p->cpf, 12, stdin);
    p->cpf[strcspn(p->cpf, "\n")] = '\0';

    lerData(p->data_nasc);

    strcpy(p->historico, "Historico inicial");
}
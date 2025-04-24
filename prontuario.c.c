#include "prontuario.h"

// Função para inicializar a lista
void inicializarTabela(ListaProntuarios* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

// Função para inserir um prontuário na lista
int inserirProntuario(ListaProntuarios* lista, Prontuario novo) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) return 0;

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

    if (atual == NULL) return 0;

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
    printf("\n=== PRONTUÁRIOS (%d) ===\n", lista->tamanho);

    while (atual != NULL) {
        imprimirProntuario(atual->dados);
        printf("-------------------\n");
        atual = atual->prox;
    }
}

// Função para destruir a lista e liberar a memória
void destruir(ListaProntuarios* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
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
    printf("Histórico: %s\n", p.historico);
}

// Função para ler a data
void lerData(char* data) {
    printf("Data nascimento (DD/MM/AAAA): ");
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

    strcpy(p->historico, "Histórico inicial");
}

#include "prontuario.h"

//inicializa a lista
void inicializarLista(ListaProntuarios* lista) {
    lista->inicio = NULL; //inicio lista vazia
    lista->tamanho = 0; // tam em 0
}

// insere novo pront no inicio 
int inserirProntuario(ListaProntuarios* lista, Prontuario novo) {
    No* novoNo = (No*)malloc(sizeof(No)); //alcoa memoria para um no novo
    if (novoNo == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 0;
    }

    novoNo->dados = novo; //armazena os dados 
    novoNo->prox = lista->inicio; // no aponta para o "antigo" inicio
    lista->inicio = novoNo; // atualiza o inicio dad lista apra novo no
    lista->tamanho++; // incrementa o tam da lista
    return 1;
}

// busca prontuario pelo cpf
No* buscarProntuario(ListaProntuarios* lista, const char* cpf) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.cpf, cpf) == 0) { //compara cpf
            return atual;
        }
        atual = atual->prox; // vai para o prox no
    }
    return NULL; //cpf nao encontrado
}

// remove pront com base no cpf
int removerProntuario(ListaProntuarios* lista, const char* cpf) {
    No* anterior = NULL;
    No* atual = lista->inicio;

    while (atual != NULL && strcmp(atual->dados.cpf, cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0;// nao encontrou o cpf
    
    if (anterior == NULL) { //remove no do inicio
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox; //remove nno do meio/final
    }

    free(atual); //libera memoria do no removido
    lista->tamanho--; //atualiza tam da lista
    return 1;
}

// imprimi todos os prontuários
void imprimirProntuarios(ListaProntuarios* lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    No* atual = lista->inicio;
    printf("\n=== PRONTUARIOS (%d) ===\n", lista->tamanho);

    while (atual != NULL) { //percorre a lista e imprime cada prontuario
        imprimirProntuario(atual->dados);
        printf("\n\n");
        atual = atual->prox;
    }
}

// imprime data de nscimento
void imprimirData(const char* data) {
    printf("Data: %s\n", data);
}

// imprime os dados de um prontuário individual
void imprimirProntuario(Prontuario p) {
    printf("\nNome: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("Nascimento: %s\n", p.data_nasc);
    printf("Historico: %s\n", p.historico);
}

// le a data de nascimento
void lerData(char* data) {
    printf("Data nascimento (DD/MM/AAAA): ");
    fflush(stdin);  // limpa o buffer
    fgets(data, 11, stdin);
    data[strcspn(data, "\n")] = '\0';
}

// le dados de um novo pront
void lerProntuario(Prontuario* p) {
    printf("\nNome: ");
    fgets(p->nome, 100, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(p->cpf, 12, stdin);
    p->cpf[strcspn(p->cpf, "\n")] = '\0';

    lerData(p->data_nasc); //le a data de nascimento

    strcpy(p->historico, "Historico inicial"); //inicializa o historico com valor padrao
}
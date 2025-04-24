#ifndef PRONTUARIO_H
#define PRONTUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo Prontuario
typedef struct {
    char nome[100];
    char cpf[12];
    char data_nasc[11];
    char historico[500];
} Prontuario;

// Definição do nó da lista encadeada
typedef struct No {
    Prontuario dados;
    struct No* prox;
} No;

// Definição da estrutura de lista encadeada
typedef struct {
    No* inicio;
    int tamanho;
} ListaProntuarios;

// Funções para manipulação da lista
void inicializarTabela(ListaProntuarios* lista);
int inserirProntuario(ListaProntuarios* lista, Prontuario novo);
No* buscarProntuario(ListaProntuarios* lista, const char* cpf);
int removerProntuario(ListaProntuarios* lista, const char* cpf);
void imprimirProntuarios(ListaProntuarios* lista);
void destruir(ListaProntuarios* lista);

// Funções auxiliares de entrada/saída
void imprimirData(const char* data);
void imprimirProntuario(Prontuario p);
void lerData(char* data);
void lerProntuario(Prontuario* p);

#endif

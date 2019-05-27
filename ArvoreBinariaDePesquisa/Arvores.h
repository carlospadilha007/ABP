#pragma once
#define _CRT_SECURE_NO_WARNINGS

// Estruturas

typedef struct {
	int RA;
	char dataDeNascimento[30];
	char nome[50];
}TipoAluno;

typedef struct no
{
	struct no *esq, *dir;
	TipoAluno item;
}TNo;


//Funções de manipulação
int buscaPai(TNo* ptr, TipoAluno item);
int buscaIrmao(TNo* ptr, TipoAluno item);
void escreveNo(TipoAluno item);
void leNo(TipoAluno* item);
void exibeMenu();

//Funções Padrão
void inicializa(TNo** ptr);
void insere(TNo** ptr, TipoAluno item);
void retira(TNo** ptr, TipoAluno item);
void antecessor(TNo* q, TNo** r);
void sucessor(TNo* q, TNo** r);
void pesquisa(TNo* ptr, TipoAluno item);
void in_ordem(TNo* ptr);
void pre_ordem(TNo* ptr);
void pos_ordem(TNo* ptr);

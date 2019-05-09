#pragma once

// Estruturas

typedef struct {
	int chave;
}TipoItem;

typedef struct
{
	struct no* esq, * dir;
	int chave;
}TNo;


//Funções de manipulação
int buscaPai(TNo* ptr, int chave);
int buscaIrmao(TNo* ptr, int chave);

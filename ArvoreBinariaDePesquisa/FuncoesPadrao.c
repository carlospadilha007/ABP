#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

void inicializa(TNo** ptr) {
	*ptr = NULL;
}

void insere(TNo** ptr, int chave) {
	if (*ptr == NULL) {
		(*ptr) = (TNo*)malloc(sizeof(TNo));
		(*ptr)->esq = NULL;
		(*ptr)->dir = NULL;
		(*ptr)->chave = chave;
	}
	else {
		if (chave < (*ptr)->chave) {
			insere(&(*ptr)->esq, chave);
		}
		else if (chave > (*ptr)->chave) {
			insere(&(*ptr)->dir, chave);
		}
	}
}

void retira(TNo** ptr, int chave) {
	if ((*ptr) == NULL) {
		printf("\nA chave #%d não esta na arvore!", chave);
	}
	else if (chave < (*ptr)->chave) {
		retira(&(*ptr)->esq, chave);
	}
	else if (chave > (*ptr)->chave) {
		retira(&(*ptr)->dir, chave);
	}
	else {
		TNo* aux = *ptr;
		if ((*ptr)->dir == NULL) {
			(*ptr) = (*ptr)->esq;
			free(aux);
		}
		else if ((*ptr)->esq == NULL) {
			(*ptr) = (*ptr)->esq;
			free(aux);
		}
		else {
			antecessor((*ptr), &(*ptr)->esq);
		}
	}
}

void antecessor(TNo* q, TNo** r) {
	if ((*r)->dir != NULL) {
		antecessor(q, &(*r)->dir);
	}
	else {
		q->chave = (*r)->chave;
		q = (*r);
		(*r) = (*r)->esq;
		free(q);
	}
}

void sucessor(TNo* q, TNo** r) {
	if ((*r)->esq != NULL) {
		antecessor(q, &(*r)->esq);
	}
	else {
		q->chave = (*r)->chave;
		q = (*r);
		(*r) = (*r)->dir;
		free(q);
	}
}

void pesquisa(TNo* ptr, int chave) {
	while ((ptr != NULL) && (ptr->chave != chave));
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

void inicializa(TNo** ptr) {
	*ptr = NULL;
}

void insere(TNo** ptr, TipoAluno item) {
	if (*ptr == NULL) {
		(*ptr) = (TNo*)malloc(sizeof(TNo));
		(*ptr)->esq = NULL;
		(*ptr)->dir = NULL;
		(*ptr)->item = item;
	}
	else {
		if (item.RA < (*ptr)->item.RA) {
			insere(&(*ptr)->esq, item);
		}
		else if (item.RA > (*ptr)->item.RA) {
			insere(&(*ptr)->dir, item);
		}
	}
}

void retira(TNo** ptr, TipoAluno item) {
	if ((*ptr) == NULL) {
		printf("\nA chave #%d não esta na arvore!", item.RA);
	}
	else if (item.RA < (*ptr)->item.RA) {
		retira(&(*ptr)->esq, item);
	}
	else if (item.RA > (*ptr)->item.RA) {
		retira(&(*ptr)->dir, item);
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
		q->item = (*r)->item;
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
		q->item = (*r)->item;
		q = (*r);
		(*r) = (*r)->dir;
		free(q);
	}
}

void pesquisa(TNo* ptr, TipoAluno item) {
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (item.RA > ptr->item.RA) {
			ptr = ptr->dir;
		}
		else {
			ptr = ptr->esq;
		}
	}
	if (ptr == NULL) {
		printf("\nA chave #%d não esta na arvore!", item.RA);
	}
	else {
		printf("\nA chave #%d esta na arvore!", item.RA);
	}
}

void in_ordem(TNo* ptr) {
	if (ptr != NULL) {
		in_ordem(ptr->esq);
		escreveNo(ptr->item);
		in_ordem(ptr->dir);
	}
}

void pre_ordem(TNo* ptr) {
	if (ptr != NULL) {
		escreveNo(ptr->item);
		pre_ordem(ptr->esq);
		pre_ordem(ptr->dir);
	}
}

void pos_ordem(TNo* ptr) {
	if (ptr != NULL) {
		pos_ordem(ptr->esq);
		pos_ordem(ptr->dir);
		escreveNo(ptr->item);
	}
}
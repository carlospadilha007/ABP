#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

int buscaPai(TNo* ptr, int chave) {
	TNo* ant;
	if (ptr->chave == chave) {
		return 0;
	}
	while ((ptr != NULL) && (ptr->chave != chave)) {
		if (chave == ptr->chave) {
			return ant->chave;
		}
		else if (chave > ptr->chave) {
			ant = ptr;
			ptr = ptr->dir;
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
		}
	}
	free(ant);
	return -1;
}

int buscaIrmao(TNo* ptr, int chave) {
	TNo* ant;
	int esq, dir;
	esq = dir = 0;
	if (ptr->chave == chave) {
		return 0;
	}
	while ((ptr != NULL) && (ptr->chave != chave)) {
		if (chave > ptr->chave) {
			ant = ptr;
			ptr = ptr->dir;
			esq = 1;
			dir = 0;
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
			dir = 1;
			esq = 0;
		}
	}
	if (esq == 1) {
		if (ant->dir == NULL) {
			return -1;
		}
		else
		{
			ant = ant->dir;
			return ant->chave;
		}
	}
	else {
		if (ant->esq == NULL) {
			return -1;
		}
		else
		{
			ant = ant->esq;
			return ant->chave;
		}
	}
	free(ant);

}
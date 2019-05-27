#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

void buscaPai(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	if (ptr->item.RA == item.RA) {
		printf("\n� a raiz, logo n�o possui pai!");
	}
	ant = ptr;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (item.RA == ptr->item.RA) {
			printf("\nO seu pai � #%d ", ant->item.RA);
			return;
		}
		else if (item.RA > ptr->item.RA) {
			ant = ptr;
			ptr = ptr->dir;
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
		}
	}
	printf("\nN�o esta na arvore!");

}

void buscaIrmao(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	if (ptr->item.RA == item.RA) {
		printf("\nN�o possui irm�os, visto que � a raiz!");
	}
	ant = ptr;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (ptr->item.RA == item.RA) {
			if (ptr->item.RA > item.RA) {
				if (ant->dir == NULL) {
					printf("\nN�o possui irm�os!");
					return;
				}
				else
				{
					printf("\nO seu irm�o �: #%d", ant->dir->item.RA);
					return;
				}
			}
			else {
				if (ant->esq == NULL) {
					printf("\nN�o possui irm�os!");
					return;
				}
				else
				{
					printf("\nO seu irm�o �: #%d", ant->esq->item.RA);
					return;
				}
			}
		}
		if (item.RA > ptr->item.RA) {
			ant = ptr;
			ptr = ptr->dir;
			
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
		}
	}
	printf("N�o esta na arvore!");

}

void escreveNo(TipoAluno item) {
		//printf("\nNome: %s ", item.nome);
		printf("\nRA: %d ", item.RA);
		//printf("\nData de Nascimento: %s ", item.dataDeNascimento);
}
void leNo(TipoAluno* item) {
	fflush(stdin);
	//printf("\nNome: "); fflush(stdin); scanf("%s", &item->nome);
	printf("RA: "); fflush(stdin); scanf("%d", &item->RA);
	//printf("Data de Nascimento: "); fflush(stdin), scanf("%s", &item->dataDeNascimento);
}
void exibeMenu() {
	system("cls");
	printf("0 - Digite para sair");
	printf("\n1 - Inserir novo elememto");
	printf("\n2 - Retirar um elemento");
	printf("\n3 - Pesquisar elemento");
	printf("\n4 - Imprimir via in_orden");
	printf("\n5 - Imprimir via pre_orden");
	printf("\n6 - Imprimir via pos_orden");
	printf("\nSua Op��o: ");
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

int buscaPai(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	if (ptr->item.RA == item.RA) {
		return 0;
	}
	ant = ptr;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (item.RA == ptr->item.RA) {
			return ant->item.RA;
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

	free(ant);
	return -1;
}

int buscaIrmao(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	int esq, dir;
	esq = dir = 0;
	if (ptr->item.RA == item.RA) {
		return 0;
	}
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (item.RA > ptr->item.RA) {
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
			return ant->item.RA;
		}
	}
	else {
		if (ant->esq == NULL) {
			return -1;
		}
		else
		{
			ant = ant->esq;
			return ant->item.RA;
		}
	}
	free(ant);

}

void escreveNo(TipoAluno item) {
		//printf("\nNome: %s ", item.nome);
		printf("\nCodigo: %d ", item.RA);
		/*printf("\nCPF: %d ", item.CPF);
		printf("\nRA: %d ", item.RA);
		printf("\nData de Nascimento: %s ", item.dataDeNascimento);
		printf("\nSexo: %s ", item.sexo);*/
}
void leNo(TipoAluno* item) {
	fflush(stdin);
	//printf("\nNome: "); fflush(stdin); scanf("%s", &item->nome);
	printf("Codigo: "); fflush(stdin); scanf("%d", &item->RA);
	/*printf("CPF: "); fflush(stdin); scanf("%d", &item->CPF);
	printf("RA: "); fflush(stdin); scanf("%d", &item->RA);
	printf("Data de Nascimento: "); fflush(stdin), scanf("%s", &item->dataDeNascimento);
	printf("Sexo: "); fflush(stdin);  scanf("%s", &item->sexo);*/
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
	printf("\nSua Opção: ");
}
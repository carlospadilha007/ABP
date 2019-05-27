#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "Arvores.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	TNo *raiz;
	TipoAluno item;
	int op = 1;
	inicializa(&raiz);
	while (op != 0)
	{
		exibeMenu();
		scanf("%d", &op);
		if (op == 0) {
			break;
		}
		leNo(&item);
		insere(&raiz, item);
	}
	printf("Digite o codigo a ser pesquisado: ");
    fflush(stdin);
	scanf("%d", &item.RA);
	pesquisa(raiz, item);
	pre_ordem(raiz);
    system("pause");
	return 0;
}

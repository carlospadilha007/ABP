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
		switch (op)
		{
		case 1: {
			printf("\nDigite o RA ser Inserido: ");
			leNo(&item);
			insere(&raiz, item);
			break;
		}
		case 2: {
			printf("\nDigite o RA ser retirado: ");
			leNo(&item);
			retira(&raiz, &item);
			break;
		}
		case 3: {
			printf("\nDigite o RA ser pesquisado: ");
			leNo(&item);
			pesquisa(raiz, item);
			break;
		}
		case 4: {
			in_ordem(raiz);
			system("pause");
			break;
		}
		case 5: {
			pre_ordem(raiz);
			system("pause");
			break;
		}
		case 6: {
			pos_ordem(raiz);
			system("pause");
			break;
		}
			default:
				printf("\nO opçãp invalida!");
				break;
		}
	}
    system("pause");
	return 0;
}

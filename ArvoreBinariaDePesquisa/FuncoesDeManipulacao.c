#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

// Busca o pai do elemento pesquisado
void buscaPai(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	if (ptr->item.RA == item.RA) {
		printf("\nÉ a raiz, logo não possui pai!");
	}
	ant = ptr;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		if (item.RA > ptr->item.RA) {
			ant = ptr;
			ptr = ptr->dir;
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
		}
	} 
if (ptr == NULL) { 
	printf("\nNão esta na arvore!");
}
else if (item.RA == ptr->item.RA) {
	printf("\nO seu pai é #%d ", ant->item.RA);
}
	system("pause");
}

// Busca o irmão do elemento pesquisado
void buscaIrmao(TNo* ptr, TipoAluno item) {
	TNo* ant = NULL;
	if (ptr->item.RA == item.RA) {
		printf("\nNão possui irmãos, visto que é a raiz!");
	}
	ant = ptr;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		
		if (item.RA > ptr->item.RA) {
			ant = ptr;
			ptr = ptr->dir;
			
		}
		else {
			ant = ptr;
			ptr = ptr->esq;
		}
	}
	if (ptr == NULL) {
		printf("\nNão esta na arvore!");
	}else if (ptr->item.RA == item.RA) {
		if (item.RA < ant->item.RA  ) {
			if (ant->dir == NULL) {
				printf("\nNão possui irmãos!");
			}
			else
			{
				printf("\nO seu irmão é: #%d", ant->dir->item.RA);
			}
		}
		else {
			if (ant->esq == NULL) {
				printf("\nN�o possui irmãos!");
			}
			else
			{
				printf("\nO seu irmão é: #%d", ant->esq->item.RA);
			}
		}
	}
	else {
		printf("N�o esta na arvore!");
	}
	system("pause");

}

// Escreve os compos da struct aluno
void escreveNo(TipoAluno item) {
		//printf("\nNome: %s\t", item.nome);
		printf("RA: %d\t", item.RA);
		//printf("Data de Nascimento: %s\t", item.dataDeNascimento);
		printf("\n");
}

// Lê os compos da struct aluno
void leNo(TipoAluno* item) {
	fflush(stdin);
	//printf("\nNome: "); fflush(stdin); scanf("%s", &item->nome);
	printf("RA: "); fflush(stdin); scanf("%d", &item->RA);
	//printf("Data de Nascimento: "); fflush(stdin), scanf("%s", &item->dataDeNascimento);
}

// Menu de exibição
void exibeMenu() {
	system("cls");
	printf("0 - Digite para sair");
	printf("\n1 - Inserir novo elemento");
	printf("\n2 - Retirar um elemento");
	printf("\n3 - Pesquisar elemento");
	printf("\n4 - Imprimir via in_orden");
	printf("\n5 - Imprimir via pre_orden");
	printf("\n6 - Imprimir via pos_orden");
	printf("\n7 - Busca pai");
	printf("\n8 - Busca irmão");
	printf("\n9 - Encher arvore");
	printf("\nSua Opção: ");
}

// Menu de impreção
void subMenu() {
	system("cls");
	printf("1 - Imprimir somente ABP");
	printf("\n2 - Imprimir somente AVL");
	printf("\n3 - Imprimir ambas as arvores");
	printf("\nDigite sua opção: ");
}

// Menu principal
void menu(TNo** raiz, TNo** raizAVL) {
	TipoAluno item;
	int subOp, op = 1, contABP = 0, contAVL = 0;
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
			printf("\nDigite os dados a serem inseridos: \n");
			leNo(&item);
			insere(&(*raiz), item);
			insereAVL(&(*raizAVL), item);
			break;
		}
		case 2: {
			printf("\nDigite o RA ser retirado: ");
			leNo(&item);
			retira(&(*raiz), &item);
			retiraAVL(&(*raizAVL), &item);
			break;
		}
		case 3: {
			printf("\nDigite o RA ser pesquisado: ");
			leNo(&item);
			printf("\nABP: ");
			pesquisa(*raiz, item);
			printf("\nAVL: ");
			pesquisa(*raizAVL, item);
			system("pause");
			break;
		}
		case 4: {
			subMenu();
			scanf("%d", &subOp);
			if (subOp == 1) {
				printf("\nArvore ABP: \n");
				in_ordem(*raiz);
			}
			else if (subOp == 2) {
				printf("\nArvore AVL: \n");
				in_ordem(*raizAVL);
			}
			else if (subOp == 3) {
				printf("\nArvore ABP: \n");
				in_ordem(*raiz);
				printf("\n\nArvore AVL: \n");
				in_ordem(*raizAVL);
			}
			else {
				printf("\nOpção inválida!\nRetornando para o menu principal.....");
			}
			system("pause");
			break;
		}
		case 5: {
			subMenu();
			scanf("%d", &subOp);
			if (subOp == 1) {
				printf("\nArvore ABP: \n");
				pre_ordem(*raiz);
			}
			else if (subOp == 2) {
				printf("\nArvore AVL: \n");
				pre_ordem(*raizAVL);
			}
			else if (subOp == 3) {
				printf("\nArvore ABP: \n");
				pre_ordem(*raiz);
				printf("\n\nArvore AVL: \n");
				pre_ordem(*raizAVL);
			}
			else {
				printf("\nOpção inválida!\nRetornando para o menu principal.....");
			}
			system("pause");
			break;
		}
		case 6: {
			subMenu();
			scanf("%d", &subOp);
			if (subOp == 1) {
				printf("\nArvore ABP: \n");
				pos_ordem(*raiz);
			}
			else if (subOp == 2) {
				printf("\nArvore AVL: \n");
				pos_ordem(*raizAVL);
			}
			else if (subOp == 3) {
				printf("\nArvore ABP: \n");
				pos_ordem(*raiz);
				printf("\n\nArvore AVL: \n");
				pos_ordem(*raizAVL);
			}
			else {
				printf("\nOpção inválida!\nRetornando para o menu principal.....");
			}
			system("pause");
			break;
		}
		case 7: {
			leNo(&item);
			buscaPai(*raiz, item);
			break;
		} case 8: {
			leNo(&item);
			buscaIrmao(*raiz, item);
			break;
		} case 9: {
			encheArvore(raiz, raizAVL);
            break;
		}
		default:
			printf("\nOpção inválida!\nRetornando para o menu principal.....");
			system("pause");
			break;
		}
	}
}

// Enche a arvore com os dados do arquivo
void encheArvore(TNo **raiz, TNo **raizAVL) {
	TipoAluno item;
	FILE* file;
	file = fopen("Entrada.dat", "r");
	if (file == NULL) {
		printf("ERRO, o arquivo não pode ser aberto!\n");
		system("pause");
		return;
	}
	while (!feof(file))
	{
		fscanf(file,"%d %s %s", &item.RA, &item.nome, &item.dataDeNascimento);
		insere(&(*raiz), item);
		insereAVL(&(*raizAVL), item);
	}
}

// Menu de escolha do sucessor antecessor
void menuAntecessorSucessor() {
	printf("\n1 - Utilizar antecessor");
	printf("\n2 - Utilizar sucessor");
}

// Função que cria os arquivos
void criaArquivo() {
	FILE* file;
	file = fopen("Entrada.dat", "w");
	fclose(file);
}
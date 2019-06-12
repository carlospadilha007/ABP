#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"

// Incializa as arvores
void inicializa(TNo** ptr) {
	*ptr = NULL;
}

// Insere elementos na ABP
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

// Retira os elementos na ABP
void retira(TNo** ptr, TipoAluno *item) {
	if ((*ptr) == NULL) {
		printf("\nA chave #%d n�o esta na arvore!", item->RA);
	}
	else if (item->RA < (*ptr)->item.RA) {
		retira(&(*ptr)->esq, item);
	}
	else if (item->RA > (*ptr)->item.RA) {
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
			int op = 0;
			while (op != 1 && op != 2){
				menuAntecessorSucessor();
				scanf("%d", &op);
			}
			if (op == 1) {
				antecessor((*ptr), &(*ptr)->esq);
			}
			else {
				sucessor((*ptr), &(*ptr)->esq);
			}

		}
	}
}

// Busca o antecessor (filho mais a direita da esquerda)
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

// Busca o sucessor (filho mais a esquerda da direita)
void sucessor(TNo* q, TNo** r) {
	if ((*r)->esq != NULL) {
		sucessor(q, &(*r)->esq);
	}
	else {
		q->item = (*r)->item;
		q = (*r);
		(*r) = (*r)->dir;
		free(q);
	}
}

// Pesquisa os elementos e retorna se o elemento se encontra e o numero de buscas
void pesquisa(TNo* ptr, TipoAluno item) {
	int cont = 0;
	while ((ptr != NULL) && (ptr->item.RA != item.RA)) {
		cont++;
		if (item.RA > ptr->item.RA) {
			ptr = ptr->dir;
		}
		else {
			ptr = ptr->esq;
		}
	}
	if (ptr == NULL) {
		printf("\nA chave #%d n�o esta na arvore!", item.RA);
	}
	else {
		printf("\nA chave #%d esta na arvore!", item.RA);
	}
	printf("\nO numero de compara��es feitas foi  %d\n", cont);
	system("pause");
}

// Algoritmo que imprimi respectivamente: filho esq, raiz e filho dir
void in_ordem(TNo* ptr) {
	if (ptr != NULL) {
		in_ordem(ptr->esq);
		escreveNo(ptr->item);
		in_ordem(ptr->dir);
	}
}

// Algoritmo que imprimi respectivamente: raiz, filho esq e filho dir
void pre_ordem(TNo* ptr) {
	if (ptr != NULL) {
		escreveNo(ptr->item);
		pre_ordem(ptr->esq);
		pre_ordem(ptr->dir);
	}
}

// Algoritmo que imprimi respectivamente: filho esq, filho dir e raiz
void pos_ordem(TNo* ptr) {
	if (ptr != NULL) {
		pos_ordem(ptr->esq);
		pos_ordem(ptr->dir);
		escreveNo(ptr->item);
	}
}

// Funções Padrões da AVL

// Insere Os dados na arvore AVL
void insereAVL(TNo **ptr, TipoAluno item) {
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
	// Parte do rotacionamento
	int FB = altura((*ptr)->dir) - altura((*ptr)->esq); // calculo do fator de balanceamento (fb) da raiz da subarvore
	if (FB == 2) {
                    int FBF = altura((*ptr)->dir->dir) - altura((*ptr)->dir->esq); // calculo do fb  do filho
                    if (FBF == 1) // rotação simples caso o filho tenha um fb igual a da raiz da subarvore
                            rotacaoEsq(ptr);
                    else if (FBF == -1) { // rotação dupla caso o filho tenha um fb diferente a da raiz da subarvore
                            rotacaoDir(&(*ptr)->dir);
                            rotacaoEsq(ptr);
                    }
	}
	else if (FB == -2) {
                    int FBF = altura((*ptr)->esq->dir) - altura((*ptr)->esq->esq); // calculo do fb  do filho
                    if (FBF == 1) { // rotação dupla caso o filho tenha um fb diferente a da raiz da subarvore
                            rotacaoEsq(&(*ptr)->esq);
                            rotacaoDir(ptr);
                    }
                    else if (FBF == -1) { // rotação simples caso o filho tenha um fb igual a da raiz da subarvore
                            rotacaoDir(ptr);
                    }
	}
}

// Retira os elementos da avl
void retiraAVL(TNo **ptr, TipoAluno *item) {
	if ((*ptr) == NULL) {
		printf("\nA chave #%d n�o esta na arvore!", item->RA);
	}
	else if (item->RA < (*ptr)->item.RA) {
		retiraAVL(&(*ptr)->esq, item);
	}
	else if (item->RA > (*ptr)->item.RA) {
		retiraAVL(&(*ptr)->dir, item);
	}
	else {
		TNo* aux = *ptr;
		if ((*ptr)->dir == NULL) {
			(*ptr) = (*ptr)->esq;
			free(aux);
		}
		else if ((*ptr)->esq == NULL) {
			(*ptr) = (*ptr)->dir;
			free(aux);
		}
		else {
			int op = 0;
			while (op != 1 && op != 2) {
				menuAntecessorSucessor();
				scanf("%d", &op);
			}
			if (op == 1) {
				antecessor((*ptr), &(*ptr)->esq);
			}
			else {
				sucessor((*ptr), &(*ptr)->esq);
			}
		}
	}
	//Rebalanceamento
	if ((*ptr) != NULL) {
		int FB = altura((*ptr)->dir) - altura((*ptr)->esq); // calculo do fator de balanceamento (fb) da raiz da subarvore
		if (FB == 2) {
				int FBF = altura((*ptr)->dir->dir) - altura((*ptr)->dir->esq); // calculo do fb  do lado aposto da subarvore ao item excluido
			
				if (FBF == 1 || FBF == 0) // rotação simples caso o filho analisado tenha um fb igual a zero ou ao fb da raiz da subarvore
					rotacaoEsq(ptr);
				else if (FBF == -1) { // rotação dupla caso o filho analisado tenha um fb de sinal oposto ao fb da raiz da subarvore
					rotacaoDir(&(*ptr)->dir);
					rotacaoEsq(ptr);
				}
		}
		else if (FB == -2) {
				int FBF = altura((*ptr)->esq->dir) - altura((*ptr)->esq->esq); // calculo do fb  do lado aposto da subarvore ao item excluido
				if (FBF == -1 || FBF == 0) { // rotação simples caso o filho analisado tenha um fb igual a zero ou ao fb da raiz da subarvore
					rotacaoDir(ptr);
				}
				else if (FBF == 1){ // rotação dupla caso o filho analisado tenha um fb de sinal oposto ao fb da raiz da subarvore
					rotacaoEsq(&(*ptr)->esq);
					rotacaoDir(ptr);
				}
		}
	}
}

// Calcula a altura da subarvore
int altura(TNo* ptr) {
	if (ptr == NULL){
		return -1;
	}
	else {
		int he = altura(ptr->esq);
		int hd = altura(ptr->dir);
		if (he < hd)
			return hd + 1;
		else return he + 1;
	}
}

// Algoritmo de rotação que rotaciona a subarvore para a direita
void rotacaoDir(TNo** ptr) {
	TNo *q, *temp;
	q = (*ptr)->esq;
	temp = q->dir;
	q->dir = (*ptr);
	(*ptr)->esq = temp;
	(*ptr) = q;
}
// Algoritmo de rotação que rotaciona a subarvore para a esquerda
void rotacaoEsq(TNo** ptr) {
	TNo *q, *temp;
	q = (*ptr)->dir;
	temp = q->esq;
	q->esq = (*ptr);
	(*ptr)->dir = temp;
	(*ptr) = q;
}
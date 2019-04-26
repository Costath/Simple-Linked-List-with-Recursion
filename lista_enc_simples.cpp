/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include "lista_enc_simples.h"

Lista* inicializar(){
	
	return NULL;
}

Lista* insereInicio(Lista* L, int dado){		//Insere no inicio da lista o elemento informado e retorna o ponteiro criado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = dado;
	novo->prox = L;
	novo->anterior = NULL;
	
	return  novo;
}

Lista* insereFim(Lista* L, int dado){		//Insere no fim da lista o elemento informado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
		
	novo->info = dado;
	novo->prox = NULL;
	
	if(L == NULL){
		
		novo->anterior = NULL;
		
		return novo;		//Retorna o ponteiro criado caso seja o primeiro elemento a ser inserido na lista.
	}else{
		
		Lista* P = L;
		
		while(P->prox != NULL){
			P = P->prox;
		}
		
		P->prox = novo;
		novo->anterior = P;
		
		return L;		//Retorna o próprio L caso a lista já contenha outros elementos.
	}
}

void mostrar(Lista* L){		//Mostra os elementos da lista de forma recursiva.
	
	if(L != NULL){
		printf("%d\t", L->info);
		mostrar(L->prox);
	}else{
		printf("\n\n");

	}
}

int mostrarInicio(Lista* L){		//Retorna o primeiro elemento da lista.
	
	return L->info;
}

int mostrarFim(Lista* L){		//Retorna o último elemento da lista.
	
	Lista* P = L;
	while(P->prox != NULL){
		P = P->prox;
	}
	
	return P->info;
}

bool vazia(Lista* L){		//Retorna 'true' se a lista estiver vazia.
	
	if(L == NULL){
		
		return true;
	}else{
		
		return false;
	}
}

bool buscar(Lista* L, int dado){		//Retorna 'true' se determinado elemento estiver na lista.
	
	Lista* P = L;
	
	for(Lista* P = L; P != NULL; P = P->prox){
		if(P->info == dado){
			
			return true;
		}
	}
	
	return false;
}

Lista* retira(Lista* L, int dado){		//Retira determinado elemento da lista de forma recursiva.
	
	if(vazia(L)){
		printf("Objeto não encontrado na lista.\n");
		return L;
	}
	
	if(L->info == dado){
		Lista* P = L;
		L = L->prox;
		free(P);
		printf("Elemento |%d| retirado da lista.\n");
	}else{
		L->prox = retira(L->prox, dado);
	}
	return L;	
}

int tamanho(Lista* L){		//Verifica e retorna o tamanho da lista.
	int size = 0;
	
	for(Lista* P = L; P != NULL; P = P->prox){
		
		size++;
	}
	
	return size;
}

void liberar(Lista* L){		//Libera, de forma recursiva, a memória alocada, caso tenha alguma.
	
	if(!vazia(L)){
		liberar(L->prox);
		free(L);
	}
	
}




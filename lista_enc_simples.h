/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include <stdio.h>
#include <stdlib.h>

struct lista {
	int info;
	struct lista* prox;
	struct lista* anterior;
};

typedef struct lista Lista;

Lista* inicializar();
Lista* insereInicio(Lista* L, int dado);
Lista* insereFim(Lista* L, int dado);
void mostrar(Lista* L);
int mostrarInicio(Lista* L);
int mostrarFim(Lista* L);
bool vazia(Lista* L);
bool buscar(Lista* L, int dado);
Lista* retira(Lista* L, int dado);
int tamanho(Lista* L);
void liberar(Lista* L);

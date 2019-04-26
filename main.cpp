/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include "lista_enc_simples.h"
#include <locale.h>

int main() {
setlocale(LC_ALL, "");
	
	system("title Lista encadeada simples");
	
	int funcao, elemento;
	Lista* L;
	L = inicializar();
	
	menu:
	
	printf("==Lista encadeada simples==\n\n");
	printf("Selecione a fun��o desejada:\n");
	printf("1 - Insere inicio\n");
	printf("2 - Insere fim\n");
	printf("3 - Mostrar\n");
	printf("4 - Mostrar inicio\n");
	printf("5 - Mostrar fim\n");
	printf("6 - Vazia\n");
	printf("7 - Busca\n");
	printf("8 - Retira\n");
	printf("9 - Tamanho\n");
	printf("0 - Sair\n\n");
	
	scanf("%d", &funcao);
	
	switch(funcao){			//Direciona para a fun��o requisitada no menu acima.
		case(1):		//Insere no inicio da lista o elemento informado.
			printf("\nInforme o elemento inteiro a ser inserido no inicio: ");
			scanf("%d", &elemento);
			
			L = insereInicio(L, elemento);
			
			system("cls");
		break;
		case(2):		//Insere no fim da lista o elemento informado.
			printf("\nInforme o elemento inteiro a ser inserido no fim: ");
			scanf("%d", &elemento);
			
			L = insereFim(L, elemento);
			
			system("cls");
		break;
		case(3):		//Mostra os elementos da lista.
			if(!vazia(L)){
				
				printf("\nLista:\n\n");
				
				mostrar(L);
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(4):		//Mostra o primeiro elemento da lista.
			if(!vazia(L)){
				
				printf("\nO primeiro elemento da lista �: %d\n", mostrarInicio(L));
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(5):		//Mostra o �ltimo elemento da lista.
			if(!vazia(L)){
				
				printf("\n\nO �ltimo elemento da lista �: %d\n", mostrarFim(L));
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
			
		break;
		case(6):		//Informa se a lista est� vazia.
			if(vazia(L)){
				
				printf("\nA lista est� vazia.\n");
			}else{
				
				printf("\nA lista n�o est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(7):		//Informa se determinado elemento est� na lista.
			if(!vazia(L)){
				printf("\nInforme o elemento a ser buscado: ");
				scanf("%d", &elemento);
				
				if(buscar(L, elemento)){
					
					printf("\nO elemento est� presente na lista.\n");
				}else{
					
					printf("\nO elemento n�o est� presente na lista.\n");
				}
			}else{
				printf("\nA lista est� vazia. N�o � poss�vel realizar buscas.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(8):		//Retira determinado elemento da lista.
			if(!vazia(L)){
				
				printf("\n\nInforme o elemento a ser retirado: ");
				scanf("%d", &elemento);
				
				L = retira(L, elemento);
				system("pause");
				system("cls");
			}else{
				
				printf("\nA lista est� vazia.\n");
				system("pause");
				system("cls");
			}
			
		break;
		case(9):		//Verifica e informa o tamanho da lista.
			printf("\nO tamanho da lista �: %d\n\n", tamanho(L));
			
			system("pause");
			system("cls");
		break;
		case(0):		//Libera a mem�ria alocada, caso tenha alguma, e encerra o programa.
			liberar(L);
				
			printf("\nObrigado!\n");
			
			return 0;
		break;
	}
	
	goto menu;		//Mant�m no menu enquanto n�o for selecionada a op��o "sair".
	
}

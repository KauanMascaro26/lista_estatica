#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define TAMANHO_MAX 100 

typedef struct {
    int elementos[TAMANHO_MAX];
    int tamanho;
} ListaEstatica;

ListaEstatica criarListaEstatica() {
    ListaEstatica lista;
    lista.tamanho = 0;
    return lista;
}

void inserirListaEstatica(ListaEstatica *lista, int elemento) {
    if (lista->tamanho < TAMANHO_MAX) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
        printf("Elemento %d inserido na lista.\n", elemento);
    } else {
        printf("Erro: Lista estática cheia, não é possível inserir mais elementos.\n");
    }
}

void imprimirListaEstatica(ListaEstatica lista) {
	int i;
    printf("Lista Estática: ");
    if (lista.tamanho == 0) {
        printf("lista vazia\n");
    } else {
        for (i = 0; i < lista.tamanho; i++) {
            printf("%d ", lista.elementos[i]);
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    ListaEstatica lista = criarListaEstatica();
    int elemento, continuar;

    do {
        printf("Digite o elemento a ser inserido na lista estática: ");
        scanf("%d", &elemento);
        inserirListaEstatica(&lista, elemento);

        printf("Deseja inserir mais elementos? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
    } while (continuar != 0);

    imprimirListaEstatica(lista);

    return 0;
}

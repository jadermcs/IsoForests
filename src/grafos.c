#include <stdio.h>
#define TOTALVERTICES 32


typedef struct item{
	int grau;
	struct item* prox;
}ITEM;

ITEM lista[TOTALVERTICES + 1];

void Imprimir(ITEM *lista);
void Inserir_Aresta(ITEM *lista, int a, int b);

int main() {
    int i, a, b;
    char codigoa, codigob, codigoc, espaco;
    FILE *fp;
    fp = fopen("bbbb.txt","r+");
    if (!fp) {
        printf("Erro ao abrir o arquivo \n");
        return 0;
    }
    // Inicialização da lista.
    for(i = 1; i < TOTALVERTICES + 1; i++){
        lista[i].grau = 0;
        lista[i].prox = NULL;
    }
    while(!feof(fp)) {
        // leitura dos vertices (a,b) - passagem para a função Inserir_Aresta.
        fscanf(fp, "%d", &a);
        fscanf(fp, "%d %d %d", &codigoa, &codigob, &codigoc); // Lê espaço - espaço
        fscanf(fp, "%d", &b);
        /* getchar();
        printf("bbbb\n");
        getchar(); */
        codigob = 40;
        while(codigob != '\n') {
            // printf("b1: %d\n", b);
            // getchar();
            fscanf(fp, "%c", &codigob);
            // printf("codigob: %c", codigob);
            // getchar();
            if(codigob != '\n') {
                // printf("aa\n");
                Inserir_Aresta(lista,a,b);
                Inserir_Aresta(lista,b,a);
                fscanf(fp, "%c %d", &espaco, &b);
                printf("b2: %d\n", b);
                getchar();
                if(feof(fp))
                    codigob ='\n';
            }
        }
    }
    fclose(fp);
    Imprimir(lista);
    getchar();
    return 0;
}

void Imprimir(ITEM *lista) {
    int i;
    ITEM * tmp;
    for(i = 1; i < TOTALVERTICES + 1; i++) {
        tmp = lista[i].prox;
        printf("%2d: (%d) ==>", i, lista[i].grau);
        while (tmp != NULL) {
            printf("%d  ", tmp->grau);
            tmp = tmp->prox;
        }
    printf("\n");
    }
}

void Inserir_Aresta(ITEM *lista, int a, int b) {
    ITEM *aux;
    ITEM *tmp;

    aux = (ITEM*) malloc((int)sizeof(ITEM));    //retorno de um ponteiro genérico.
    aux->grau = b;
    aux->prox = NULL;

    lista[a].grau++;
    if(lista[a].prox == NULL) // Caso a lista estiver vazia - Insere.
        lista[a].prox = aux;
    else {
        tmp = lista[a].prox;
        aux->prox = tmp;
        lista[a].prox = aux;
    }
    /* else	{ Inserir aresta ordenada
    tmp = lista[a].prox;
    if (tmp->campo > b) { //insere como primeiro da lista
      aux->prox = tmp;
      lista[a].prox = aux;
    } 		          //insere os vértices ordenados
    else if (tmp->prox == NULL) {
      aux->prox = tmp->prox;
      tmp->prox = aux;
    }
    else {
      while((tmp->prox != NULL) &&(tmp->prox->campo < b))
	tmp = tmp->prox;
      aux->prox = tmp->prox;
      tmp->prox = aux;
    }
  } */
}

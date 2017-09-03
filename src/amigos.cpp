#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define TOTALVERTICES 49

using namespace std;

struct lista {
    int idaluno;
    lista * prox;
};

struct llista {
    int idaluno;
    int qtamigos = 0;
    lista * prox;
};

llista * grafo = new llista[TOTALVERTICES];

void cria_adj(int, string);
void print_grafo();
void print_desc();

int main() {
    ifstream infile("amigos.txt");
    string line;
    //cria lista adjacente lendo linha por linha
    for (int i = 0; i < TOTALVERTICES; i++) {
        getline(infile, line);
        cria_adj(i, line);
    }
    //printa grafo
    print_grafo();
    //printa ids em ordem descrecente por grau
    print_desc();
    return 0;
}

void cria_adj(int i, string line) {
    istringstream ss(line);
    int elem;
    lista * amigo;
    ss >> grafo[i].idaluno;

    while(ss >> elem) {
        grafo[i].qtamigos++;
        amigo = new lista;
        amigo->idaluno = elem;
        amigo->prox = grafo[i].prox;
        grafo[i].prox = amigo;
    }
}

void print_grafo() {
    lista * amigo;
    for (int i = 0; i < TOTALVERTICES; ++i) {
        cout << "(" << grafo[i].idaluno << ") ";
        amigo = new lista;
        amigo = grafo[i].prox;
        while (amigo != NULL) {
            cout << amigo->idaluno << ",";
            amigo = amigo->prox;
        }
        cout << endl;
    }
}

int *array;
int cmp(const void *x, const void *y) {
    int ix = *(int *)x;
    int iy = *(int *)y;
    return array[ix] > array[iy] ? -1 : array[ix] < array[iy];
}

void print_desc() {
    int keys[TOTALVERTICES];
    int values[TOTALVERTICES];

    for (int i = 0; i < TOTALVERTICES; ++i) {
        keys[i] = i;
        values[i] = grafo[i].qtamigos;
    }

    array = values;
    qsort(keys, TOTALVERTICES, sizeof(*keys), cmp);

    for (const int &key: keys) {
        cout << grafo[key].idaluno << "  ";
        cout << grafo[key].qtamigos << endl;
    }
}

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#define TOTALVERTICES 49
#define PESOMIN 5
typedef long long ll;

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

vector<ll> v, ne;
llista * grafo = new llista[TOTALVERTICES];

void cria_adj(int, string);
void print_grafo();
void print_desc();
void bron_kerbosch(ll, ll, ll);

int main() {
    ifstream infile("amigos.txt");
    string line;
    lista * amigo;
    //cria lista adjacente lendo linha por linha
    for (int i = 0; i < TOTALVERTICES; i++) {
        getline(infile, line);
        cria_adj(i, line);
    }
    //printa grafo
    print_grafo();
    //printa ids em ordem descrecente por grau
    print_desc();
    //cliques do grafo maiores que 5
    ne.resize(TOTALVERTICES, 0);

    for (int i = 0; i < TOTALVERTICES; ++i) {
        amigo = grafo[i].prox;
        while (amigo != NULL) {
            ne[i] |= (1LL << amigo->idaluno);
            amigo = amigo->prox;
        }
    }
    bron_kerbosch(0LL, ~0LL, 0LL);
    for (int i = 0; i < v.size(); i ++) cout << v[i] << endl;
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

void bron_kerbosch(ll R, ll P, ll X){
    if ((P == 0LL) && (X == 0LL)) {
        v.push_back(R);
        return;
    }
    int u = 0;
    for (; u < TOTALVERTICES; u++)
        if ((P|X) & (1LL << u))
            break;
    for (int i = 0; i < TOTALVERTICES; i ++)
        if ((P&~ne[u]) & (1LL << i)){
            bron_kerbosch(R | (1LL << i), P & ne[i], X & ne[i]);
            P -= (1LL << i);
            X |= (1LL << i);
        }
}

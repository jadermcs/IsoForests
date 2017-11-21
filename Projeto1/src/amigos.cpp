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
    lista *prox;
};

struct llista {
    int idaluno;
    int qtamigos = 0;
    lista *prox;
};
int n = TOTALVERTICES;
vector<ll> v, ne;
llista * grafo = new llista[TOTALVERTICES];

void cria_adj(int, string);
void print_grafo();
void print_desc();
void bron_kerbosch(ll, ll, ll);
void debitmask(ll);

int main() {
    ifstream infile("amigos.txt");
    string line;
    lista *amigo;
    //cria lista adjacente lendo linha por linha
    for (int i = 0; i < TOTALVERTICES; i++) {
        getline(infile, line);
        cria_adj(i, line);
    }
    //printa grafo
    cout << "LISTA DE ADJACENCIAS" << endl;
    print_grafo();
    //printa ids em ordem descrecente por grau
    cout << "ORDEM DESCRECENTE POR GRAU" << endl;
    print_desc();
    //cliques do grafo maiores que 5
    cout << "CLIQUES" << endl;
    ne.resize(TOTALVERTICES, 0);
    //bitmask para operacoes de conjunto
    //cria uma palavra de 64bits para armazenar o conjunto em que o indice de cada
    //elemento corresponde a sua posição ex: 1001001 = {7,4,1}
    for (int i = 0; i < TOTALVERTICES; ++i) {
        if (!grafo[i].qtamigos)
            continue;
        amigo = grafo[i].prox;
        while (amigo != NULL) {
            ne[i] |= (1LL << (amigo->idaluno -1));
            amigo = amigo->prox;
        }
    }
    //utiliza do Bron-Kerbosch com operações binarias simulando
    //operacoes de conjunto para achar cliques no grafico e salva no vetor v
    bron_kerbosch(0, ~0LL, 0);
    //desfaz o bitmask aplicado gerando o respectivo valor em decimal
    //e retorno o clique em forma legivel de v
    for (int i = 0; i < int(v.size()); i ++)
        debitmask(v[i]);
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



void bron_kerbosch(ll r, ll p, ll x){
    if ((p == 0LL) && (x == 0LL)) {
        v.push_back(r);
        return;
    }
    int u = 0;
    for (; u < n; u ++)
        if ( (p|x) & (1LL << u) )
            break;
    for (int i = 0; i < n; i ++)
        if ( (p&~ne[u]) & (1LL << i) ){
            bron_kerbosch(r | (1LL << i), p & ne[i], x & ne[i]);
            p -= (1LL << i);
            x |= (1LL << i);
        }
 }

void debitmask(ll setc) {
    vector<int> clique;
    for (int i = 0; i < TOTALVERTICES; ++i) {
        if (((~setc | 1LL) & (setc)) == 1LL)
            clique.push_back(i+1);
        setc >>= 1;
    }
    if (clique.size() > 4) {
        cout << "{";
        for (auto i = clique.begin(); i != clique.end()-1; ++i)
            cout << *i << ",";
        cout << clique.back() << "}\n";
    }
}

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define TOTALVERTICES 39

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
void printa_grafo();

int main(int argc, char *argv[]) {
    ifstream infile ("amigos.txt");
    string line;

    for (int i = 0; i < TOTALVERTICES; i++) {
        getline(infile, line);
        cria_adj(i, line);
    }
    printa_grafo();
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

void printa_grafo() {
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

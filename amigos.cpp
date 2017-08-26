#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lista{
    int aluno;
    lista *prox_amigo;
};


struct vertice {
    int aluno; //numero do aluno
    int qt_amigos = 0; //quantidade de amigos
    vertice *ant_aluno;
    vertice *prox_aluno;
    lista amigos;
};


int main(int argc, char *argv[])
{
    ifstream infile ("amigos.txt");
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    return 0;
}

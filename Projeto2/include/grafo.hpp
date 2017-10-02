#ifndef PROJETO2HPP
#define PROJETO2HPP

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#define INFINITO -10000000

using namespace std;

class Grafo {
  int V; // número de vértices

  // ponteiro um array contendo as listas de adjacências
  list< pair<int, int> > * adj;
public:
  Grafo(int V);
  void addAresta(int v1, int v2, int custo);
  void topSortUtil(int v, bool visited[], stack<int> &Stack);
  void topSort();
  void dijkstra(int orig, int dest);
};

#endif

#ifndef PROJETO2HPP
#define PROJETO2HPP

#include <iostream>
#include <list>
#include <queue>
#define INFINITO -10000000

using namespace std;

class Grafo {
  int V; // número de vértices

  // ponteiro um array contendo as listas de adjacências
  list<pair<int, int>> * adj;
public:
  Grafo(int V);
  void addAresta(int v1, int v2, int custo);
  void dijkstra(int orig, int dest);
  void printPath(int parent[], int j);
  void printSolution(int dist[], int n, int parent[]);
};

#endif

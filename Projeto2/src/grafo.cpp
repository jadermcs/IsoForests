// Implementação do algoritmo de Dijkstra
// Fonte para apoio: https://gist.github.com/marcoscastro/d4e0df5b134c2cd63cf2
#include "grafo.hpp"
#include <fstream>


// construtor
Grafo::Grafo(int V) {
  this->V = V; // atribui o número de vértices
  adj = new list<pair<int, int> >[V];
} /* cria as listas onde cada lista é uma lista de pairs
 onde cada pair é formado pelo vértice destino e o custo */


// adiciona uma aresta ao grafo de v1 à v2
void Grafo::addAresta(int v1, int v2, int custo) {
  adj[v1].push_back(make_pair(v2, custo));
}

// algoritmo de Dijkstra
void Grafo::dijkstra(int orig, int dest) {
  // vetor de distâncias
  int dist[V];
  
  int parent[V];
  parent[0] = -1;
/*  vetor de visitados serve para caso o vértice já tenha sido
 expandido (visitado), não expandir mais 
*/
  
  int visitados[V]; // fila de prioridades de pair (distancia, vértice)
  priority_queue < pair<int, int>,
  vector<pair<int, int> >, greater<pair<int, int> > > pq;
  
// inicia o vetor de distâncias e visitados
  for(int i = 0; i < V; i++) {
    dist[i] = INFINITO;
    visitados[i] = false;
  }
  
// a distância de orig para orig é 0
  dist[orig] = 0;
  
// insere na fila
  pq.push(make_pair(dist[orig], orig));
  
// loop do algoritmo
  while(!pq.empty()) {
    pair<int, int> p = pq.top(); // extrai o pair do topo
    int u = p.second; // obtém o vértice do pair
    pq.pop(); // remove da fila
    // verifica se o vértice não foi expandido
    if(visitados[u] == false) {
      // marca como visitado
      visitados[u] = true;
      list<pair<int, int> >::iterator it;
      // percorre os vértices "v" adjacentes de "u"
      for(it = adj[u].begin(); it != adj[u].end(); it++) {
	// obtém o vértice adjacente e o custo da aresta
	int v = it->first;
	int custo_aresta = it->second;
	// relaxamento (u, v)
	if(dist[v] < (dist[u] + custo_aresta)) {
	  // atualiza a distância de "v" e insere na fila
	  dist[v] = dist[u] + custo_aresta;
	  pq.push(make_pair(dist[v], v));
	  parent[v] = u;
	}
      }
    }
  }
  printSolution(dist, dest, parent);
}

void Grafo::printPath(int parent[], int j) {
  // Base Case : If j is source
    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

void Grafo::printSolution(int dist[], int n, int parent[]) {
    int src = 0;
    printf("Vertex\t  Distance\t\tPath");
    printf("\n%d -> %d \t\t %d\t\t%d ", src, n, dist[n], src);
    printPath(parent, n);
    // for (int i = 1; i < V; i++) {
    //     printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
    //     printPath(parent, i);
    // }
}

int main() {
  int v1, v2, custo, nvertices;
  string line;
  ifstream infile("disciplinas.txt");
  infile >> nvertices;

  Grafo g(nvertices);
  while (infile >> v1 >> v2 >> custo) {
      g.addAresta(v1, v2, custo);
  }
  g.dijkstra(0, 4);

  return 0;
}

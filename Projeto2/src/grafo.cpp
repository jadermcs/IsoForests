#include "grafo.hpp"

using namespace std;

Grafo::Grafo(int V) {
  this->V = V;
  adj = new list< pair<int, int> >[V];
}

void Grafo::addAresta(int v1, int v2, int custo) {
  adj[v1].push_back(make_pair(v2, custo));
}

void Grafo::topSortUtil(int v, bool visited[], stack<int> &Stack) {
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list< pair<int,int> >::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[(*i).first])
            topSortUtil((*i).first, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

void Grafo::topSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}


int main() {
  int nvert, i, j, weight;
  ifstream infile("disciplinas.txt");
  infile >> nvert;
  Grafo g(nvert);
  while (infile >> i >> j >> weight) {
    g.addAresta(i, j, weight);
  }

  cout << "Following is a Topological Sort of "
           "the given graph n" << endl;
  g.topSort();
  cout << endl;
  return 0;
}

// referencias:
// http://www.geeksforgeeks.org/topological-sorting/

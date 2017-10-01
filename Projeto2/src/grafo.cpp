#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int nvert, i, j, weight;
  fstream infile("disciplinas.txt");
  infile >> nvert;
  int b[nvert][nvert] = {0};
  while (infile >> i >> j >> weight) {
    b[i][j] = weight;
  }
  for (int i = 0; i < nvert; ++i) {
    for (int j = 0;  j < nvert; ++ j) {
      for (int k = 0; k < nvert; ++k) {
	if ((b[i][k] + b[k][j] > b[i][j]) || (b[i][j] == 0)) {
	    b[i][j] = b[i][k] + b[k][j];
	}
      }
    }
  }

  int maxi=0, maxj=0, maxw=0;
  for (int i = 0; i < nvert; ++i) {
    for (int j = 0; j < nvert; ++j) {
      if (b[i][j] > maxw) {
	maxi = i; maxj = j;
	maxw = b[i][j];
      }
    }
  }
  cout << maxw << endl;
  cout << maxi << " " << maxj << endl;
}

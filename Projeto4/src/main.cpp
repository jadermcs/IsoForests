#include "isof.h"



void findParty(){
  string party;
  float totalValue = 0;
  cin >> party;
  transform(party.begin(), party.end(),party.begin(), ::toupper);

  for(int i = 0; i < (long) GRAPH.first.size();i++){
    if(party.compare(GRAPH.first[i].party) == 0){
      cout << i+1 << " - " << GRAPH.first[i].name << " / " << GRAPH.first[i].state << " / " \
          << GRAPH.first[i].party << endl;
      for(int j = 0; j < (long) GRAPH.first[i].gastos.size();j++){
	cout << "\t-" << GRAPH.first[i].gastos[j].tipoT << " na empresa " \
        << GRAPH.first[i].gastos[j].empresa.name << " / " << GRAPH.first[i].gastos[j].empresa.id \
        << ": " << endl;
	for(int k = 0; k < (long) GRAPH.first[i].gastos[j].transac.size();k++){
	  cout << "\t\t- " << GRAPH.first[i].gastos[j].transac[k].first << "  R$" \
          << GRAPH.first[i].gastos[j].transac[k].second << endl;
	  totalValue += GRAPH.first[i].gastos[j].transac[k].second;
	}
      }
    }

  }

  cout << endl << endl << ">>>> GASTOS TOTAIS: R$" << fixed << setprecision(2) << totalValue << endl;


}


void printAnomalies(){
  createCommunities();

  calcAnomalies();


}

void calcAnomalies(){
  long long md, N, sum, dp, cost, big = 0.0, low = 9999999999,
    var = 0.0, total = 0.0;

  for(auto& key : COM) total += key.second;

  cout << "No total foram gastos R$ " << total << " reais" << endl;

  for(int i = 0; i < (long long) GRAPH.first.size();i++)
    {
      N = (long long) GRAPH.first[i].gastos.size();
      sum = COM[GRAPH.first[i].name];
      md = sum/N;
      var = big = 0.0;
      low = 9999999999;
      for(int j = 0; j < (long long) GRAPH.first[i].gastos.size();j++){
	for (int k = 0; k < (long long) GRAPH.first[i].gastos[j].transac.size(); ++k)
	  {
	    cost = GRAPH.first[i].gastos[j].transac[k].second;

	    if(cost > big) big = cost;
	    else if(cost < low) low = cost;

	    var += (pow(cost - md, 2.0))/N;
	    dp = sqrt(var);
	  }
      }

      cout << GRAPH.first[i].name << " desvio padrão de " << dp << " com média de " << md << endl;
      if(low == 9999999999) low = big;
      cout << "O maior gasto foi de " << big << " e o menor de " <<  low << endl;
    }
}

void createCommunities(){
  float sum;
  for(int i = 0; i < (long long) GRAPH.first.size();i++){
    sum = 0;
    for(int j = 0; j < (long long) GRAPH.first[i].gastos.size();j++){
      for(int k = 0; k < (long long) GRAPH.first[i].gastos[j].transac.size();k++){
        sum += GRAPH.first[i].gastos[j].transac[k].second;
      }
    }
    COM[GRAPH.first[i].name] = sum;
    cout << GRAPH.first[i].name << " gastou no total R$ " << sum << " reais " << " em " \
        << GRAPH.first[i].gastos.size() << " empresas" << endl;
  }
}

void printGrafo(){
  for(int i = 0; i < (long long) GRAPH.first.size();i++){
    cout << i+1 << " - " << GRAPH.first[i].name << " / " << GRAPH.first[i].state \
        << " / " << GRAPH.first[i].party << endl;
    for(int j = 0; j < (long long) GRAPH.first[i].gastos.size();j++){
      cout << "\t-" << GRAPH.first[i].gastos[j].tipoT << " na empresa " \
          << GRAPH.first[i].gastos[j].empresa.name << " / " << GRAPH.first[i].gastos[j].empresa.id << ": " << endl;
      for(int k = 0; k < (long long) GRAPH.first[i].gastos[j].transac.size();k++){
	cout << "\t\t- " << GRAPH.first[i].gastos[j].transac[k].first << "  R$" \
        << GRAPH.first[i].gastos[j].transac[k].second << endl;
      }
    }
  }


}

void printdVertex(){
  for(int i = 0; i < (long long) GRAPH.first.size();i++){
    cout << i+1 << " - " << GRAPH.first[i].name << " " << GRAPH.first[i].state << " " << GRAPH.first[i].party << endl;
  }

}

void printcVertex(){
  for(int i = 0; i < (long long) GRAPH.second.size();i++){
    cout << i+1 << " - " << GRAPH.second[i].name << " " << GRAPH.second[i].id << endl;
  }
}

int edgeExistence(string r_desc, string nome, int d_index){

  for(int i = 0; i < (long long) GRAPH.first[d_index].gastos.size();i++){
    if(GRAPH.first[d_index].gastos[i].tipoT == r_desc && GRAPH.first[d_index].gastos[i].empresa.name == nome){
      return i;
    }
  }

  return -1;
}

int nameExistence(int deputyOrCompany, string name){
  if(deputyOrCompany == 0){
    for(int i = 0; i < (long long) GRAPH.first.size();i++){
      if(GRAPH.first[i].name.compare(name) == 0){
	return i;
      }
    }
  } else {
    for(int i = 0; i < (long long) GRAPH.second.size();i++){
      if(GRAPH.second[i].name.compare(name) == 0){
	return i;
      }
    }
  }

  return -1;
}

int add_dVertex(string d_name, string d_state, string d_party){
  int indexOfNode;

  indexOfNode = nameExistence(0, d_name);
  if(indexOfNode == -1){
    struct dVertex adding;
    adding.name = d_name;
    adding.state = d_state;
    adding.party = d_party;
    GRAPH.first.push_back(adding);
    indexOfNode = GRAPH.first.size()-1;
  }

  return indexOfNode;

}

int add_cVertex(string c_name, string c_id){
  int indexOfNode;

  indexOfNode = nameExistence(1, c_name);

  if(indexOfNode == -1){
    struct cVertex adding;
    adding.name = c_name;
    adding.id = c_id;
    GRAPH.second.push_back(adding);
    indexOfNode = GRAPH.first.size()-1;
  }

  return indexOfNode;
}

void add_rEdge(string r_desc, string r_date, float r_value, int dVertex, int cVertex){
  int indexOfNode;

  indexOfNode = edgeExistence(r_desc, GRAPH.second[cVertex].name, dVertex);

  if(indexOfNode == -1){
    struct rEdge edge;
    edge.tipoT = r_desc;
    edge.transac.push_back(make_pair(r_date, r_value));
    edge.empresa = GRAPH.second[cVertex];
    GRAPH.first[dVertex].gastos.push_back(edge);
  } else {
    GRAPH.first[dVertex].gastos[indexOfNode].transac.push_back(make_pair(r_date, r_value));
  }

}

int readFile(){
  FILE *pF;
  float r_value;
  int d_index, c_index;
  char d_name[500], d_state[500], d_party[500], c_name[500], c_id[500], r_date[500], r_desc[500];
  string sd_name, sd_state, sd_party, sc_name, sc_id, sr_date, sr_desc;

  pF = fopen("dirty_deputies.txt", "r");

  if(pF == NULL){
    printf("Error on open the file.\n");
    return -1;
  }

  while (fscanf(pF, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n", d_name, d_state, d_party, r_desc, c_name, c_id, r_date, &r_value) != EOF){
    if(r_value < 0){
      r_value = r_value * -1;
    }
    sd_name = d_name; sd_state = d_state; sc_name = c_name;
    sr_date = r_date; sr_desc = r_desc; sc_id = c_id; sd_party = d_party;

    d_index = add_dVertex(sd_name, sd_state, sd_party);
    c_index = add_cVertex(sc_name, sc_id);
    add_rEdge(sr_desc, sr_date, r_value, d_index, c_index);

  }

  fclose(pF);

  return 0;

}

int main(){
  readFile();
  printAnomalies();
  printf("\nGrafo: \n\n\n\n");
  printGrafo();

  return 0;
}

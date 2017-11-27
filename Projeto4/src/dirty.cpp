/** @file dirty.cpp
 *  @brief Main file.
 *
 *  This file contains all the functions and variables
 *  to fully execute the fourth project of TAG 2017/1.
 *
 *  @author Dayanne Fernandes da Cunha 13/0107191
 *  @author Renato Avellar Nobre 15/0146698
 *  @bug No bug known.
 */

#include "dirty.inl"


/**
 * Displays the help screen
 *
 * @return void
 */

void findParty(){
  string party;
  float totalValue = 0;
  cin >> party;
  transform(party.begin(), party.end(),party.begin(), ::toupper);

  for(int i = 0; i < GRAPH.first.size();i++){
    if(party.compare(GRAPH.first[i].party) == 0){
      cout << i+1 << " - " << GRAPH.first[i].name << " / " << GRAPH.first[i].state << " / " << GRAPH.first[i].party << endl;
      /*print company vertex and edge name*/
      for(int j = 0; j < GRAPH.first[i].gastos.size();j++){
	cout << "\t-" << GRAPH.first[i].gastos[j].tipoT << " na empresa " << GRAPH.first[i].gastos[j].empresa.name << " / " << GRAPH.first[i].gastos[j].empresa.id << ": " << endl;
	/*print edge values*/
	for(int k = 0; k < GRAPH.first[i].gastos[j].transac.size();k++){
	  cout << "\t\t- " << GRAPH.first[i].gastos[j].transac[k].first << "  R$" << GRAPH.first[i].gastos[j].transac[k].second << endl;
	  totalValue += GRAPH.first[i].gastos[j].transac[k].second;
	}
      }
    }

  }

  cout << endl << endl << ">>>> GASTOS TOTAIS: R$" << fixed << setprecision(2) << totalValue << endl;

  
}

/**
 * Print all state expanses given a input
 *
 * @return void
 */
void findState(){
  string state;
  float totalValue = 0;
  cin >> state;
  transform(state.begin(), state.end(),state.begin(), ::toupper);

  for(int i = 0; i < GRAPH.first.size();i++){
    if(state.compare(GRAPH.first[i].state) == 0){
      cout << i+1 << " - " << GRAPH.first[i].name << " / " << GRAPH.first[i].state << " / " << GRAPH.first[i].party << endl;
      /*print company vertex and edge name*/
      for(int j = 0; j < GRAPH.first[i].gastos.size();j++){
	cout << "\t-" << GRAPH.first[i].gastos[j].tipoT << " na empresa " << GRAPH.first[i].gastos[j].empresa.name << " / " << GRAPH.first[i].gastos[j].empresa.id << ": " << endl;
	/*print edge values*/
	for(int k = 0; k < GRAPH.first[i].gastos[j].transac.size();k++){
	  cout << "\t\t- " << GRAPH.first[i].gastos[j].transac[k].first << "  R$" << GRAPH.first[i].gastos[j].transac[k].second << endl;
	  totalValue += GRAPH.first[i].gastos[j].transac[k].second;
	}
      }
    }
  }

  cout << endl << endl << ">>>> GASTOS TOTAIS: R$" << fixed << setprecision(2) << totalValue << endl;

   
}

/**
 * Print all expanses from a deputy
 *
 * @return void
 */
void findDeputy(){
  int id;
  float totalValue = 0;

  cin >> id;

  cout << "\tNOME: " << GRAPH.first[id-1].name << endl;

  for(int j = 0; j < GRAPH.first[id-1].gastos.size();j++){
    cout << "\t-" << GRAPH.first[id-1].gastos[j].tipoT << " na empresa " << GRAPH.first[id-1].gastos[j].empresa.name << " / " << GRAPH.first[id-1].gastos[j].empresa.id << ": " << endl;
    /*print edge values*/
    for(int k = 0; k < GRAPH.first[id-1].gastos[j].transac.size();k++){
      cout << "\t\t- " << GRAPH.first[id-1].gastos[j].transac[k].first << "  R$" << GRAPH.first[id-1].gastos[j].transac[k].second << endl;
      totalValue += GRAPH.first[id-1].gastos[j].transac[k].second;
    }
  }

  cout << endl << endl << ">>>> GASTOS TOTAIS: R$" << fixed << setprecision(2) <<totalValue << endl;

   
}

/**
 * Process what is the user's choice of the search interface
 *  and call the respective method
 *
 * @return void
 */

void printAnomalies(){
  createCommunities();

  calcAnomalies();

   
}

void calcAnomalies(){
  long long md, N, sum, dp, cost, big = 0.0, low = 9999999999,
    var = 0.0, total = 0.0;

  for(auto& key : COM) total += key.second;

  cout << "No total foram gastos R$ " << total << " reais" << endl;

  for(int i = 0; i < GRAPH.first.size();i++)
    {
      N = GRAPH.first[i].gastos.size();
      sum = COM[GRAPH.first[i].name];
      md = sum/N;
      var = big = 0.0;
      low = 9999999999;
      for(int j = 0; j < GRAPH.first[i].gastos.size();j++){
	for (int k = 0; k < GRAPH.first[i].gastos[j].transac.size(); ++k)
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
  for(int i = 0; i < GRAPH.first.size();i++){
    sum = 0;
    for(int j = 0; j < GRAPH.first[i].gastos.size();j++){
      for(int k = 0; k < GRAPH.first[i].gastos[j].transac.size();k++){
        sum += GRAPH.first[i].gastos[j].transac[k].second;
      }
    }
    COM[GRAPH.first[i].name] = sum;
    cout << GRAPH.first[i].name << " gastou no total R$ " << sum << " reais " << " em " << GRAPH.first[i].gastos.size() << " empresas" << endl;
  }
}

/**
 *  Print the Graph in the following format
 *  1 - DEPUTY_NAME / DEPUTY_STATE / DEPUTY_PARTY
 *      - TYPE_OF_EXPANSE AT THE COMPANY COMPANY_NAME / COMPANY_ID:
 *            - EXPANSE_DATE R$EXPANSE_VALUE
 *
 * @return void
 */
void printGrafo(){
  /*print deputy vertex*/
  for(int i = 0; i < GRAPH.first.size();i++){
    cout << i+1 << " - " << GRAPH.first[i].name << " / " << GRAPH.first[i].state << " / " << GRAPH.first[i].party << endl;
    /*print company vertex and edge name*/
    for(int j = 0; j < GRAPH.first[i].gastos.size();j++){
      cout << "\t-" << GRAPH.first[i].gastos[j].tipoT << " na empresa " << GRAPH.first[i].gastos[j].empresa.name << " / " << GRAPH.first[i].gastos[j].empresa.id << ": " << endl;
      /*print edge values*/
      for(int k = 0; k < GRAPH.first[i].gastos[j].transac.size();k++){
	cout << "\t\t- " << GRAPH.first[i].gastos[j].transac[k].first << "  R$" << GRAPH.first[i].gastos[j].transac[k].second << endl;
      }
    }
  }

   
}

/**
 *  Print Deputies vertexes as a list of name / state / party
 *
 * @return void
 */
void printdVertex(){
  for(int i = 0; i < GRAPH.first.size();i++){
    cout << i+1 << " - " << GRAPH.first[i].name << " " << GRAPH.first[i].state << " " << GRAPH.first[i].party << endl;
  }

   
}

/**
 *  Print company vertexes as a list of name and id
 *
 * @return void
 */
void printcVertex(){
  for(int i = 0; i < GRAPH.second.size();i++){
    cout << i+1 << " - " << GRAPH.second[i].name << " " << GRAPH.second[i].id << endl;
  }
}

/**
 * Look for the existence of a edge.
 *
 *  @param r_desc the name of the edge being looked
 *  @param nome the name of the company vertex
 *  @param d_index the index of the deputy
 *
 * @return int i represents the index of the edge being looked
 * or -1 representing that there is no such edge
 */
int edgeExistence(string r_desc, string nome, int d_index){

  for(int i = 0; i < GRAPH.first[d_index].gastos.size();i++){
    if(GRAPH.first[d_index].gastos[i].tipoT == r_desc && GRAPH.first[d_index].gastos[i].empresa.name == nome){
      return i;
    }
  }

  return -1;
}

/**
 *  Look for the existence of a vertex.
 *
 *  @param deputyOrCompany int value representing if it is a deputy or
 *      company being looked
 *  @param name string the name of the deputy or company
 *
 * @return int i represents the index of the vertex being looked
 * or -1 representing that there is no such vertex
 */
int nameExistence(int deputyOrCompany, string name){
  if(deputyOrCompany == 0){
    for(int i = 0; i < GRAPH.first.size();i++){
      if(GRAPH.first[i].name.compare(name) == 0){
	return i;
      }
    }
  } else {
    for(int i = 0; i < GRAPH.second.size();i++){
      if(GRAPH.second[i].name.compare(name) == 0){
	return i;
      }
    }
  }

  return -1;
}

/**
 * Add a deputy vertex on the graph
 *
 *  @param r_desc the name of the edge being looked
 *  @param nome the name of the company vertex
 *  @param d_index the index of the deputy
 *
 * @return int indexOfNode represents the index of the vertex
 */
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

/**
 * Add a company vertex on the graph
 *
 *  @param r_desc the name of the edge being looked
 *  @param nome the name of the company vertex
 *  @param d_index the index of the deputy
 *
 * @return int indexOfNode represents the index of the vertex
 */
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

/**
 * Create an edge between a given deputy vertex and a company vertex
 *
 *  @param r_desc the name of the expanse of edge
 *  @param r_date the date of the expanse
 *  @param r_value the value of the expanse
 *  @param dVertex the index of the deputy vertex
 *  @param cVertex the index of the company vertex
 *
 * @return int 0 represents good exit, -1 represents bad exit
 */
void add_rEdge(string r_desc, string r_date, float r_value, int dVertex, int cVertex){
  int indexOfNode;

  indexOfNode = edgeExistence(r_desc, GRAPH.second[cVertex].name, dVertex);

  /* If expanse type edge does not exist, create one for it*/
  if(indexOfNode == -1){
    struct rEdge edge;
    edge.tipoT = r_desc;
    edge.transac.push_back(make_pair(r_date, r_value));
    edge.empresa = GRAPH.second[cVertex];
    GRAPH.first[dVertex].gastos.push_back(edge);
    /* Else, put the date and value of the expanse in the correspondent edge */
  } else {
    GRAPH.first[dVertex].gastos[indexOfNode].transac.push_back(make_pair(r_date, r_value));
  }

}



/**
 * Read the text file and create the GRAPH.
 *
 * @return int 0 represents good exit, -1 represents bad exit
 */
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


/**
 * Main function.
 *  Reads and loads basic data, then executes all main functionalities
 *  of the program.
 *
 * @return int 0 represents good exit, -1 represents bad exit
 */
int main(){
  readFile();
  printAnomalies();
  

  return 0;
}

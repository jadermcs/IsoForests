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
 * Clears the terminal screen
 *
 * @return void
 */
void clear(){
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

/**
 * Information message to guide the user to press any key to continue using the
 *  system
 *
 * @return void
 */
void pressToContinue(){
    cout << endl << "\t    Aperte <QUALQUER TECLA> para voltar ao menu.    ";
    getchar();
    getchar();
}

/**
 * Displays the help screen
 *
 * @return void
 */
void displayHelpUI(){
    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t- Quarto projeto da matéria de Teoria e Aplicação de Grafos -" << endl;
    cout << "\t- (TAG) do semestre de 2017/1. Feito por Dayanne Fernandes  -" << endl;
    cout << "\t- e Renato Nobre. Matrículas 13/0107191 e 15/0146698        -" << endl;
    cout << "\t- respectivamente.                                          -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- O trabalho implementa um grafo contendo informacoes de    -" << endl;
    cout << "\t- gastos de parlamentares, e tem como objetivo encontrar    -" << endl;
    cout << "\t- anomalias em tais gastos. A opção 1 mosta as anomalias    -" << endl;
    cout << "\t- encontradas pelo nosso algoritmo; a opção 2 realiza uma   -" << endl;
    cout << "\t- busca pelos parlamentares, utilizando seu identificador   -" << endl;
    cout << "\t- ou busca todos os parlamentares de um certo estado ou     -" << endl;
    cout << "\t- partido, e realizando a soma dos gastos. Opção 3 mostra   -" << endl;
    cout << "\t- todos os parlamentares, com seus respectivos indicadores  -" << endl;
    cout << "\t- e informações de partido e estado. Opção 4 mostra todas   -" << endl;
    cout << "\t- as empresas envolvidas com os gastos. Opção 5 mostra o    -" << endl;
    cout << "\t- grafo completo.                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;

    pressToContinue();
}


/**
 * Displays the search user interface of the project
 *
 * @return void
 */
void searchUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-----------------------Search Menu---------------------------" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- 1. Listar deputado por identificador                      -" << endl;
    cout << "\t- 2. Listar deputados por sigla do estado                   -" << endl;
    cout << "\t- 3. Listar deputados por sigla do partido                  -" << endl;
    cout << "\t- 4. Sair                                                   -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\t>>> ";
}


/**
 * Displays the loading user interface of the project
 *
 * @return void
 */
void loadingUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                      Carregando ...                       -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-            Pode demorar em média 1 minuto                 -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
}


/**
 * Displays the main user interface of the project
 *
 * @return void
 */
void displayUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- 1. Realizar busca por anomalias                           -" << endl;
    cout << "\t- 2. Busca Personalizada                                    -" << endl;
    cout << "\t- 3. Mostrar lista de deputados                             -" << endl;
    cout << "\t- 4. Mostrar lista de empresas                              -" << endl;
    cout << "\t- 5. Mostrar o Grafo                                        -" << endl;
    cout << "\t- 6. Ajuda                                                  -" << endl;
    cout << "\t- 7. Sair                                                   -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\t>>> ";
}

/**
 * Displays the deputy search user interface of the project
 *
 * @return void
 */
void deputySearchUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- 1. Informe o identificador do deputado                    -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\t>>> ";
}

/**
 * Displays the state search user interface of the project
 *
 * @return void
 */
void stateSearchUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- 1. Informe o estado do deputado                           -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\t>>> ";
}

/**
 * Displays the party search user interface of the project
 *
 * @return void
 */
void partySearchUI(){
    clear();

    cout << "\t-----Brazil's House of Deputies Reimbursements Anomalies-----" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t- 1. Informe o partido do deputado                          -" << endl;
    cout << "\t-                                                           -" << endl;
    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\t>>> ";
}

/**
 * Displays a message when the user inputs a not valid choice for the
 *  processUIChoice
 *
 * @return void
 */
void displayWrongChoiceUI(){
    displayUI();
    cout << "\tEscolha invalida, informe um valor de 1 a 7" << endl;
    cout << "\t>>> ";
}


/**
 * Displays a message when the user inputs a not valid choice for the
 *  processUIChoice
 *
 * @return void
 */
void displayWrongSearchChoiceUI(){
    searchUI();
    cout << "\tEscolha invalida, informe um valor de 1 a 4" << endl;
    cout << "\t>>> ";
}

/**
 * Print all party expanses given a party input
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

    pressToContinue();
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

    pressToContinue();
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

    pressToContinue();
}

/**
 * Process what is the user's choice of the search interface
 *  and call the respective method
 *
 * @return void
 */
void processSearchChoice(){
    int choice = 0;

    cin >> choice;

    while(choice != 4){
        clear();

        if(choice == 1){
            deputySearchUI();
            findDeputy();
            searchUI();
        } else if(choice == 2){
            stateSearchUI();
            findState();
            searchUI();
        } else if(choice == 3){
            partySearchUI();
            findParty();
            searchUI();
        }  else {
            displayWrongSearchChoiceUI();
        }

        cin >> choice;
    }
}

/**
 * Process what is the user's choice of the main user interface
 *  and call the respective method
 *
 * @return void
 */
void processUIChoice(){
    int choice = 0;

    cin >> choice;

    while(choice != 7){
        clear();

        if(choice == 1){
            printAnomalies();
            displayUI();
        } else if(choice == 2){
            searchUI();
            processSearchChoice();
            displayUI();
        } else if(choice == 3){
            printdVertex();
            displayUI();
        } else if(choice == 4){
            printcVertex();
            displayUI();
        } else if(choice == 5){
            printGrafo();
            displayUI();
        } else if(choice == 6){
            displayHelpUI();
            displayUI();
        } else {
            displayWrongChoiceUI();
        }

        cin >> choice;
    }
}


void printAnomalies(){
    createCommunities();

    calcAnomalies();

    pressToContinue();
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

    pressToContinue();
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

    pressToContinue();
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

    pressToContinue();
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

    loadingUI();
    readFile();
    displayUI();
    processUIChoice();

  return 0;
}

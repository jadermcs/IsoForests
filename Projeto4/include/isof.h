#ifndef ISOFOREST
#define ISOFOREST

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

void clear();
void deputySearchUI();
void displayHelpUI();
void displayUI();
void displayWrongChoiceUI();
void displayWrongSearchChoiceUI();
void loadingUI();
void partySearchUI();
void pressToContinue();
void printAnomalies();
void printcVertex();
void printdVertex();
void printGrafo();
void processSearchChoice();
void processUIChoice();
void stateSearchUI();
void createCommunities();
void calcAnomalies();


int add_cVertex(string c_name, string c_id);
int add_dVertex(string d_name, string d_state, string d_party);
void add_rEdge(string r_desc, string r_date, float r_value, int dVertex, int cVertex);
int edgeExistence(string r_desc, string nome, int d_index);
int nameExistence(int deputyOrCompany, string name);
int readFile();


typedef struct cVertex{
    string name;
    string id;
}t_cVertex;

typedef struct rEdge{
    string tipoT;
    vector< pair<string, float> > transac;
    cVertex empresa;
}t_rEdge;

typedef struct dVertex{
    string name;
    string state;
    string party;
    vector<rEdge> gastos;
}t_dVertex;

pair< vector<dVertex>, vector<cVertex> > GRAPH;
map<string, float> COM;

#endif

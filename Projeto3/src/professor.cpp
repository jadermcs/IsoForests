#include "professor.hpp"

Professor:: Professor(int id, int num_skills){
  this->id = id;
  this->num_skills = num_skills;
  this->works_for = NULL;
};

void Professor:: set_prefs(int *the_prefs){
  for (int i=0; i<MAX_PREFS; i++){
    preferences[i] = the_prefs[i]-1;
  }
}

Professor* Professor::get_free_professor(list<Professor*> &pl){
  for (auto prof: pl){
    if (prof->is_free()){
      pl.remove(prof);
      pl.push_back(prof);
      return prof;
    }
  }
  return NULL;
}

bool Professor::is_free(){
  return (!works_for);
}

int Professor::propouse(){
  if (pref_idx >= MAX_PREFS){
    throw runtime_error("Professor::propouse " + stoi(id) + " priority list overflow"); // mingw does not support to_string. source: https://stackoverflow.com/a/12975602
  }
  return preferences[pref_idx++];
}

void Professor::gets_job(School *s){
  if (! this->is_free() ){
    cout << "the school is: " << works_for << endl;
    throw runtime_error("Professor::gets_job " + stoi(id) + " has to be unemployed first");
  }
  works_for = s;
}

void Professor::loses_job(){
  works_for = NULL;
}

int Professor::get_priority_idx(int school_id){
  for (int i=0; i<MAX_PREFS; i++){
    if (preferences[i] == school_id){
      return i;
    }
  }
  throw runtime_error("Professor::get_priority_idx " + stoi(id) + " not found school_id");
}

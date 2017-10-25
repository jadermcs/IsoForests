#include "school.hpp"

School::School(int id, int min_skill){
  if (min_skill < 0 || min_skill > MAX_SKILLS)
    throw invalid_argument("School::School min_skill must be positive");
  this->id = id;
  this->min_skill = min_skill;
}

bool School::is_free(){
  return ((int) linked_to.size() < capacity);
}

void School::accepts(Professor *p){
  if ((int) linked_to.size() > capacity){
    throw runtime_error("School::accepts " + stoi(id) + " full capacity reached");
  }
  linked_to.push_back(p);
  p->gets_job(this);
}

void School::kicks(Professor *p){
  linked_to.remove(p);
  p->loses_job();
}

list<Professor*> School::get_team(){
  return linked_to;
}

bool School::prefers(Professor *a, Professor *b){
  return (a->pref_idx > b->pref_idx);
}

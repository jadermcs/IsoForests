#ifndef PROFESSORHPP
#define PROFESSORHPP

#include "main.hpp"
#include "school.hpp"

class School;

class Professor{
public:
  int id;
  int num_skills;
  int preferences[MAX_PREFS]; int pref_idx=0;
  School *works_for;

  Professor(int id, int num_skills);

  void set_prefs(int *the_prefs);

  static Professor* 	get_free_professor(list<Professor*> &pl);

  bool 	is_free();
  int 	propouse();
  void	gets_job(School *s);
  void	loses_job();
  int 	get_priority_idx(int school_id);
};


#endif

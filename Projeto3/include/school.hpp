#ifndef SCHOOLHPP
#define SCHOOLHPP

#include "main.hpp"
#include "professor.hpp"

class Professor;

class School {
public:
  int id;
  int min_skill;
  list<Professor*> linked_to;
  int capacity = 2;

  School(int id, int min_skill);

  bool 				is_free();
  void 				accepts(Professor *p);
  void				kicks(Professor *p);
  list<Professor*> 	get_team();
  bool				prefers(Professor *a, Professor *b);
};

#endif

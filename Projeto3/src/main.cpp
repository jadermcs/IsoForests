#include "main.hpp"
#include "professor.hpp"
#include "school.hpp"

template <class T>
class PoolManager{
private:
  T** pool_array;
  int max_elements;
public:
  PoolManager(int max_elements){
    pool_array = (T**)malloc(max_elements * sizeof(void*));
    int idx;
    for (idx=0; idx < max_elements; idx++)
      pool_array[idx] = NULL;

    this->max_elements = max_elements;
  }
  ~PoolManager(){
    free(this->pool_array);
  }

  int add_element(T* elem_p){
    if ( elem_p->id < 0 || elem_p->id >= max_elements){
      return -1;
    }
    pool_array[elem_p->id] = elem_p;
    return elem_p->id;
  }

  T* get_fromID(int id){
    if (id < 0 || id >= max_elements){
      return NULL;
    }
    return pool_array[id];
  }

  void get_element_list(list<T*> &l){
    for (int idx=0; idx<max_elements; idx++){
      if (pool_array[idx]){
	l.push_back(pool_array[idx]);
      }
    }
  }

  void free_all(){
    int idx;
    for (idx=0; idx<max_elements; idx++)
      free(pool_array[idx]);
  }
};

void make_matches(PoolManager<Professor> &pm, PoolManager<School> &sm){

  list<Professor*> pl;
  Professor* unemployed_human;
  School* provoked_school;

  pm.get_element_list(pl);
  //Professor::sort_descending(pl);
  while(true){
    unemployed_human = Professor::get_free_professor(pl);
    if (! unemployed_human){
      break;
    }

    int prop_id = unemployed_human->propouse();
    provoked_school = sm.get_fromID(prop_id);
    if (!provoked_school){
      break;
    }

    if (provoked_school->is_free()){
      provoked_school->accepts(unemployed_human);
    } else {
      list<Professor*> enemy_set = provoked_school->get_team();
      for (auto enemy : enemy_set){
	if ( provoked_school->prefers(unemployed_human, enemy) ){
	  provoked_school->kicks(enemy);
	  provoked_school->accepts(unemployed_human);
	  break;
	}
      }
    }
  }

  list<School*> sl; string line;
  sm.get_element_list(sl);
  for (auto school: sl){
    list<Professor*> p = school->get_team();
    cout << "E" << school->id+1 << endl;
    line = "\t[";
    for (auto professor: p){
      line += "P" + stoi(professor->id+1) + ", ";
    }
    line += "\b\b]";
    cout << line << endl;
  }
}


int main(){
  ifstream fp;
  string line;

  PoolManager<Professor> pm(NUM_PROFESSORS);
  PoolManager<School> sm(NUM_SCHOOLS);

  int id, skill, preference[MAX_PREFS];
  int read_c;

  Professor *the_professor, *cur;
  School *the_school;

  fp.open(FILE_NAME);

  if (!fp.is_open ()) {
    cout << "Could not open file \"" << FILE_NAME << "\"." << endl;
    exit(1);
  }

  fp.seekg (PRF_START, ios_base::beg);

  for (int i = 0; i < NUM_PROFESSORS; i++) {
    getline (fp, line);
    read_c = sscanf (line.c_str(), "(P%d, %d): (E%d, E%d, E%d, E%d, E%d)",
		     &id, &skill, &preference[0], &preference[1], &preference[2], &preference[3], &preference[4]);
    // if (read_c != 7){
    //   i--;
    //   continue;
    // }
    the_professor = new Professor(id-1, skill);
    the_professor->set_prefs(preference);
    read_c = pm.add_element(the_professor);
  }

  fp.seekg (SCH_START, ios_base::beg);

  for (int i = 0; i < NUM_SCHOOLS; i++) {
    getline (fp, line);
    read_c = sscanf (line.c_str(), "(E%d):(%d)", &id, &skill);
    the_school = new School(id-1, skill);
    sm.add_element(the_school);
  }

  fp.close();

  make_matches(pm,sm);

  pm.free_all();
  sm.free_all();

  return 0;
}

#ifndef MAINHPP
#define MAINHPP

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>
#include <map>

#define NUM_PROFESSORS 100
#define NUM_SCHOOLS 50
#define MAX_PREFS 5
#define MAX_SKILLS 3
#define FILE_NAME "input.txt"
#define PRF_START 130
#define SCH_START 3719
#define MAX_PROFS 3
#define ERR -1

using namespace std;

#include <sstream>

template <typename T>
string stoi ( T Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}


#endif

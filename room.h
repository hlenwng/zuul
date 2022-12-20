#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
using namespace std;

class room {
 public:
  room();
  room(char* name);
  void setExit(char* direction, room* neighbor);
  void removeItem(char *it);
  void setItem(item* newItem);
  void printItem();
  map<char*, room*> getExit();
  item* matchItem(char* input);
  void printDescription();
  int getID();
  
 private:
  vector<item*> items;
  int id;
  map<char*, room*> exits;
  char* name;
  item* match;
};

#endif

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
using namespace std;

/*
  Creator: Helen Wang
  Date: Dec 19, 2022
  Program: Header file for room's class.
*/

class room {
 public:

  //Declare functions
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
  //Intialize functions
  vector<item*> items;
  int id;
  map<char*, room*> exits;
  char* name;
  item* match;
};

#endif

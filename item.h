#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class item {
 public:
  item();
  item(char* newItem);
  char* getItem();
 private:
  char* z;
  char* description;
};
#endif


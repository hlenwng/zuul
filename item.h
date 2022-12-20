#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

/*
  Creator: Helen Wang
  Date: Dec 19, 2022
  Program: Header file for item's class.
*/

class item {
 public:
  //Intialize functions
  item();
  item(char* newItem);
  char* getItem();
 private:
  //Intialize variables
  char* z;
  char* description;
};
#endif


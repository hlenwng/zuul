#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
#include <map>
using namespace std;

/* Creator: Helen Wang
   Date: Dec 19, 2022
   Program: cpp file for item's functions.
*/

//Create item
item::item(char *newItem) {
  description = newItem;
}

//Get item's info
char* item::getItem() {
  char *z = new char[20];
  strcpy(z, description);
  return z;
}

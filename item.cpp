#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
#include <map>
using namespace std;

item::item(char *newItem) {
  description = newItem;
}

char* item::getItem() {
  char *z = new char[20];
  strcpy(z, description);
  return z;
}

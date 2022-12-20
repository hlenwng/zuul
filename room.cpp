#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include <map>
using namespace std;

room::room() {

}

room::room(char* newName) {
  name = newName;
  
}

map<char*, room*> room::getExit() {
  return exits;
}

void room::setExit(char* direction, room *neighbor) {
  exits.insert(make_pair<char*,room*>(((char*)direction), ((room*)neighbor)));
}

void room::printDescription() {
  cout << "You are in the " << name << endl;
  cout << "Exits: ";
  
  map<char*, room*>::iterator i;
    for (i = exits.begin(); i != exits.end(); ++i) {
      cout << i->first << ", ";
    }

    cout << endl;
}

void room::setItem(item* newItem) {
  items.push_back(newItem);
}


void room::removeItem(char *it) {
  vector<item*>::iterator i;
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(it, items[i]->getItem()) == false){
      items.erase(items.begin() + i);
    }
  }
}

item* room::matchItem(char* input) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getItem(), input) == 0) {
      match = items[i];
    }
  }
  return match;
}

void room::printItem() {
  cout << "Items: ";
  for (int i = 0; i < items.size(); i++) {
    cout << items[i]->getItem();
    cout << " ";
  }
  cout << endl;
}

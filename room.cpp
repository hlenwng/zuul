#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include <map>
using namespace std;

/*
  Creator: Helen Wang
  Date: Dec 19, 2022
  Program: cpp file for room functions.
*/

room::room() {
}

//Create room
room::room(char* newName) {
  name = newName;
}

//Gets a room's exits
map<char*, room*> room::getExit() {
  return exits;
}

//Sets a room's exits (the exit's direction, and which room it leads to)
void room::setExit(char* direction, room *neighbor) {
  exits.insert(make_pair<char*,room*>(((char*)direction), ((room*)neighbor)));
}

//Prints the room's name and exits
void room::printDescription() {
  cout << "You are in the " << name << endl;
  cout << "Exits: ";
  
  map<char*, room*>::iterator i;
    for (i = exits.begin(); i != exits.end(); ++i) {
      cout << i->first << ", ";
    }

    cout << endl;
}

//Creates a new item
void room::setItem(item* newItem) {
  items.push_back(newItem);
}

//Remove's an item from your inventory
void room::removeItem(char *it) {
  vector<item*>::iterator i;
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(it, items[i]->getItem()) == false){
      items.erase(items.begin() + i);
    }
  }
}

//See if item you want to pick up is there
item* room::matchItem(char* input) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getItem(), input) == 0) {
      match = items[i];
    }
  }
  return match;
}

//Print the items in a room
void room::printItem() {
  cout << "Items: ";
  for (int i = 0; i < items.size(); i++) {
    cout << items[i]->getItem();
    cout << " ";
  }
  cout << endl;
}

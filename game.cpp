#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include <map>
#include "item.h"
using namespace std;

/*
  Title: Zuul
  Creator: Helen Wang
  Date: Dec 19, 2022
  Program: An interactive word game where users can move between rooms,
  pick up & drop items, view their inventory,
  and win the game by picking the baby up.
*/

//Intialize functions
//room* go(int&id, room* currentRoom, char secondWord[]);
room* go(room* currentRoom, map<char*, room*>&exit);
bool get(room* currentRoom, vector<item*>&inven); 
void getInven(vector<item*>&inven);
void drop(room* currentRoom, vector<item*>&inven);

int main() {
  //Intialize variables
  vector<room*> rooms;
  map<char*, room*> exits;
  vector<item*> inven;
  //int id = 3;
  room* currentRoom;
  char GO[3] = "GO";
  char GET[4] = "GET";
  char HELP[5] = "HELP";
  char DROP[5] = "DROP";
  char INVENTORY[10] = "INVENTORY";
  char QUIT[5] = "QUIT";
  char input[20];
  bool playing = true;
  char secondWord[20];
  
  //Create rooms & items
  room* kitchen = new room((char*)"in the kitchen");
  room* bathroom = new room((char*)"in the bathroom");
  room* bedroom = new room((char*)"in the bedroom");
  room* dungeon = new room((char*)"in the dungeon");
  room* balcony = new room((char*)"in the balcony");
  room* basement = new room((char*)"in the basement");
  room* pool = new room((char*)"in the pool");
  room* playroom = new room((char*)"in the playroom");
  room* door = new room((char*)"in the door");
  room* hottub = new room((char*)"in the hot tub");
  room* pantry = new room((char*)"in the pantry");
  room* beach = new room((char*)"in the beach");
  room* closet = new room((char*)"in the closet");
  room* attic = new room((char*)"in the attic");
  room* sofa = new room((char*)"in the sofa");

  
  item* babyfood = new item((char*)"babyfood");
  item* spoon = new item((char*)"spoon");
  item* baby = new item((char*)"baby");
  item* mother = new item((char*)"mother");
  item* peaches = new item((char*)"peaches");
  
  //intialize room exits                                                      
  kitchen->setExit((char*)"east", bathroom);
  kitchen->setExit((char*)"south", sofa);

  bathroom->setExit((char*)"east", bedroom);
  bathroom->setExit((char*)"west", kitchen);
  
  bedroom->setExit((char*)"east", dungeon);
  bedroom->setExit((char*)"west", bathroom);

  dungeon->setExit((char*)"east", balcony);
  dungeon->setExit((char*)"west", bedroom);

  balcony->setExit((char*)"south", basement);
  balcony->setExit((char*)"west", dungeon);

  basement->setExit((char*)"south", pool);
  basement->setExit((char*)"north", balcony);

  pool->setExit((char*)"south", playroom);
  pool->setExit((char*)"north", basement);

  playroom->setExit((char*)"north", pool);
  playroom->setExit((char*)"south", door);
  playroom->setExit((char*)"west", hottub);
  
  door->setExit((char*)"north", playroom);

  hottub->setExit((char*)"east", playroom);
  hottub->setExit((char*)"west", pantry);

  pantry->setExit((char*)"east", hottub);
  pantry->setExit((char*)"west", beach);

  beach->setExit((char*)"east", pantry);
  beach->setExit((char*)"west", closet);

  closet->setExit((char*)"east", beach);
  closet->setExit((char*)"north", attic);

  attic->setExit((char*)"south", closet);
  attic->setExit((char*)"north", sofa);

  sofa->setExit((char*)"south", attic);
  sofa->setExit((char*)"north", kitchen);

  //Set current room
  currentRoom = kitchen;

  //Intialize room items
  kitchen->setItem(babyfood);
  hottub->setItem(baby);
  closet->setItem(spoon);
  basement->setItem(peaches);
  bedroom->setItem(mother);

  //Welcoming message
  cout << endl;
  cout << "Welcome to Zuul!" << endl;
  cout << "This is an text-interactive adventure game." << endl;
  cout << "Find the baby in Angie's house." << endl;
  cout << "Type 'help' if you need help." << endl;
  currentRoom->printDescription();
  cout << endl;

  //While user still wants to play, or hasn't won yet...
  while (playing) {
    cout << endl;
    cout << "Type in a command (GO, GET, HELP, DROP, INVENTORY or QUIT)" << endl;
    cin.get(input, 20);
    cin.get();

    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }
    
    if (strcmp(input, GO) == false) {
      //currentRoom = go(id, currentRoom, secondWord);
      currentRoom = go(currentRoom, exits);
      cout << endl;
    }
    
    else if (strcmp(input, GET) == false) {
      currentRoom->printItem();
      playing = get(currentRoom, inven);      
    }
    
    else if (strcmp(input, HELP) == false) {
      cout << "Instructions for commands" << endl;
      cout << "Go -> direction" << endl;
      cout << "Get -> pick up item" << endl;
      cout << "Drop -> drop an item" << endl;
      cout << "Inventory -> view your inventory" << endl;
      cout << "Quit -> quit zuul program" << endl;
      cout << endl;
    }
    
    else if (strcmp(input, DROP) == false) {
      drop(currentRoom, inven);
    }
    
    else if (strcmp(input, INVENTORY) == false) {
      getInven(inven);
    }
    
    else if (strcmp(input, QUIT) == false) {
      cout << "Thank you for playing" << endl;
      playing = false;
    }
    
    else {
      cout << "Please type in a valid command" << endl;
      cout << endl;
    }
  }
}

//User can pick up an item from a room
bool get(room* currentRoom, vector<item*>&inven) {
  cout << "What item do you want to pick up?" << endl;
  char input [20];
  cin.get(input, 20, '\n');
  cin.ignore();

  if(strcmp(input, "baby food")==0 || strcmp(input, "spoon") == 0) {
    cout << "You have picked it up" << endl;
  }

  //Winning condition: picking up the baby
  else if (strcmp(input, "baby") == 0) {
    cout << "You picked up the baby" << endl;
    cout << "You win" << endl;
    return false;
  }
  
  //push to inventory vector
  inven.push_back(currentRoom->matchItem((char*)input));

  //get rid from current room
  //inven.push_back(input);
  currentRoom->removeItem(input);
  //currentRoom->removeItem(currentRoom->matchItem((char*)input));
  return true;
}

//Drop an item that you've picked up before
void drop(room* currentRoom, vector<item*>&inven) {
  cout << "What do you want to drop?" << endl;
  char input[20];
  cin.get(input, 20, '\n');
  cin.ignore();

  if(strcmp(input, "baby food")==0 || strcmp(input, "spoon") == 0 || strcmp(input, "baby\
   ") == 0) {
    cout << "You have dropped it" << endl;
  }
  item* drop;
  
  //currentRoom->setItem(drop);

  //remove from inventory
  for (int i = 0; i < inven.size(); i++) {
    if (strcmp(input, inven[i]->getItem()) == false){
      inven.erase(inven.begin() + i);
      drop = inven[i];
    }
  }

  //push to current room                                                                
  currentRoom->setItem(drop);
}

//View your current inventory (items you've collected)
void getInven(vector<item*>&inven) {
  //print inventory
  cout << "Inventory: ";
  for(int i = 0; i < inven.size(); i++){
    cout << inven[i]->getItem();
  }
  cout << endl;
}

//Go to a room through exits
room* go(room* currentRoom, map<char*, room*>&exit) {
  cout << endl;
  char secondWord[20];
  currentRoom->printDescription();
  //currentRoom->printItem();
  cout << "Which direction do you want to go? (north, east, south, west)" << endl;
  cin.get(secondWord, 20);
  cin.ignore();

  if ((strcmp(secondWord, "north") == 0) || (strcmp(secondWord, "south") == 0) || (strcmp(secondWord, "east") == 0) || (strcmp(secondWord, "west") == 0)) {

    //search for existing room
    map<char*, room*>::iterator i;

    //ITERATOR DOESN'T WORK ON MAC (can't read in second direction value)
    //i++ doesn't work, doesn't advance
    for (i = currentRoom->getExit().begin(); i != currentRoom->getExit().end(); ++i) {
      cout << "searching" << endl;
      if (strcmp(secondWord, i->first) == false) {
	currentRoom = i->second;
	break;
      }
    }
  }
  else {
    cout << "There is no exit there" << endl;
  }

   currentRoom->printDescription();
   cout << endl;
   return currentRoom;
}

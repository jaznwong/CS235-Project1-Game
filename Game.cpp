#include <iostream>
#include <vector>
#include <string>
#include "Game.h"

using namespace std;

//set default constructor
Tractor::Tractor() {
  x = 0;
  y = 0;
  size = 0;
  activity = IDLE;
}

//int x mutator method
void Tractor::set_x(int x_val){
  x = x_val;
}
//int x accessor method
int Tractor::get_x() const{
  return x;
}
//int y mutator method
void Tractor::set_y(int y_val){
  y = y_val;
}
//int y accessor method
int Tractor::get_y() const{
  return y;
}
//short size mutator method
void Tractor::set_size(unsigned short size_val){
  size = size_val;
}
//short size accessor method
unsigned short Tractor::get_size() const{
  return size;
}
//activity mutator method
void Tractor::set_activity(Activity activity_mode){
  activity = activity_mode;
}
//activity accessor method
Activity Tractor::get_activity() const{
  return activity;
}

//set parameterized constructor
Tractor::Tractor(const int& x_val, const int& y_val, const unsigned short& size_val, const Activity& activity_val){
  x = x_val;
  y = y_val;
  size = size_val;
  activity = activity_val;
}
//end tractor

//begin Game

Game::Game(unsigned new_size){
  map_size = new_size; //sets the size of the map
}
//end constructor

unsigned int Game::get_mapsize() const { //returns the size of the map
  return map_size;
}


int Game::GetTractor(int x, int y) const{ //iterate through vector to find index of tractor at (x,y)
  for (int i = 0; i < all.size(); i++) { //iterates to max size of vector
    if ((all[i].get_x() - all[i].get_size()/2) <= x && x <= (all[i].get_x() + all[i].get_size()/2) && //checks to see if x is between the left and right bounds of the tractors
    (all[i].get_y() - all[i].get_size()/2) <= y && y <= (all[i].get_y() + all[i].get_size()/2)) { //checks to see if y falls within the top and bottom bounds of the tractors
      return i; //returns the index of the tractor if (x,y) falls within the bounds of one of the tractors
    }

  }
  return -1; //returns -1 if x,y does not fall within the bounds of one of the tractors
  }

void Game::SelectTractor(int x, int y){ //if x,y is within the bounds of a tractor, that tractor index will be added to the selected vector
  while (selected.size() > 0){ //empties selected vector if there is something in it
    selected.pop_back();
  }
  //check for tractor
  //if tractor exists take index and move to selected
  //if tractor does not exist, empty the selected vect
  if (GetTractor(x,y) != -1){ //checks to see if index is returned or not
    selected.push_back(GetTractor(x, y)); //if index is returned, the index of the tractor will be added to selected vector
  }
    else if (GetTractor(x,y) == -1){ //if index is not returned, the selected vector will be emptied
      selected.pop_back();
    }
  }


void Game::SelectTractors(int x1, int y1, int x2, int y2){ //selects tractors that fall within the rectangular bounds of x1,y1 and x2,y2
  while (selected.size() > 0){ //empties selected vector
    selected.pop_back();
  }
  for (int k = 0; k < all.size(); k++){ //iterates through every element in all vector that holds all the tractors on the map

    // each of the four cases checks to see if the bounds of the tractor fall within the rectangule x1,y1 and x2,y2 depending on the positions of x1,y1 and x2,y2
    // since there are four ways to change the coordinates (x-size,y-size) , (x+size, y+size), (x-size, y+size), (x+size, y-size), within each case there are four coordinate changes to check
    //if bounds of tractor fall within the rectangle defined by x1,y1 and x2,y2 the tractor index will be added to the selected vector

    if (x1 < x2 && y1 < y2){ //x1,y1 bottom left && x2,y2 top right
      if ((all[k].get_x() - all[k].get_size()/2 >= x1 && all[k].get_x() - all[k].get_size()/2 <= x2 && all[k].get_y() + all[k].get_size()/2 <= y2 && all[k].get_y() + all[k].get_size()/2 >=y1)||
      (all[k].get_x() - all[k].get_size()/2 >= x1 && all[k].get_x() - all[k].get_size()/2 <= x2 && all[k].get_y() - all[k].get_size()/2 <= y2 && all[k].get_y() - all[k].get_size()/2 >=y1)||
      (all[k].get_x() + all[k].get_size()/2 >= x1 && all[k].get_x() + all[k].get_size()/2 <= x2 && all[k].get_y() + all[k].get_size()/2 <= y2 && all[k].get_y() + all[k].get_size()/2 >=y1)||
      (all[k].get_x() + all[k].get_size()/2 >= x1 && all[k].get_x() + all[k].get_size()/2 <= x2 && all[k].get_y() - all[k].get_size()/2 <= y2 && all[k].get_y() - all[k].get_size()/2 >=y1)){
        selected.push_back(k);
    }
  }

    else if (x1 < x2 && y1 > y2){ //x1,y1 top left && x2,y2 bottom right
      if ((all[k].get_x() - all[k].get_size()/2 >= x1 && all[k].get_x() - all[k].get_size()/2 <= x2 && all[k].get_y() + all[k].get_size()/2 <= y1 && all[k].get_y() + all[k].get_size()/2 >=y2)||
      (all[k].get_x() - all[k].get_size()/2 >= x1 && all[k].get_x() - all[k].get_size()/2 <= x2 && all[k].get_y() - all[k].get_size()/2 <= y1 && all[k].get_y() - all[k].get_size()/2 >=y2) ||
      (all[k].get_x() + all[k].get_size()/2 >= x1 && all[k].get_x() + all[k].get_size()/2 <= x2 && all[k].get_y() + all[k].get_size()/2 <= y1 && all[k].get_y() + all[k].get_size()/2 >=y2) ||
      (all[k].get_x() + all[k].get_size()/2 >= x1 && all[k].get_x() + all[k].get_size()/2 <= x2 && all[k].get_y() - all[k].get_size()/2 <= y1 && all[k].get_y() - all[k].get_size()/2 >=y2)){
        selected.push_back(k);
      }
    }

    else if (x1 > x2 && y1 < y2){ //x1,y1 bottom right && x2,y2 top left
      if ((all[k].get_x() - all[k].get_size()/2 >= x2 && all[k].get_x() - all[k].get_size()/2 <= x1 && all[k].get_y() + all[k].get_size()/2 <= y2 && all[k].get_y() + all[k].get_size()/2 >= y1) ||
      (all[k].get_x() - all[k].get_size()/2 >= x2 && all[k].get_x() - all[k].get_size()/2 <= x1 && all[k].get_y() - all[k].get_size()/2 <= y2 && all[k].get_y() - all[k].get_size()/2 >= y1)||
      (all[k].get_x() + all[k].get_size()/2 >= x2 && all[k].get_x() + all[k].get_size()/2 <= x1 && all[k].get_y() + all[k].get_size()/2 <= y2 && all[k].get_y() + all[k].get_size()/2 >= y1)||
      (all[k].get_x() + all[k].get_size()/2 >= x2 && all[k].get_x() + all[k].get_size()/2 <= x1 && all[k].get_y() - all[k].get_size()/2 <= y2 && all[k].get_y() - all[k].get_size()/2 >= y1)){
        selected.push_back(k);
      }
    }
    else if (x1 > x2 && y1 > y2){ //x1,y1 top right && x2,y2 bottom left
      if ((all[k].get_x() - all[k].get_size()/2 >= x2 && all[k].get_x() - all[k].get_size()/2 <= x1 && all[k].get_y() + all[k].get_size()/2 <= y1 && all[k].get_y() + all[k].get_size()/2 >= y2) ||
      (all[k].get_x() - all[k].get_size()/2 >= x2 && all[k].get_x() - all[k].get_size()/2 <= x1 && all[k].get_y() - all[k].get_size()/2 <= y1 && all[k].get_y() - all[k].get_size()/2 >= y2)||
      (all[k].get_x() + all[k].get_size()/2 >= x2 && all[k].get_x() + all[k].get_size()/2 <= x1 && all[k].get_y() + all[k].get_size()/2 <= y1 && all[k].get_y() + all[k].get_size()/2 >= y2)||
      (all[k].get_x() + all[k].get_size()/2 >= x2 && all[k].get_x() + all[k].get_size()/2 <= x1 && all[k].get_y() - all[k].get_size()/2 <= y1 && all[k].get_y() - all[k].get_size()/2 >= y2)){
        selected.push_back(k);
      }
    }
  }
}

void Game::AddTractor(Tractor new_unit){ //adds a new tractor to the map and thus the all vector
  all.push_back(new_unit);
}

bool Game::MoveTractor(int i, int new_x, int new_y){ //tractor i is moved to new_x and new_y if it doesnt intersect with another tractor and if it doesnt fall off the map
  //checks to see if new_x and new_y is within the bounds of the map
  //checks to see if the entire tractor lies within the map
    if (0 <= (new_x - all[i].get_size()/2) &&  //checks to see if new_x - 1/2 tractor size is to the right of the left bound
    map_size >= (new_x + all[i].get_size()/2) && //checks to see if new_x + 1/2 tractor size  is to the left of the right bound
    0 <= (new_y - all[i].get_size()/2) &&   //checks to see if new_y - 1/2 tractor size is above the bottom bound
    map_size >= (new_y + all[i].get_size()/2)){ //checks to see if new_y + 1/2 tractor size is below the top bound

      for (int k = 0; k < all.size(); k++){ //iterates through each tractor in the all vector and thus on the map

        if (k != i){ //doesnt check to see if tractor i at the new coordinates will intersect with tractor i at its original coordinates

        // each case represents the four ways to change the coordinates (new_x-size,new_y-size) , (new_x+size, new_y+size), (new_x-size, new_y+size), (new_x+size, new_y-size)
        //if any of the four coordinate changes involving new_x and new_y intersects with any bounds of the tractors on the map, the tractor cannot be moved to the new coordinates

        //(new_x-size, new_y+size)
          if ((new_x - all[i].get_size()/2 >= all[k].get_x() - all[k].get_size()/2 && //checks left bound
          new_x - all[i].get_size()/2 <= all[k].get_x() + all[k].get_size()/2 && //checks right bound
          new_y + all[i].get_size()/2 >= all[k].get_y() - all[k].get_size()/2 && //checks bottom bound
          new_y + all[i].get_size()/2 <= all[k].get_y() + all[k].get_size()/2) || //checks top bound
          //(new_x-size,new_y-size)
          (new_x - all[i].get_size()/2 >= all[k].get_x() - all[k].get_size()/2 &&
          new_x - all[i].get_size()/2 <= all[k].get_x() + all[k].get_size()/2 &&
          new_y - all[i].get_size()/2 >= all[k].get_y() - all[k].get_size()/2 &&
          new_y - all[i].get_size()/2 <= all[k].get_y() + all[k].get_size()/2) ||
          //(new_x+size,new_y+size)
          (new_x + all[i].get_size()/2 >= all[k].get_x() - all[k].get_size()/2 &&
          new_x + all[i].get_size()/2 <= all[k].get_x() + all[k].get_size()/2 &&
          new_y + all[i].get_size()/2 >= all[k].get_y() - all[k].get_size()/2 &&
          new_y + all[i].get_size()/2 <= all[k].get_y() + all[k].get_size()/2) ||
          //(new_x+size, new_y-size)
          (new_x + all[i].get_size()/2 >= all[k].get_x() - all[k].get_size()/2 &&
          new_x + all[i].get_size()/2 <= all[k].get_x() + all[k].get_size()/2 &&
          new_y - all[i].get_size()/2 >= all[k].get_y() - all[k].get_size()/2 &&
          new_y - all[i].get_size()/2 <= all[k].get_y() + all[k].get_size()/2)) {
            return false;
          }
          else { //if the bounds of the tractor i at the new coordinates do not intersect with another vector and the tractor of the new coordinates do not fall of the map:
            all[i].set_x(new_x); //x coordinate of tractor i is changed to new_x
            all[i].set_y(new_y); //y coordinate of tractor i is changed to new_y
            return true; //true is returned if tractor can be moved
          }
        }
      }
    }
    return false; //false is returned if tractor cannot be moved
  }


void Game::AssignTractorsActivity(Activity new_activity){ //sets a new activity for tractors in selected vector
  for (int i = 0; i < selected.size(); i++){
    int x = selected[i]; //int x holds the index of the tractors in the selected vector
    all[i].set_activity(new_activity); //the index of the tractor will be changed in the main vector that holds the tractors
  }
}

void Game::PrintTractor(int i){ //prints all information of tractor i
  string act;
  if (all[i].get_activity() == 0){
    act = "SEEDING";
  }
  else if (all[i].get_activity() == 1){
    act = "HARVESTING";
  }
  else if (all[i].get_activity() == 2){
    act = "MOVING";
  }
  else if (all[i].get_activity() == 3){
    act = "IDLE";
  }
  cout << "Position: (" << all[i].get_x() << "," << all[i].get_y() << ") Size: " << all[i].get_size() << " Activity: " << act << " " << endl;
}

void Game::PrintSelectedTractors(){ //prints information of tractors in selected vector (position, size and activity)
  for (int i = 0; i <selected.size(); i++){
    int x = selected[i]; //int x holds the index of the tractors in the selected vector
    //the corresponding index in the all vector will print that tractors information
    string act;
    if (all[i].get_activity() == 0){
      act = "SEEDING";
    }
    else if (all[i].get_activity() == 1){
      act = "HARVESTING";
    }
    else if (all[i].get_activity() == 2){
      act = "MOVING";
    }
    else if (all[i].get_activity() == 3){
      act = "IDLE";
    }
    cout << "Position: (" << all[x].get_x() << "," << all[x].get_y() << ") Size: " << all[x].get_size() << " Activity: " << act << " " << endl;
  }
}

void Game::PrintAllTractors(){ //prints the information of all the tractors in all vector
  for (int i = 0; i < all.size(); i++){
    string act;
    if (all[i].get_activity() == 0){
      act = "SEEDING";
    }
    else if (all[i].get_activity() == 1){
      act = "HARVESTING";
    }
    else if (all[i].get_activity() == 2){
      act = "MOVING";
    }
    else if (all[i].get_activity() == 3){
      act = "IDLE";
    }
    cout << "Position: (" << all[i].get_x() << "," << all[i].get_y() << ") Size: " << all[i].get_size() << " Activity: " << act << " " << endl;
  }
}

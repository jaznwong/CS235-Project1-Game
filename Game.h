#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum Activity {SEEDING, HARVESTING, MOVING, IDLE}; //declaration of Activity type with four attributes

//Declaration for Tractor class
class Tractor
{
private:
  //x coordinate of Tractor
  int x;
  //y coordinate of Tractor
  int y;
  // size of the Tractor
  unsigned short size;
  //current acticity
  Activity activity;

public:
  //mutator method of x
  void set_x(int);
  //accessor method for int x
  int get_x() const;
  //mutator method for int y
  void set_y(int);
  //accessor method for int y
  int get_y() const;
  //mutator method for size;
  void set_size(unsigned short);
  //accessor method for size
  unsigned short get_size() const;
  //mutator method for activity
  void set_activity(Activity);
  //accessor method for activity
  Activity get_activity() const;

  //default constructor
  Tractor();
  //parameterized constructor
  Tractor(const int& x_val, const int& y_val, const unsigned short& size_val, const Activity& activity_val);

}; //end Tractor

//declaration for Game class
class Game
{
private:
  //size of the game map
  unsigned int map_size;
  //list of all tractors on map
  vector<Tractor>all;
  //indexes of all units currently selected in all-vector
  vector<int>selected;


public:
  //default constructor that initializes an empty Game object for the map of new_size
  Game(unsigned int new_size);
  //accessor method for map_size
  unsigned int get_mapsize() const;
  //returns index of tractor that occupies location (x,y). If no unit on (x,y), should return -1
  int GetTractor(int x, int y) const;
  //selects tractor located on (x,y)--involves emptying selected-vector and putting index of selected tractor in it. If no unit at (x,y), method should empty the selected-vector
  void SelectTractor(int x, int y);
  //selects all tractors located in rectangular defined by (x1,y1) and (x2,y2). Add to selected-vector the indexes of all tractors whose square at least partially intersect with the rectangle
  void SelectTractors(int x1, int y1, int x2, int y2);
  //adds the new tractor to all-vector
  void AddTractor(Tractor new_unit);
  //moves the tractor number i if possible and returns true value if successful; if move is not possible, tractor is left at initial position at false value returned; tractor can be moved if it does not overlap with other tractor position or does not go off the map
  bool MoveTractor(int i, int new_x, int new_y);
  //sets the new_activity for all selected tractors
  void AssignTractorsActivity(Activity new_activity);
  //prints tractor number i from the all-vector (prints all fields of that unit)
  void PrintTractor(int i);
  //prints selected units
  void PrintSelectedTractors();
  //prints all units
  void PrintAllTractors();

}; //end Game

#endif

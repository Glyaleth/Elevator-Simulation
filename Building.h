#pragma once
#include <iostream>
using namespace std; 

class Building {
public:
	Building(); //default constructor
	int get_passengers();
	int get_elevators() const; 
	int get_floors();
	int set_passengers(); 
	void set_elevators(int e);
	void set_floors(int f);
private:
	int elevators, floors;
};

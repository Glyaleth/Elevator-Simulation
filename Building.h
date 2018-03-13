#pragma once
#include <iostream>
using namespace std;

class Building {
public:
	Building(int e_num, int p_num); //default constructor
	int get_elevators() const;
	int get_floors();
	void set_elevators(int e);
	void set_floors(int f);
private:
	int elevators, floors;
};

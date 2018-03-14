#pragma once
#include <iostream>
#include "Elevator.h"
#include "Passenger.h"
#include <vector>
#include <queue>
using namespace std;

class Building
{
private:
	int entry_passengers;
	int exit_passengers;
	int elevators, floors, passengers;
	vector <Elevator> Elevator_vec;
	vector <std::queue<Passenger>> Floor_vec;


public:
	Building(int e_num, int f_num); //default constructor

	int get_passengers();
	int get_elevators();
	int get_floors();
	void set_passengers(int p);
	void set_elevators(int e);
	void set_floors(int f);

	int current_pass_in_ele();
	void passenger_entry(int i);
	void passenger_exit(int n);

	void add_Passenger(Passenger the_passenger);
	void Decide();
	void loading_passengers();
};

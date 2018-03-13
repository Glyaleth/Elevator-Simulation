//
//  Elevator_manager.cpp
//  elevator
//

//

#include "Building.h"
#include "Elevator.h"
#include "Passenger.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;



Building::Building(int e_num, int f_num)
{
	elevators = e_num;
	floors = f_num;

	vector <Elevator> Elevator_vec;
	vector <queue<Passenger>> Floor_vec;

	for (int i = 0; i < elevators; i++) { //create i elevators and assign unique IDnumbers
		Elevator my_elev(i);
		Elevator_vec.push_back(my_elev);
	}

	for (int i = 0; i < floors; i++) { //create i floors, put a queue of passengers in each floor
		queue <Passenger> PassengerQ();
		Floor_vec.push_back(PassengerQ);
	}
}

int Building::get_passengers()
{
	return passengers;
}

int Building::get_elevators()
{
	return elevators;
}

int Building::get_floors()
{
	return floors;
}


void Building::set_passengers(int p)
{
	passengers = p;
}

void Building::set_elevators(int e)
{
	elevators = e;
}

void Building::set_floors(int f)
{
	floors = f;
}



int Building::current_pass_in_ele()
{
	return entry_passengers - exit_passengers;
}

void Building::passenger_entry(int i)
{
	entry_passengers += i;
}

void Building::passenger_exit(int n)
{
	exit_passengers += n;
}



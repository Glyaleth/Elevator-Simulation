#include "Building.h"
#include <iostream>
#include "Elevator.h"
#include "Passenger.h"
#include <vector>
#include <queue>
using namespace std;

Building::Building(int e_num, int f_num)
{
	elevators = e_num;
	floors = f_num;

	for (int i = 0; i < elevators; i++) { //create i elevators 
		Elevator my_elev(i); //assign ID Number
		Elevator_vec.push_back(my_elev); //Push into Elevator vector
	}

	for (int i = 0; i < floors; i++) { //create i floors
		queue <Passenger> PassengerQ;
		Floor_vec.push_back(PassengerQ); //put a queue of passengers in each index of the floor vector
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

vector<Elevator> Building::get_ElevatorVec()
{
	return Elevator_vec;
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

vector<queue<Passenger>> Building::get_FloorVec()
{
	return Floor_vec;
}

int Building::current_pass_in_ele()
{
	return entry_passengers - exit_passengers;
}

void Building::passenger_entry(int i)
{
	entry_passengers += i;
}



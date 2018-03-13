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

void Building::add_Passenger(Passenger the_passenger, int direction)
{
	//***TODO*** BUILDING: Create function that takes in a passenger and pushes them into their queue(based on their direction)
	if(direction == 1)//if going up 
		up_requests.push(the_passenger); 
	else if(direction == 2)
		down_requests.push(the_passenger); 
	else
		cout << "Something is wrong with the direction simulator." << endl;
	
	// std::priority_queue<int, std::vector<int>, std::greater<int> third (myints,myints+4) has minimum value at top
	//priority queue has problem of having greatest value at top w/ FIFO

}

void Building::Decide()
{
	//***TODO*** BUILDING: function to iterate through each elevator and decide which floor to go to
	//***TODO*** BUILDING : decide function should call My_Elevator.move(next_floor); -->function to move elevator to next_floor, should return void

}



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

	for (int i = 0; i < elevators; i++) { //create i elevators and assign unique IDnumbers
		Elevator my_elev(i);
		Elevator_vec.push_back(my_elev);
	}

	for (int i = 0; i < floors; i++) { //create i floors, put a queue of passengers in each floor
		queue <Passenger> PassengerQ;
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

void Building::add_Passenger(Passenger the_passenger)
{
	//***TODO*** BUILDING: Create function that takes in a passenger and pushes them into their queue(based on their direction)
	for (int i = 1; i < Floor_vec.size() - 1; i++) {
		if (i == the_passenger.getCurrentFloor())
			Floor_vec[i].push(the_passenger);
	}

}

void Building::Decide()
{
	//***TODO*** BUILDING: function to iterate through each elevator and decide which floor to go to 
	int d_floor;
	for (int i = 0; i < Elevator_vec.size; i++) {
		d_floor = Elevator_vec[i].elev_passenger.front.getDestination();
		if (d_floor > Elevator_vec[i].getCurrentFloor()) { //going up 
			for (int p = 0; p < Elevator_vec[i].elev_passenger.size(); p++) {
				if ((Elevator_vec[i].elev_passenger[p].getDestination() > Elevator_vec[i].getCurrentFloor()) && (Elevator_vec[i].elev_passenger[p].getDestination() < d_floor))
					d_floor = Elevator_vec[i].elev_passenger[p].getDestination();
			}
		}
		else if (d_floor < Elevator_vec[i].getCurrentFloor()) { //going down 
			for (int p = 0; p < Elevator_vec[i].elev_passenger.size(); p++) {
				if ((Elevator_vec[i].elev_passenger[p].getDestination() < Elevator_vec[i].getCurrentFloor()) && (Elevator_vec[i].elev_passenger[p].getDestination() > d_floor))
					d_floor = Elevator_vec[i].elev_passenger[p].getDestination();
			}
		}
		Elevator_vec[i].setCurrentFloor(d_floor);
	}

	//***TODO*** BUILDING : decide function should call My_Elevator.move(next_floor); -->function to move elevator to next_floor, should return void

}

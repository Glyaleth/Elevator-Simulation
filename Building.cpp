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

void Building::passenger_exit(int n)
{
	exit_passengers += n;
}

void Building::add_Passenger(Passenger the_passenger)
{
	Floor_vec[the_passenger.getCurrentFloor()].push(the_passenger);

}

//use double-ended priority queue?-->dequeue
//when we randomly give the passenger a destination &current floor,we store the same passenger in two dequeues(one to decide 
//when to pick them up,one decides when to unload them) and the order we store the passenger in the dequeue will be 
//based on their current floor and destination floor(which floor is closer to the current floor that evevator is on))
//So we can get two priority dequeues
//where we store passenger info?

void Building::Decide()
{





	for (int i = 0; i < Elevator_vec.size(); i++) { //For each elevator in the building
		int d_floor = -1;
		int c_floor = Elevator_vec[i].getCurrentFloor(); //get current floor of elevator
		Elevator current = Elevator_vec[i]; //Save current elevator in temp variable

		if (Floor_vec[c_floor].empty() == false)  //if current floor has passengers, stay on this floor
			d_floor = c_floor;

		else { //else move to another floor


			//IF ELEVATOR NOT CURRENTLY IN USE/IDEL
			if (current.getIdle() == false) {
				d_floor = current.elev_passengers.front().getDestination();

				//GOING UP: 
				if (d_floor > c_floor) {
					for (int p = 0; p < current.elev_passengers.size(); p++) { //for every passenger in the elevator
						//if someone's destination is between current and destination floor --> go there first
						if ((current.elev_passengers[p].getDestination() > c_floor) && (current.elev_passengers[p].getDestination() < d_floor))
							d_floor = current.elev_passengers[p].getDestination();
					}

					int cf = current.getCurrentFloor()+1; //temp variable for current floor
					for (cf; cf < d_floor; cf++) { //for each floor on the way to d_floor
						if (Floor_vec[cf].empty()) //if floor is empty, do nothing
							continue;
						else if (Floor_vec[cf].front().getDirection() == 1) { //if the first person at that floor is also going up
							d_floor = Floor_vec[cf].front().getCurrentFloor();
							break;
						}
						
					}
				}

				//GOING DOWN:
				else if (d_floor < c_floor) {
					for (int p = 0; p < current.elev_passengers.size(); p++) { //for each passenger on the way to d_floor
						//if someone's destination is between current and destination floor --> go there first
						if ((current.elev_passengers[p].getDestination() < c_floor) && (current.elev_passengers[p].getDestination() > d_floor))
							d_floor = current.elev_passengers[p].getDestination();
					}
					int cf = current.getCurrentFloor()-1; //temp variable for current floor
					for (cf; cf > d_floor; cf--) { //for each floor on the way to d_floor
						if (Floor_vec[cf].empty()) //if floor is empty, do nothing
							continue;
						else if (Floor_vec[cf].front().getDirection() == 0) { //if the first person at that floor is also going down
							d_floor = Floor_vec[cf].front().getCurrentFloor();
							break;
						}
					}
				}
			}


			//ELEVATOR NOT IN USE: 
			else if (current.getIdle() == true) {
				for (int k = 0; k < Floor_vec.size(); k++) {
					if (!Floor_vec[k].empty()) { //if there is someone on this floor 
						d_floor = k;//go to that floor
						break;
					}
				}
			}
		}

		Elevator_vec[i].setCurrentFloor(d_floor);
		if (d_floor!=-1)
			this->loading_passengers(i, d_floor);



	}
}

void Building::loading_passengers(int elev, int floor) //looks at all the elevators in the building, it's current floor and if it needs to load any passengers
{

	Passenger p;
	while (Floor_vec[floor].size()>0) {  //while the current floor's queue is not empty
		p = Floor_vec[floor].front(); //save the passenger at the front of the queue
		Floor_vec[floor].front().setOnElevator(true);
		Elevator_vec[elev].load(p); //load into elevator
		Floor_vec[floor].pop(); //remove from the queue
		cout << "LOADING: Passenger " << p.getIDNum() << " on floor [" << floor << "]\n";
	}

}

int Building::unloading_passengers(int count, stack<Passenger>& Exitors)
{
	int num_exited = 0;
	for (int i = 0; i < Elevator_vec.size(); i++) {
		while (Elevator_vec[i].still_exiting()) { //While there are still passengers that need to get off 
			Passenger exit_passenger = Elevator_vec[i].exit();
			exit_passenger.setExitTime(count); //Set the time that the passenger left the elevator to the current count
			Exitors.push(exit_passenger); //store the passenger into the stack of exited passengers
			num_exited++; //Increment the #passengers exited by 1
		}
	}
	return num_exited;


}

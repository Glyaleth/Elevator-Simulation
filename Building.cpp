//Saally Campos 
//Chale Abad
//Thomas Diggs
//Mao Zheng


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

void Building::add_Passenger(Passenger the_passenger)
{
	Floor_vec[the_passenger.getCurrentFloor()].push(the_passenger);
}

int Building::Decide(int count, stack<Passenger>& Exitors)
{
	int num_exited = 0;

	for (int i = 0; i < Elevator_vec.size(); i++) { //For each elevator in the building
		int d_floor = -1; //destination floor 
		int c_floor = Elevator_vec[i].getCurrentFloor(); //get current floor of elevator
		Elevator current = Elevator_vec[i]; //Save current elevator in temp variable

		if (Floor_vec[c_floor].empty() == false)  //if current floor has passengers, stay on this floor
			d_floor = c_floor;

		else { //else move to another floor

			   //IF ELEVATOR NOT CURRENTLY IN USE/IDLE
			if (current.getIdle() == false) {
				d_floor = current.getElevPass().front().getDestination();

				//GOING UP: 
				if (d_floor > c_floor) {
					for (int p = 0; p < current.getElevPass().size(); p++) { //for every PASSENGER in the elevator
																			 // if someone's destination is between current and destination floor --> go there first													 
						if ((current.getElevPass()[p].getDestination() > c_floor) && (current.getElevPass()[p].getDestination() < d_floor))
							d_floor = current.getElevPass()[p].getDestination();
					}

					int cf = current.getCurrentFloor() + 1; //temp variable for current floor
					for (cf; cf < d_floor; cf++) { //for each FLOOR on the way to d_floor
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
					for (int p = 0; p < current.getElevPass().size(); p++) { //for each PASSENGER on the way to d_floor
																			 //if someone's destination is between current and destination floor --> go there first
						if ((current.getElevPass()[p].getDestination() < c_floor) && (current.getElevPass()[p].getDestination() > d_floor))
							d_floor = current.getElevPass()[p].getDestination();
					}
					int cf = current.getCurrentFloor() - 1; //temp variable for current floor
					for (cf; cf > d_floor; cf--) { //for each FLOOR on the way to d_floor
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

		if (d_floor != -1)	//if the destination floor has updated, load the passenger
			this->loading_passengers(i, d_floor);

		
		while (Elevator_vec[i].still_exiting()) { //While there are still passengers that need to get off 
			Passenger exit_passenger = Elevator_vec[i].exit(Elevator_vec[i].getCurrentFloor());
			exit_passenger.setExitTime(count); //Set the time that the passenger left the elevator to the current count
			Exitors.push(exit_passenger); //store the passenger into the stack of exited passengers
			num_exited++; //Increment the #passengers exited by 1
			}
		}
	return num_exited;

	}




void Building::loading_passengers(int elev, int floor)
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


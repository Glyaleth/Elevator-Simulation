#include <iostream>
#include "Building.h"
#include "Elevator.h"
#include "Passenger.h"
#include <vector>
#include <queue>
using namespace std;



Building::Building(int e_num, int f_num)
{
	elevators = e_num;
	floors = f_num;

	for (int i = 1; i <= elevators; i++) { //create i elevators and assign unique IDnumbers
		Elevator my_elev(i);
		Elevator_vec.push_back(my_elev);
	}

	for (int i = 1; i <= floors; i++) { //create i floors, put a queue of passengers in every floor
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

void Building::Decide()
{

	for (int i = 1; i <= Elevator_vec.size(); i++) {
		int d_floor = -1;
		if (Floor_vec[i].empty() == false) { //if current floor has passengers
			d_floor = i;
		}
		else { //else move to another floor
			if (Elevator_vec[i - 1].getIdel() == false) { //If elevator is in use
				d_floor = Elevator_vec[i - 1].elev_passengers.front().getDestination();

				if (d_floor > Elevator_vec[i - 1].getCurrentFloor()) { //going up 
					for (int p = 0; p < Elevator_vec[i - 1].elev_passengers.size(); p++) { //for every passenger in the elevator
						//if someone else in the elevator is going somehwere alone the way (between front's destination and current floor) --> go there first
						if ((Elevator_vec[i - 1].elev_passengers[p].getDestination() > Elevator_vec[i - 1].getCurrentFloor()) && (Elevator_vec[i - 1].elev_passengers[p].getDestination() < d_floor))
							d_floor = Elevator_vec[i - 1].elev_passengers[p].getDestination();

					}
					int cf = Elevator_vec[i - 1].getCurrentFloor(); //get current floor of elevator
					for (cf + 1; cf < d_floor; cf++) { //for each floor on the way to d_floor
						if (Floor_vec[i - 1].front().getDirection()) //if the first person at that floor is also going up
							d_floor = Floor_vec[i - 1].front().getDestination();
					}
				}
				else if (d_floor < Elevator_vec[i - 1].getCurrentFloor()) { //going down 
					for (int p = 0; p < Elevator_vec[i - 1].elev_passengers.size(); p++) {
						if ((Elevator_vec[i - 1].elev_passengers[p].getDestination() < Elevator_vec[i - 1].getCurrentFloor()) && (Elevator_vec[i - 1].elev_passengers[p].getDestination() > d_floor))
							d_floor = Elevator_vec[i - 1].elev_passengers[p].getDestination();
					}
					int cf = Elevator_vec[i - 1].getCurrentFloor(); //get current floor of elevator
					for (cf - 1; cf > d_floor; cf--) { //for each floor on the way to d_floor
						if (Floor_vec[i - 1].front().getDirection()==0) //if the first person at that floor is also going down
							d_floor = Floor_vec[i - 1].front().getDestination();
					}
				}
				

			}
			else if (Elevator_vec[i-1].getIdel() == true) { //If elevator is not in use
				for (int k = 0; k < Floor_vec.size(); k++) {
					if (!Floor_vec[k].empty()) { //if there is someone on this floor 
						d_floor = k;//go to that floor
						break;
					}
				}


			}
		}

		if (d_floor == -1) { //if d floor didn't change
			cout << "Elev " << i << " went nowhere.\n";
		}
		else { //move elevator and load passengers
			cout << "Elev went from floor " << Elevator_vec[i-1].getCurrentFloor();
			Elevator_vec[i-1].setCurrentFloor(d_floor);
			cout << " to " << Elevator_vec[i-1].getCurrentFloor() << endl;
			this->loading_passengers(i-1, d_floor);
		}
	}


}

void Building::loading_passengers(int elev, int floor) //looks at all the elevators in the building, it's current floor and if it needs to load any passengers
{
	
	Passenger p;
	while (!Floor_vec[floor].empty()) {  //while the current floor's queue is not empty
		p = Floor_vec[floor].front(); //save the passenger at the front of the queue
		Elevator_vec[elev].load(p); //load into elevator
		Floor_vec[floor].pop(); //remove from the queue
		cout << p.getIDNum() << " LOADING on floor " << floor << endl;
	}


}

int Building::unloading_passengers(int c, stack<Passenger>& Exitors)
{
	int num_exited=0;

	for (int i = 0; i < Elevator_vec.size(); i++) {
		while (Elevator_vec[i].still_exiting()) { //While there are still passengers that need to get off 
			Passenger exit_passenger = Elevator_vec[i].exit();
			exit_passenger.setExitTime(c); //Set the time that the passenger left the elevator to the current count
			Exitors.push(exit_passenger); //store the passenger into the stack of exited passengers
			num_exited++; //Increment the #passengers exited by 1
		}
	}

	return num_exited;

}
		








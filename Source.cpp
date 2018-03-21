//Saally Campos 
//Chale Abad
//Thomas Diggs
//Mao Zheng

#include <iostream>
#include <string>
#include <array>
#include <stack>
#include <ctime>
#include <vector>
#include "Passenger.h"
#include "Building.h"
#include "Elevator.h"
using namespace std;

void PrintResults(int pass_num, stack <Passenger> Pass_Stack); //takes in number of passengers, stack of passengers, sums it up and prints avg. waiting time
void getInput(int &e_num, int &f_num, int &p_num); //takes in inputs of pass-by references: elevators, floors, and passengers user wants 
int CalcArrivals(int arrived_num, int p_num); //takes in all that have arrived and total passengers wanted, generates random number within range of two 
void PrintPassengers(vector<queue<Passenger>> the_floors); //takes in vector of floors and their queue of passengers, prints who is waiting for the elevator

void main() {
	bool again = true;
	while (again) {
		//WELCOMING MESSAGE:
		cout << "Welcome to the Elevator Simulation! \nPlease insert a number corresponding to one of the options below: \n" << endl;
		cout << "1.Start Simulation\n" << "2.Exit\n" << endl;
		int choice;
		cin >> choice;
		//START SIMULATION:
		if (choice == 1) {
			int e_num = -1; //#elevators
			int f_num = -1; //#floors
			int p_num; //#passengers

			getInput(e_num, f_num, p_num); //gather input

			Building My_Building(e_num, f_num); //pass #elevators and #floors

			int count = 0; //counter to calculate what tick we are at
			int num_arrived = 0; //counts the number of passengers already arrived
			int IDNum_Count = 0; //counter to keep track of what ID numbers are already used
			int num_exited = 0; //counter of passengers who have exited the elevator
			stack <Passenger> Exitors; //stack stores all passengers that have exited the elvevator 
			vector <Elevator> Elevators = My_Building.get_ElevatorVec();

			while (num_exited < p_num) { //while there are still passengers who haven't made it to their destination
				cout << "\n--------------------- COUNT:" << count << " --------------------------- \n";

				int new_arrivals = CalcArrivals(num_arrived, p_num);

				//UPDATE NUM_ARRIVED AND NEW ARRIVALS:
				num_arrived += new_arrivals; //increment passengers arrived
				cout << "New Arrivals: " << new_arrivals << endl;

				//CREATE NEWLY ARRIVED PASSENGERS:
				for (int i = 0; i < new_arrivals; i++) {
					Passenger the_passenger(count, IDNum_Count, f_num); //pass the current count & assign IDNumber
					IDNum_Count++; //increment IDNum_Counter to give each passenger a unique ID (based on priority/ who got here first)
								   //cout << "Passenger " << the_passenger.getIDNum() << ": Current Floor [" << the_passenger.getCurrentFloor() << "], Destination: [" << the_passenger.getDestination() << "]\n";

					My_Building.add_Passenger(the_passenger);//add passenger to Building's queue of passengers depending on floor
				}

				//Print off each person on each floor to keep track of who is still waiting
				vector<queue<Passenger>> the_floors = My_Building.get_FloorVec();
				PrintPassengers(the_floors);

				//After adding the new passengers & data, have the building manager decide what all elevators should do next
				My_Building.Decide();

				//Once elevator has moved, unload the passengers & count how many got off
				num_exited += My_Building.unloading_passengers(count, Exitors);

				count++;
			}
			//After all passengers have exited the elevator, simulation is over, print the results
			PrintResults(p_num, Exitors);
		}
		else if (choice == 2) { //if user wants to exit simulation
			return;
		}
	}
	system("pause");
}

void PrintResults(int pass_num, stack <Passenger> Pass_Stack)
{
	cout << "\nCONCLUSION:                            Total Passengers: " << pass_num << endl;
	double sum = 0;
	//ITERATE THROUGH PASSENGER STACK, SUM WAIT TIMES:
	for (int i = 0; i < pass_num; i++) {
		Passenger current = Pass_Stack.top();
		sum += current.getWaitTime();
		Pass_Stack.pop();
	}
	//OUTPUT AVERAGE:
	cout << "                                    Average Wait Time: " << sum / pass_num << "\n__________________________________________________________";
	cout << endl << endl;
}

void getInput(int &e_num, int &f_num, int &p_num) //input elevators, floors, and passengers
{
	cout << "_________________________________________________________\n\nTo begin the Elevator Simulation:" << endl;
	//INPUT ELEVATORS:
	cout << "Please enter the number of elevators you want: ";
	cin >> e_num;
	//INPUT FLOORS:
	cout << "Please enter the number of floors you want in the building: ";
	cin >> f_num;
	while (f_num <= 1) { //must have more than 1 floor
		cout << "You must have at least 2 floors.\n";
		cin >> f_num;
	}
	//INPUT PASSENGERS:
	cout << "Please enter the number of passengers you want to show up: ";
	cin >> p_num;
	while (p_num <= 0) {
		cout << "You must have at least 1 passenger.\n";
		cin >> p_num;
	}
	cout << "\nProcessing simulation... \n\n";
}

int CalcArrivals(int arrived_num, int p_num)
{
	int new_arrivals;
	//ALL PASSENGERS SIMULATED:
	if (arrived_num >= p_num) //if the arrived passengers >= total passengers wanted
		new_arrivals = 0;
	//STILL NEED PASSENGERS:
	else
		new_arrivals = rand() % (p_num - arrived_num) + 1; //random # from 0 to (total passengers-already arrived) 
	return new_arrivals;
}

void PrintPassengers(vector<queue<Passenger>> the_floors)
{
	//Print out list of passengers still waiting to get on elevator
	for (int k = 0; k < the_floors.size(); k++) {
		while (the_floors[k].empty() == false) {//if there is someone there
			cout << "Passenger " << the_floors[k].front().getIDNum() << ": Current Floor [" << the_floors[k].front().getCurrentFloor() << "], Destination: [" << the_floors[k].front().getDestination() << "]\n";
			the_floors[k].pop();
		}
	}
}

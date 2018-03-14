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




void PrintResults(int pass_num, stack <Passenger> Pass_Stack);
void getInput(int &e_num, int &f_num, int &p_num);

void main() {
	bool again = true;
	while (again) {

		cout << "Elevator Simulation\n" << endl;
		cout << "1.Start Simulation\n" << "2.Exit\n" << endl;
		int choice;
		cin >> choice;

		if (choice == 1) {
			int e_num=-1; //#elevators
			int f_num=-1; //#floors
			int p_num; //#passengers
			
			getInput(e_num, f_num, p_num); 

			Building My_Building(e_num, f_num); //pass #elevators and #floors
			
			Elevator My_Elevator(25); 

			int count = 0; //counter to calculate what tick we are at
			int num_arrived = 0; //counts the number of passengers already arrived
			int IDNum_Count = 0; //counter to keep track of what ID numbers are already used
			int num_exited=0; //counter of #passengers who have exited the elevator

			stack <Passenger> Exitors; //Stack stores all passengers that have exited the elvevator 

			while (num_exited < p_num) { //while there are still passengers who haven't made it to their destination
				cout << "COUNT: " << count << "\n";
				srand(time(NULL));

				int new_arrivals;
				if (num_arrived >= p_num) {
					new_arrivals = 0;
				}
				else
					new_arrivals = rand() % p_num - num_arrived + 0; //random # from 0-3 for passengers that just arrived

				num_arrived += new_arrivals;


				//Create Passengers
				for (int i = 0; i < new_arrivals; i++) {
					Passenger the_passenger(count, IDNum_Count, f_num); //Create a passenger pass the current count & assign IDNumber
					IDNum_Count++; //Increment IDNum_Counter to give each passenger a unique ID (based on priority, who got here first)

					My_Building.add_Passenger(the_passenger);
				}



				//Decide where to go
				//After adding the new passengers & data, have the building manager decide what all elevators should do next
				My_Building.Decide();



				//Once all elevators have moved to their new floor, pop out passengers

				//THIS NEEDS TO BE DONE FOR EACH ELEVATOR


				while (My_Elevator.still_exiting()) { //While there are still passengers that need to get off of the elevator 

					Passenger exit_passenger = My_Elevator.exit();



					exit_passenger.setExitTime(count); //Set the time that the passenger left the elevator to the current count

					

					Exitors.push(exit_passenger); //store the passenger into the stack of exited passengers
					num_exited++; //Increment the #passengers exited by 1
				}


				//After popping out passengers, start pushing new passengers into elevator
				//THIS NEEDS TO BE DONE FOR EACH ELEVATOR 

				/*
				while (!My_Elevator.StillLoading()) {//While there are still people that need to get into the elevator


					Passenger loading_passenger;


					cout << "Passenger #" << loading_passenger.getIDNum() << " is on elevator #..." << " and is headed to floor #..." << loading_passenger.getDestination() << endl;

					My_Elevator.load(loading_passenger);


				}
				*/


				Passenger loading_passenger;
				My_Elevator.load(loading_passenger);







				//After moving elevator, loading/exiting passengers, increment the counter and loop again
				count++;
				

			}


			//After all passengers have exited the elevator, simulation is over, print the results
			PrintResults(p_num, Exitors);


		}



		else if (choice == 2) {
			return;
		}

		
	}


system("pause");


}






void PrintResults(int pass_num, stack <Passenger> Pass_Stack)
{
	cout << "Total Passengers:" << pass_num<< endl;
	
	//Ittereate through Passenger stack, sum up the wait times
	double sum = 0;
	/*
	for (int i = 0; i < pass_num; i++) {
		Passenger current = Pass_Stack.top();
		sum += current.getWaitTime();
		Pass_Stack.pop();
	}
	*/

	
	cout << "Average Wait time:" << sum / pass_num<< endl;
	
	
	cout << endl << endl;


}

void getInput(int &e_num, int &f_num, int &p_num) //#Elevator, #Floors, #passengers
{
	cout << "Begin Elevator Simulation" << endl;

	cout << "Please enter the number of elevators you want to see simulated(1 to 10):" << endl;
	cin >> e_num;
	while (e_num <= 0 || e_num > 10) { 
		cout << "You must enter a number between 1 and 10\n";
		cin >> e_num;
	}

	cout << "Please enter the number of floors in the building" << endl;
	cin >> f_num;

	while (f_num <= 1 ) { //must have more than 1 floor
		cout << "You must have at least 2 floors\n";
		cin >> f_num;
	}


	cout << "Please enter the number of passenger" << endl;
	cin >> p_num;
	while (p_num <= 0) {
		cout << "You must have at least 1 passenger\n";
		cin >> p_num;
	}
}


#include <iostream>
#include <string>
#include<array>
#include <stack>
#include "Passenger.h"
#include "Building.h"
#include "Elevator.h"
using namespace std;


/*OVERALL THINGS THAT WE NEED TO DO:


Building My_Building(e_num, p_num); //***TODO*** Create Constructor that takes in #elevator & #floors, assigns values and 'creates' the building
//***TODO*** We need a way to keep track of all of our elevators, either in the Main or in the Building class...

Elevator My_Elevator(); //Contructor for the elevator?? Maybe this should be within Building??

int new_arrivals = rand(); //***TODO*** create random function that generates a random # from (x,y)

My_Building.add_Passenger(the_passenger, the_passenger.getDirection()); //***TODO*** Create function in Building that takes in a passenger and pushes them into their queue (based on their direction)

My_Building.Decide(); //***TODO*** Building function iterate through each elevator and decide which floor to go to
//***TODO*** Within Building, decide function should call My_Elevator.move(next_floor); -->function to move elevator to next_floor, should return void

//Once arriving all elevators have moved to their new floor, pop out passengers
//THIS NEEDS TO BE DONE FOR EACH ELEVATOR
while (!My_Elevator.StillExiting()) { //***TODO*** Create a bool .StillExiting() that checks if there are still passengers that need to get "popped" out of the elevator

Passenger exit_passenger = My_Elevator.Exit(); //***TODO*** Create function to decide who needs to get off on the current floor it is on
//***TODO** .Exit() should somehow return the passenger that just exited the elevator

//After popping out passengers, start pushing new passengers into elevator
//THIS NEEDS TO BE DONE FOR EACH ELEVATOR

while (!My_Elevator.StillLoading()) { //***TODO*** create bool StillLoading function that checks if there is still anyone on the current floor that needs to be loaded in

Passenger loading_passenger; //**TODO*** how do we know who need to get on the elevator?

My_Elevator.load(loading_passenger, loading_passenger.getDestination()); //***TODO*** Create Elevator function to load a passenger into the elevator
//**Function takes in the passenger getting loaded, and their destination floor, and returns void??



*/




void PrintResults(int pass_num, stack <Passenger> Pass_Stack);

void main() {
	bool again = true;
	while (again) {
		cout << "Elevator Simulation\n" << endl;
		cout << "1.Start Simulation\n" << "2.Exit\n" << endl;
		int choice;
		cin >> choice;

		if (choice == 1) {
			int e_num, f_num, p_num; //#Elevator, #Floors, #passengers
			cout << "Begin Elevator Simulation" << endl;
			cout << "Please enter the number of elevators you want to see simulated(1 to 10):" << endl;
			cin >> e_num;
			cout << "Please enter the number of floors in the building" << endl;
			cin >> f_num;
			cout << "Please enter the number of passenger" << endl;
			cin >> p_num;

			Building My_Building(e_num, p_num); //***TODO*** Create Constructor that takes in #elevator & #floors, assigns values and 'creates' the building
			//***TODO*** We need a way to keep track of all of our elevators, either in the Main or in the Building class...
			Elevator My_Elevator();

			int count = 0, num_arrived = 0, IDNum_Count = 0, num_exited; //counter to calculate wait time, #of passengers already arrived, #passengers who have exited the elevator
			stack <Passenger> Exitors; //Stack stores all passengers that have exited the elvevator 


			while (num_exited < p_num) { //while there are still passengers who haven't made it to their destination
				int new_arrivals = rand(); //***TODO*** create random function that generates a random # from (x,y)

				//Create Passengers
				for (int i = 0; i < new_arrivals; i++) {
					Passenger the_passenger(count, IDNum_Count); //Create a passenger that arrived at the current count & assign them an IDNumber
					IDNum_Count++; //Increment IDNum_Counter to give each passenger a unique ID (based on priority, who got here first)
					My_Building.add_Passenger(the_passenger, the_passenger.getDirection()); //***TODO*** Create function in Building that takes in a passenger and pushes them into their queue (based on their direction)
				}



				//Decide where to go
				//After adding the new passengers & their data, have the building manager decide what all elevators should do next
				My_Building.Decide(); //***TODO*** Building function iterate through each elevator and decide which floor to go to
					//***TODO*** Within Building, decide function should call My_Elevator.move(next_floor); -->function to move elevator to next_floor, should return void

			
				//Once arriving all elevators have moved to their new floor, pop out passengers

				//THIS NEEDS TO BE DONE FOR EACH ELEVATOR
				while (!My_Elevator.StillExiting()) { //***TODO*** Create a bool .StillExiting() that checks if there are still passengers that need to get "popped" out of the elevator 
					//While there are still passengers that need to get off of the elevator 
					Passenger exit_passenger = My_Elevator.Exit(); //***TODO*** Create function to decide who needs to get off on the current floor it is on
															  //***TODO** .Exit() should somehow return the passenger that just exited the elevator

					exit_passenger.setExitTime(count); //Set the time that the passenger left the elevator to the current count
					
					cout << "Passenger #" << exit_passenger.getIDNum() << " has arrived at floor: \n";
					
					Exitors.push(exit_passenger); //store the passenger into the stack of exited passengers
					num_exited++; //Increment the #passengers exited by 1
				}

				//After popping out passengers, start pushing new passengers into elevator
				//THIS NEEDS TO BE DONE FOR EACH ELEVATOR 
				//While there are still people that need to get into the elevator
				while (!My_Elevator.StillLoading()) { //***TODO*** create bool StillLoading function that checks if there is still anyone on the current floor that needs to be loaded in
					Passenger loading_passenger; //**TODO*** how do we know who need to get on the elevator? 
					cout << "Passenger #" << loading_passenger.getIDNum() << " in on elevator #..." << " and is headed to floor #...\n";
					My_Elevator.load(loading_passenger, loading_passenger.getDestination()); //***TODO*** Create Elevator function to load a passenger into the elevator
																											//**Function takes in the passenger getting loaded, and their destination floor, and returns void??

				}
				

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
	for (int i = 0; i < pass_num; i++) {
		Passenger current = Pass_Stack.top();
		sum += current.getWaitTime();
		Pass_Stack.pop();
	}

	
	cout << "Average Wait time:" << sum / pass_num<< endl;
	
	
	cout << endl << endl;


}


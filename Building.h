//Saally Campos 
//Chale Abad
//Thomas Diggs
//Mao Zheng


#pragma once
#include <iostream>
#include "Elevator.h"
#include "Passenger.h"
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Building
{
private:
	int elevators, floors;
	vector<Elevator> Elevator_vec; //vector to hold all elevators in the building
	vector<queue<Passenger>> Floor_vec; //vector to hold all floors, each floor has a queue of passengers

public:
	Building(int e_num, int f_num); //constructor
	int get_elevators();
	int get_floors();
	vector <Elevator> get_ElevatorVec();
	vector<queue<Passenger>> get_FloorVec();
	void set_elevators(int e);
	void set_floors(int f);
	void add_Passenger(Passenger the_passenger); //adds passenger to Floor_vec with queue of passengers according to passenger's floor 
	int Decide(int count, stack<Passenger>& Exitors);//decides where each elevator needs to go according to the count
	void loading_passengers(int elev, int floor); //takes in elevator number and floor, loads accordingly
};
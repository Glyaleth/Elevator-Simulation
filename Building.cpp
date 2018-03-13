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

/*void get_entry_pass(){
    cout<<"initially,how many passenger entered the elevator"<<endl;
    cin<<entry_passengers;
}*/
void passenger_entry(int i){
    entry_passengers+=i;
    
}
void passenger_exit(int n){
    exit_passengers+=n;
}
int current_pass_in_ele(){
    return entry_passengers-exit_passengers;
}

Building::Building()
{
    elevators = 0;
    floors = 0;
}

int Building::get_elevators()
{
    return elevators;
}

int Building::get_floors()
{
    return floors;
}

void Building::set_elevators(int e)
{
    elevators = e;
}

void Building::set_floors(int f)
{
    floors = f;
}
void Elevator_Floor(e_num,f_num){
    vector<Elevator>Elevator(e_num);
    vector<queue<Passenger>>Floor;//queue stores the passenger waiting at that floor
    Floor.push_back(queue<Passenger>()); // add a queue
    Floor[0].push(Passenger());
}





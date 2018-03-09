//
//  Elevator_manager.cpp
//  elevator
//

//

#include "Elevator_manager.h"
#include <iostream>
using namespace std;

void get_entry_pass(){
    cout<<"initially,how many passenger entered the elevator"<<endl;
    cin<<entry_passengers;
}
void passenger_entry(int i){
    entry_passengers+=i;
    
}
void passenger_exit(int n){
    exit_passengers+=n;
}
int current_pass_in_ele(){
    return entry_passengers-exit_passengers;
}





//
//  main.cpp
//  building manager

#pragma once
#include "main.h"
#include <iostream>
using namespace std;



class Building
{
protected:
    int entry_passengers;
    int exit_passengers;
    int elevators, floors;
public:
    //void get_entry_pass();
    int current_pass_in_ele();
    void passenger_entry(int i);
    void passenger_exit(int n);
    Building(); //default constructor
    int get_passengers();
    int get_elevators();
    int get_floors();
    int set_passengers(int p);
    void set_elevators(int e);
    void set_floors(int f);
    void Elevator_Floor(e_num,f_num)
    
};




//
//  main.cpp
//  Elevetor



#include <iostream>
#include<array>
using namespace std;

//functions
void start_elevator();
void print(int pass_num,int t);

void main(){
    bool again=true;
    int p,t;//total_passenger,avg wait time
    while(again){
        again=false;
        cout<<"Elevator Simulation"<<endl;
        cout<<"1.Start Simulation"<<"2.Print Report"<<"3.Play again"<<"4.Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            start_elevator();
        }
        else if(choice==2){
            print(p,t);
        }
        else if(choice==3){
            again=true;
        }
        else if(choice==4){
            return;
        }

    }
    }
void start_elevator(){
    int e_num,f_num,p_num;
    cout<<"Begin Elevator Simulation"<<endl;
    cout<<"Please enter the number of elevators you want to see simulated(1 to 10):"<<endl;
    cin>>e_num;
    cout<<"Please enter the number of floors in the building"<<endl;
    cin>>f_num;
    cout<<"Please enter the number of passenger"<<endl;
    cin>>p_num;
    //put these values in your class
    
    
}

void print(array<int,50>pass,int t){
    cout<<""<<endl;//passenger arrive/exit/in the elevator
    cout<<"Total Passengers:"<<endl;
    cout<<"Average Wait time:"<<endl;
    for (int i=0;i<pass.size();i++)
    {
        if (pass[i])
            cout << (i+1) << "\t" << pass[i] << endl;
        else
            cout << (i+1) << "\t" << 0 << endl;
    }
    cout << endl << endl;
    
}

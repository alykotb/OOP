//============================================================================
// Name        : OOP_Assig.cpp
// Author      : aly
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Flight.h"
#include"flight_schedule.h"
#include "flight_schedule.cpp"
#include "Control.h"
#include "Control.cpp"



int main()
{
	char* countries[3]={"Almanya","Hollanda","Italy"};
	  int Durations[3]={65,70,80};
	int launch_hour[3]={20,18,5};
	 int launch_min[3]={30,15,40};
	 

	 
	 
    FlightController<int> myController;
    



	int i;
//	Flight Test[3];
	for(i=0;i<3;i++)
	{
//	  myController.flight_schedule.Flights[i] = Flight(countries[i],Durations[i],launch_hour[i],launch_min[i]);
	  
//	  flights_data.Flights[i]= Flight(countries[i],launch_hour[i],launch_min,Durations[i]);

	}

	return 0;
}

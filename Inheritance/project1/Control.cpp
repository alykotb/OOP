#include <iostream>
using namespace std;
#include "Control.h"
#include "Flight.h"
#include"flight_schedule.h"
#include "flight_schedule.cpp"
#include <algorithm>

template<class type>
void LaunchController<type>::launchSchedule(FlightSchedule<type> *ptr)
{
  	int j;	
   for(int i=0;i<3-1;i++)	
   {
   	for (j= 0 ;  j< 3 - i- 1; j++)
    {
      if ((ptr->Flights[j].getlaunchHour())>=(ptr->Flights[j+1].getlaunchHour())) 
      {
        if ((ptr->Flights[j].getlaunchHour())==(ptr->Flights[j+1].getlaunchHour()))  
	   {
			   	
      	if((ptr->Flights[j].getlaunchMin())>=(ptr->Flights[j+1].getlaunchMin()))
      		
			if((ptr->Flights[j].getlaunchMin())==(ptr->Flights[j+1].getlaunchMin()))  
			{      			
			  ptr->Flights[j+1].setState("Delayed");
            }
            else
            {
            	swap(ptr->Flights[j],ptr->Flights[j+1]);
			}
       }  
	         
	   else
	     
	     {
	        swap(ptr->Flights[j],ptr->Flights[j+1]);
	     }
      }
    }
   }
   cout<<"Launch Order:"<<endl;
    int k;
    for(k=0;k<3;k++)
    {
    	
    	cout<<ptr->Flights[k].getName()<<" "<<"Launches at"<<"  "<<ptr->Flights[k].getlaunchHour()<<":"<<ptr->Flights[k].getlaunchMin()<<" "
		<<"Flight State:"<<ptr->Flights[k].getState()<<endl;
	}
}

template<class type>
void LandController<type>::landingSchedule(FlightSchedule<type> *ptr)
{
	int j;	
   for(int i=0;i<3-1;i++)	
   {
   	for (j= 0 ;  j< 3 - i- 1; j++)
    {
      if ((ptr->Flights[j].getlandHour())>=(ptr->Flights[j+1].getlandHour())) 
      {
      if ((ptr->Flights[j].getlandHour())==(ptr->Flights[j+1].getlandHour()))  
	   {
			   	
      	if((ptr->Flights[j].getlandMin())>=(ptr->Flights[j+1].getlandMin()))
      		
			if((ptr->Flights[j].getlandMin())==(ptr->Flights[j+1].getlandMin()))  
			{      			
			  ptr->Flights[j+1].setState("Delayed");
            }
            else
            {
            	swap(ptr->Flights[j],ptr->Flights[j+1]);
			}
       }  
	         
	   else
	     
	     {
	        swap(ptr->Flights[j],ptr->Flights[j+1]);
	     }
    }
   }
}

cout<<"Landing Order:"<<endl;
    int k;
    for(k=0;k<3;k++)
    {
    	
    	cout<<ptr->Flights[k].getName()<<" "<<"Lands at"<<"  "<<ptr->Flights[k].getlandHour()<<":"<<ptr->Flights[k].getlandMin()<<" "
		<<"Flight State:"<<ptr->Flights[k].getState()<<endl;
	}

}
template<class type>
FlightController<type>::FlightController():flight_schedule()
{

	flights=&flight_schedule;
	LaunchController<type>::launchSchedule(flights);
	LandController<type>::landingSchedule(flights);
}






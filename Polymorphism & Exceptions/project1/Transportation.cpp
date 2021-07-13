#include <iostream>

using namespace std;

class Transportation
{
    protected:
    	double weight;
    	double routeDistance;
    	double initialFuel;
    	double requiredFuel;
    	double fuelConsumption;
	public:
	    Transportation()
		{
			
			
	    }	
	   virtual void checkAvailability()=0;
	   ~Transportation()
		{	
	    }
  friend istream& operator>>(istream& input,Transportation& obj)
	    {
	    	 cout<<"Enter the wieght of the cargo: ";
             cin>>obj.weight;
             cout<<endl;
             cout<<"Enter the travel distance: ";
			 cin>>obj.routeDistance;
			 cout<<endl;
			 return input;	    	
		}
};
 
class Truck: public Transportation
{
  public:	
	     Truck()
	     {
	     	cout<<"A truck is on hold for current transportation"<<endl;
	     	cout<<"Enter the amount of initial fuel: ";
	     	cin>>initialFuel;
	     	cout<<endl;
	     	fuelConsumption=30;
		 }
		 void checkAvailability()
		 {		    
			fuelConsumption= 30.0+(weight*1.0);
		    requiredFuel=(routeDistance*fuelConsumption)/100.0; /*cross multiplication*/
		   try
		   { 
		    if(requiredFuel>initialFuel)
		    {
		       throw ((int)(requiredFuel-initialFuel));
		      /*exception will ber thrown here*/	
			}
			else
			{
			   cout<<"Sufficient amount of fuel in truck"<<endl;
			   cout<<"Transportation ship can reach destination in single trip"<<endl;	
			}
		  }
		  catch(int fuel)
		  {
		  	cout<<"Transportation truck needs to refuel at the station."<<endl;
			cout<<"Need to refuel "<<fuel <<" more"<<endl;		  	
		  }
	   }
};

class Ship: public Transportation
{
  public:	
	     Ship()
	     {
	     	cout<<" A cargo ship is on hold for current transportation: "<<endl;
	     	cout<<"Enter the amount of initial fuel: ";
	     	cin>>initialFuel;
	     	cout<<endl;
	     	fuelConsumption=60;
		 }
		  void checkAvailability()
		 {
		    fuelConsumption = 60+(weight*0.5);
		    requiredFuel=(routeDistance*fuelConsumption)/100; /*cross multiplication*/
		try{
		    if(requiredFuel>initialFuel)
		    {
		    	  throw ((int) (requiredFuel-initialFuel));
		    	/*exception will ber thrown here*/
			}
			else
			{
			   cout<<"Sufficient amount of fuel in ship"<<endl;	
			   cout<<"Transportation ship can reach destination in single trip"<<endl;
			}
	       }
			catch(int fuel)
		   {
		  	 cout<<"Transportation ship needs to refuel at the station."<<endl;
			 cout<<"Need to refuel "<<fuel <<" more"<<endl;  	
		   }
	     }
};





int main()
{
	Ship myship;
	cin>>myship;
	myship.checkAvailability();
	cout<<endl;
	Truck myTruck;
	cin>>myTruck;
	myTruck.checkAvailability();
	return 0;
}


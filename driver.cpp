//
// Created by Shane Humphrey on 10/13/20.
//
#include "Route.h"
#include "Train.h"
int main(){
  const string routeFile = "proj3_routes.txt";
  const string passFile = "proj3_passengers.csv";
  Route* link = new Route();
  link->LoadRoute(routeFile);
  Train* rail = new Train(link);
  int choice = 0;
  while(choice != 6) 
  {
    if (choice == 0)
      choice = 1;
    else if (link->GetCurrentStop()->GetNextStop()) {
      rail->LoadPassengers(passFile);
      rail->DisembarkPassengers();
      rail->TrainStatus();
      rail->TravelToNextStop();
    }
    else
      rail->TurnTrainAround();
	cout<< "want to continue?(y/n)\n";
	
    char continyou;
    
    cin >> continyou;
    
    if(continyou == 'n')
      choice = 6;
  }
  cout << "Thank you for working with the Baltimore Light Rail." << endl;
  cout << "Removing all passengers, trains, and routes" << endl;
  delete link;
  delete rail;
  return 0;
}
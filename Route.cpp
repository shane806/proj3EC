//
// Createsd by Shane Humphrey on 10/13/20.
//

#include <string>
#include <iostream>
#include "Stop.cpp"
#include "Route.h"
using namespace std;

//Routes are the route a train would take from stop to stop
//In this case, it is a linked lists that is made up of stops (nodes)

/*
   Name: Route() - Default Constructor
   Desc - Creates a new empty route
   Preconditions - None
   Postconditions - Sets everything to either nullptr or 0
*/
const int NUM_ROUTE_COLS = 2;

Route::Route(){
  m_head = nullptr;
  m_tail = nullptr;
  m_currentStop = nullptr;
  m_totalStops = 0;
}

/*
   Name: ~Route - Destructor
   Desc - Removes all of the stops from the route
   Preconditions - Route must have nodes
   Postconditions - Route will be empty and m_head and m_tail and m_currentStop
                    will be nullptr and m_totalStops will be 0
*/
Route::~Route(){

  Stop* curr = m_head;
  while(curr){
    m_head = m_head->GetNextStop();

    delete curr;
    curr = m_head;
    m_totalStops--;
  }
  m_head = nullptr; m_tail = nullptr; m_currentStop = nullptr;
  cout << "total stops remaining: " << m_totalStops << endl;
}
/*
   Name: LoadRoute(string)
   Desc - Reads the route file and calls AddStop once per line.
          Increments m_totalStops.
   Preconditions - Route allocated and file available
   Postconditions - Populates route with stops. Sets m_currentStop to m_head when load completed.
*/
void Route::LoadRoute(string routeFile) {
  ifstream routeStream (routeFile);

  string line; string stopName; int stopNum;
  int i = 0;

  while (getline(routeStream, line, ',')) {
    if (i < NUM_ROUTE_COLS - 1)
      stopName = line;

    i++;
    if (i == NUM_ROUTE_COLS - 1)
    {
      getline(routeStream, line);
      stopNum = stoi(line);

      AddStop(stopName, stopNum);

      cout << "stopName: " << stopName << endl;
      cout << "stopNum: " << stopNum << endl;
      m_totalStops++; i = 0;
    }
  }
  routeStream.close();
  m_currentStop = m_head;
}

/*
   Name: AddStop(string, int)
   Desc - Allocates new stop and inserts in end of route
   Preconditions - Route allocated and data for stop available
   Postconditions - New stop inserted in end of route
*/
void Route::AddStop(string stopName, int stopNum) {
  Stop* newStop = new Stop(stopName, stopNum);

  if (!m_head)
    m_head = newStop;
  else
    m_tail->SetNextStop(newStop);
  m_tail = newStop;
}
/*
   Name: PrintRouteDetails()
   Desc - Prints information about the next stop on the route
   Preconditions - Route allocated and data for next stop available
   Postconditions - Outputs data only
*/
void Route::PrintRouteDetails()
{
  cout << "\n  Current stop: "
       << GetCurrentStop()->GetName() << endl;

  if (GetCurrentStop()->GetNextStop()){
    cout << "\n  Next stop: "
         << GetCurrentStop()->GetNextStop()->GetName() << endl;
  }
}

/*
   Name: GetCurrentStop
   Desc - Returns the m_currentStop
   Preconditions - m_currentStop has been assigned
   Postconditions - Returns the pointer
*/
Stop* Route::GetCurrentStop(){
  return m_currentStop;
}
/*
   Name: SetCurrentStop
   Desc - Updates m_currentStop
   Preconditions - m_currentStop is available
   Postconditions - Updates m_currentStop as the train moves
*/
void Route::SetCurrentStop(Stop* currStop){
  m_currentStop = currStop;
}
/*
   Name: ReverseRoute
   Desc - At the end of a route, the route can
          be reversed (as in the train turns around)
   Recommendations - Code this function last (dead last)
   Preconditions - Route has been completed
   Postconditions - Replaces old route with new reversed route.
*/
void Route::ReverseRoute() {
  Stop* currStop = m_head, *pastStop = nullptr, *futureStop = nullptr;

  while (currStop)
  {
    futureStop = currStop->GetNextStop();
    currStop->SetNextStop(pastStop);
    pastStop = currStop;
    currStop = futureStop;
  }
  m_tail = m_head; m_head = pastStop; m_currentStop = m_head;
}

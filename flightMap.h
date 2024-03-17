#include <iostream>
#include <fstream>
using namespace std;

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"
#include <vector>
#include <list>

using namespace std;

class flightMap
{
	public:
		//constructors and destructor

		flightMap();
		flightMap(const flightMap& rhs);
		~flightMap();
		
		//FlightMapClass operations:

		istream& read_cities(istream& in);
		//Read cities from a data file
		//Pre-condition: Input stream is provided
		//Post-condition: Data file is read
		//				  Cities are in ascending order


		istream& read_flights(istream& in);
		//Reads flight information and build the adjacency list
		//Pre-condition: list of the flight information is provided
		//Post-condition: Flight map is built

		void sort_flights();

		friend ostream& operator<< (ostream& out, const flightMap& f);
		//Displays the flight map in a formatted table
			// using overloaded << opererator
		//Pre-condition: none
		//Post-condition: Flight map is displayed

	private:
		//rewrite
		int numOfCities;
		vector <string>* cities;
		list <flightRec>* flights;

		//number of cities
		//vector of cities
		//flight map
};

#endif

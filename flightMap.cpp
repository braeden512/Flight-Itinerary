//include statements
#include "flightMap.h"
#include "type.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iomanip>

//default constructor
flightMap::flightMap(){
	cities = new vector<string>;
	flights = new list<flightRec>;
}

//copy constructor
flightMap::flightMap(const flightMap& f){
	numOfCities = f.numOfCities;
	cities = f.cities;
	flights = f.flights;
}

//destructor
flightMap::~flightMap(){
	delete flights;
	delete cities;
}

/*
function: read_cities - read in the cities from the file
input: input stream
return: input stream
*/
istream& flightMap::read_cities(istream& in){
	in >> numOfCities;
	while (in){
		string city;
		in >> city;
		cities->push_back(city);
	}
	return in;
}

/*
function: read_flights - read in the flights from the file
input: input stream
return: input stream
*/
istream& flightMap::read_flights(istream& in){
	flightRec temp;
	while (in){
		in >> temp.flightNum;
		in >> temp.origin;
		in >> temp.destination;
		in >> temp.price;
		flights->push_back(temp);
	}
	return in;
}

/*
function: sort_flights - sort the flights in alphabetical order
input: none
return: none
*/
void flightMap::sort_flights() {
	// Sorting the flights by origin city
	flights->sort([](const flightRec& first_flight, const flightRec& second_flight) {
		return first_flight.origin < second_flight.origin;
	});

	// Sorting each origin city's flights by destination city
	for (auto iter = flights->begin(); iter != flights->end(); ++iter) {
		// Finding the first flight with the same origin city
		auto current_origin = iter->origin;
		auto iter2 = iter;
		// Move to the next flight in the list
		std::advance(iter2, 1);
		while (iter2 != flights->end() && iter2->origin == current_origin) {
			if (*iter2 < *iter) {
				std::swap(*iter, *iter2);
			}
			++iter2;
		}
	}
}


/*
function: insertion operator overload - overload the insertion operator to print the flight map
input: output stream, flightMap object
return: output stream
*/
ostream& operator<< (ostream& out, const flightMap &f) {
	//printing the header
	out << left << setw(23) << "     Origin" << setw(18) << "Destination" << setw(10) << "Flight" << setw(10) << "Price" << endl;
	out << "============================================================" << endl << endl;

	flightRec temp;
	string s;
	int aligner = 0;

	// Declare iterators explicitly
	typedef list<flightRec>::const_iterator Iter;
	typedef list<flightRec>::const_iterator InnerIter;

	// Iterate through the list using iterators
	for (Iter iter = f.flights->begin(); iter != f.flights->end(); ++iter) {
		if (iter->origin != temp.origin) {
			temp = *iter;
			aligner = 0;
			s = "From " + temp.origin + " to:";
			out << setw(23) << s;

			// Iterate through the list again to print flights with the same origin
			for (InnerIter inner_iter = iter; inner_iter != f.flights->end(); ++inner_iter) {
				if (inner_iter->origin == temp.origin) {
					s = "$" + to_string(inner_iter->price);
					out << setw(aligner) << "" << setw(18) << inner_iter->destination << setw(10) << inner_iter->flightNum << setw(10) << s << endl;
					aligner = 23;
				}
			}
		}
	}
	return out;
}

/* 
 Braeden Treutel
 Program Description:    
	This project is a flight itinerary that produces a compact block of text, telling what cities you can fly to and how much it will cost.
	The input of the program are two data files, one with the flights and the other with the cities.       
	The output of the program is the block of text that tells you what cities you can fly to and how much it will cost.
*/ 


//include statements
#include <iostream>
#include <fstream>
#include "type.h"
#include "flightMap.h"

using namespace std;

int main() {

	//making the flightmap object
	flightMap f;

	//read in both files
	ifstream inFile("cities.dat");
	ifstream inFile2("flights.dat");
	//using these functions to read in from each file
	f.read_cities(inFile);
	f.read_flights(inFile2);
	//sort the flights in alphabetical order
	f.sort_flights();

	//print out the table
	cout << f;

	//close the files
	inFile.close();
	inFile2.close();

	return 0;
}

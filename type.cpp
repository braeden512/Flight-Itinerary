#include "type.h"

#include <iostream>

//declare overloaded < operator for flightRec
//this function compares the destinations between two flightRec
bool flightRec::operator< (const flightRec& rhs) const{
	return (this->destination < rhs.destination);
}

//declare overloaded == operator for flightRec
//this function compares the origins and destinations between two flightRec
bool flightRec::operator== (const flightRec& rhs) const{
	return (this->destination == rhs.destination && this->origin == rhs.origin);
}

//declare overloaded << (insertion) operator for flightRec struct
ostream& operator<< (ostream& os, const flightRec& rhs){
	os << rhs.flightNum << " " << rhs.origin << " " << rhs.destination << endl;
	return os;
}

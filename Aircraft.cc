#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& reg){
    registration = reg;
    this->type = type;
    flighthours = 0;
}
Aircraft::~Aircraft(){

}
string Aircraft::getRegistration(){
    return registration;
}
void Aircraft::install(Part* p, Date& d){
    parts.add(p);
    p->install(d);
}
void Aircraft::takeFlight(int hours){
    flighthours = flighthours + hours;
    for (int i = 0; i < parts.getSize(); i++){
        parts[i]->addFlightHours(hours);
    }
}
void Aircraft::inspectionReport(Date& d, Array<Part*> &p){
    for (int i = 0; i < parts.getSize(); i++){
        if (parts[i]->inspection(d)){
            p.add(parts[i]);
        }
    }
}
ostream& operator<<(ostream& out, const Aircraft& air){
	out << "Aircraft:  " << air.type <<endl
  << "Registration:  " << air.registration <<endl;

	return out;
}

#include "Part.h"

Part::Part(string name){
    this->name = name;
    flightHours = 0;
}
Part::~Part(){}
string Part::getName(){
    return name;
}
void Part::addFlightHours(int fh){
    flightHours = flightHours + fh;
}
void Part::install(Date& d){
    installationDate = d;
}
ostream& operator<<(ostream& out, Part& p){
	out<< endl << "Part:  " << p.name << endl
  << "Flight hours:  " << p.flightHours << endl
  << "Installation date:  " << p.installationDate << endl;
  return out;
}


//*************************************************************
FH_Part::FH_Part(const string& name, int num): Part(name){
    fh_inspect = num;
}
FH_Part::~FH_Part(){
}
bool FH_Part::inspection(Date& d){
    if (flightHours >= fh_inspect){
        return true;
    }
    return false;
}

//*************************************************************
IT_Part::IT_Part(const string& name, int num): Part(name){
    it_inspect = num;
}
IT_Part::~IT_Part(){
}
bool IT_Part::inspection(Date& d){
    if ((d.toDays() - installationDate.toDays()) >= it_inspect){
        return true;
    }
    return false;
}

//*************************************************************
FHIT_Part::FHIT_Part(const string& name, int fh, int it): FH_Part(name, fh), IT_Part(name, it),Part(name){
}
bool FHIT_Part::inspection(Date& d){
    if(FH_Part::inspection(d) || IT_Part::inspection(d)){
        return true;
    }
    return false;
}

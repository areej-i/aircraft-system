#include "Airline.h"

Airline::Airline(const string& name){
    this->name = name;
}
Airline::~Airline(){
    for(int i = 0; i < parts.getSize(); i++){
        delete parts[i];
    }

    for(int i = 0; i < aircrafts.getSize(); i++){
        delete aircrafts[i];
    }

}
bool Airline::getAircrafts(const string& reg, Aircraft **ac){
    cout << "a";
    for (int i = 0; i < aircrafts.getSize(); i++)
    {
        cout << "b";
        if(aircrafts[i]->getRegistration() == reg){
            cout << "c";
            *ac = aircrafts[i];
            return true;
        }
    }

    return false;

}
bool Airline::getParts(const string& name, Part **p){
    for (int i = 0; i < parts.getSize(); i++){
        if (parts[i]->getName() == name){
           *p = parts[i];
            return true;
        }
    }
    return false;
}
void Airline::addAircraft(const string& type, const string& reg){
    Aircraft *ac = new Aircraft(type,reg);
    aircrafts.add(ac);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect){

    if(fh_inspect==0){
        IT_Part *it = new IT_Part(part, it_inspect);
        parts.add(it);
    }
    if(it_inspect==0){
        FH_Part *fh = new FH_Part(part, fh_inspect);
        parts.add(fh);
    }
    if(it_inspect!=0 && fh_inspect !=0){
        FHIT_Part *fhit = new FHIT_Part(part, fh_inspect, it_inspect);
        parts.add(fhit);
    }
}
void Airline::takeFlight(const string& reg, int hours){
    for(int i = 0; i < aircrafts.getSize(); i++){
        if(aircrafts[i]->getRegistration() == reg){
            aircrafts[i]->takeFlight(hours);
        }
    }
}
void Airline::printAircraft(){
    for (int i = 0; i < aircrafts.getSize(); i++){
        cout << *aircrafts[i];
    }
}
void Airline::printParts(){
    for (int i = 0; i < parts.getSize(); i++){
        cout << *parts[i];
    }
}
bool Airline::inspectionReport(const string& reg, Date& d){
    Array<Part*> p;
    Aircraft *ac;

    if(!getAircrafts(reg, &ac)){
      return false;
    }

    ac->inspectionReport(d,p);
    cout << endl <<"Aircraft Registration:  "<< ac->getRegistration();
    cout << endl << "Aircraft Parts:  ";
    for(int i = 0; i < parts.getSize(); i++){
        cout << *parts[i];
    }
    return true;
}
bool Airline::install(const string& reg, const string& name, Date& d){
      Aircraft *ac;
      Part *p;
      if(getAircrafts(reg,&ac) && getParts(name, &p)){
          ac->install(p,d);
          return true;
      }

    return false;
}

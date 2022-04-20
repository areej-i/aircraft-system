#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"
#include "Date.h"
#include "Array.h"
#include "Aircraft.h"
#include "Part.h"

using namespace std;

class Airline{
    public:
        Airline(const string& name);
        ~Airline();

        void addAircraft(const string& type, const string& reg);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(const string& reg, int hours);

        void printAircraft();
        void printParts();

        bool inspectionReport(const string& reg, Date& d);
        bool install(const string& reg, const string& name, Date& d);


    private:
        bool getParts(const string& s, Part **p);
        bool getAircrafts(const string& s, Aircraft **ac);
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;
};
#endif

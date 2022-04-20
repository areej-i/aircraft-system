#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"
#include "Array.h"
#include "Part.h"
#include "Date.h"

using namespace std;

class Aircraft{
    friend ostream& operator<<(ostream&, const Aircraft&);
    public:
        Aircraft(const string& type, const string& reg);
        ~Aircraft();

        string getRegistration();
        void install(Part*, Date&);
        void takeFlight(int hours);
        void inspectionReport(Date& d, Array<Part*>&);

    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;

};
#endif

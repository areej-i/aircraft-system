#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Part {

    friend ostream& operator<<(ostream&, Part&);
    public:
        Part(string name);
        virtual ~Part();

        string getName();
        void addFlightHours(int);
        void install(Date&);

        virtual bool inspection(Date&)=0;

    protected:
        string name;
        Date installationDate;
        int flightHours;
};
#endif

//******************************************************************
#ifndef FH_PART_H
#define FH_PART_H

class FH_Part: virtual public Part {
    public:
        FH_Part(const string& name, int num);
        ~FH_Part();

        virtual bool inspection(Date&);

    private:
        int fh_inspect;
};
#endif

//******************************************************************
#ifndef IT_PART_H
#define IT_PART_H

class IT_Part: virtual public Part {
    public:
        IT_Part(const string& name, int num);
        ~IT_Part();

        virtual bool inspection(Date&);

    private:
        int it_inspect;
};
#endif

//******************************************************************
#ifndef FHIT_PART_H
#define FHIT_PART_H

class FHIT_Part: public IT_Part, public FH_Part {
    public:
        FHIT_Part(const string& name, int fh, int it);

        virtual bool inspection(Date&);

};
#endif

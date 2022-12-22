#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "drone.h"
using namespace std;

class factory
{
    private:
        drone **list;
        string fID;
        string oID;
        int level;
        int droneLimit;
        int currNumDrones;

    public:
        factory(string, string, int);
        factory(string, string, drone**, int, int);
        ~factory();
        void levelUp();
        int addDrone(drone*);
        int removeDrone(string);
        string getFID();
        string getOID();
        int getCurrSize();
        int getLimit();
        void printDrones(string n);
};
#endif
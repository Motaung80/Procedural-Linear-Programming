#ifndef DRONE_H
#define DRONE_H
#include <string>
using namespace std;

class drone
{
    private:
        string name;
        string type;
        int hp;
        double energy;

    public:
        drone(string, string, int, double);
        ~drone();
        string getName();
        string getType();
        int getHP();
        double getEnergy();
        void print();
};
#endif
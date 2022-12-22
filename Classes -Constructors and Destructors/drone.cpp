#include "drone.h"
#include <iostream>
using namespace std;

drone::drone(string nam, string typ, int h, double ene)
{
    name = nam;
    type = typ;
    hp = h;
    energy = ene;
}
drone::~drone()
{
    cout << name << " deleted" << endl;
}
string drone::getName()
{
    return name;
}
string drone::getType()
{
    return type;
}
int drone::getHP()
{
    return hp;
}
double drone::getEnergy()
{
    return energy;
}
void drone::print()
{
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "HP: " << hp << endl;
    cout << "Energy: " << energy << endl;
}
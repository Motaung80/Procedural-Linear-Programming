#include "factory.h"
#include "drone.h"
#include <iostream>
#include <string>
using namespace std;

factory::factory(string facId, string ownId, int limit)
{
    factory::fID = facId;
    factory::oID = ownId;
    factory::droneLimit = limit;
    factory::currNumDrones = 0;
    factory::level = 1;
    list = new drone*[droneLimit];
}
factory::factory(string facId, string ownId, drone **drones, int limit, int curnum)
{
    factory::fID = facId;
    factory::oID = ownId;
    factory::droneLimit = limit;
    factory::currNumDrones = curnum;
    factory::level = 1;
    list = new drone*[droneLimit];
    for(int x = 0; x < currNumDrones; x++)
    {
        if(drones[x] != NULL)
        {
            list[x] = new drone(drones[x]->getName(),drones[x]->getType(),drones[x]->getHP(),drones[x]->getEnergy());
        }
    } 
}
factory::~factory()
{
    for(int x = 0; x < droneLimit; x++)
    {
        if(list[x] != NULL)
        {
            delete list[x];
        }
    }
    delete [] list;
}
void factory::levelUp()
{
    level++;
}
int factory::addDrone(drone *d)
{
    for(int x = 0; x < droneLimit; x++)
    {
        if(list[x] == NULL)
        {
            list[x] = new drone(d->getName(),d->getType(),d->getHP()*level,d->getEnergy()*level);
            currNumDrones++;
            return x;
        }
    }
    return -1;
}
int factory::removeDrone(string name)
{
    for(int x = 0; x < droneLimit; x++)
    {
        if(name == list[x]->getName())
        {
            delete list[x];
            list[x] = NULL;
            currNumDrones--;
            return x;
        }
    }
    return -1;
}
string factory::getFID()
{
    return fID;
}
string factory::getOID()
{
    return oID;
}

void factory::printDrones(string s)
{
    double TotalEnergy = 0;
    cout << "Factory ID: " << fID << endl;
    cout << "OID: " << oID << endl;
    cout << "Number of Drones: " << currNumDrones << endl;
    cout << "Drone Limit: " << droneLimit << endl;
    cout << "Rank: ";

    for (int x = 0; x < level; x++)
    {
        cout << "*";
    }
    cout << endl;

    if (currNumDrones != 0)
    {
        for (int x = 0; x < droneLimit; x++)
        {
            if (list[x] != NULL)
                TotalEnergy += list[x]->getEnergy();
        }
        cout << "Energy Level: " << TotalEnergy << endl;
    }

    int HpStorage[currNumDrones];
    double EnergyStorage[currNumDrones];


    int temporary = 0;
    for (int x = 0; x < droneLimit; x++)
    {
        if(list[x] != NULL)
        {
            HpStorage[temporary] = list[x]->getHP();
            temporary++;
        }
    }

    int temporary2 = 0;
    for (int x = 0; x < droneLimit; ++x)
    {
        if(list[x] != NULL)
        {
            EnergyStorage[temporary2] = list[x]->getEnergy();
            temporary2++;
        }
    }

   bool val;
    if(s == "hp")
    {
        int temporaryHp;
        do
        {
            val = false;
            for (int x = 0; x < currNumDrones-1;x++)
            if (HpStorage[x] > HpStorage[x+1])
            {
                temporaryHp = HpStorage[x];
                HpStorage[x] = HpStorage[x+1];
                HpStorage[x+1] = temporaryHp;
                val = true;
            }
        }while(val);

        for (int x = 0; x < currNumDrones; ++x)
        {
            for (int y = 0; y < droneLimit; ++y)
            {
                if(list[y] != NULL && HpStorage[x] == list[y]->getHP())
                {
                    cout << list[y]->getName() << endl;
                }
            }   
        }
    }
    else if (s == "m")
    {
        double temporatyEnergy;
        do
        {
            val = false;
            for (int x = 0; x < currNumDrones-1; x++)
            {
                if (EnergyStorage[x] < EnergyStorage[x+1])
                {
                    temporatyEnergy = EnergyStorage[x];
                    EnergyStorage[x] = EnergyStorage[x+1];
                    EnergyStorage[x+1] = temporatyEnergy;
                    val = true;
                }
            }

        }while(val);
    
        for (int x = 0; x < currNumDrones; ++x)
        {
            for (int y = 0; y < droneLimit; ++y)
            {
                if (list[y] != NULL && EnergyStorage[x] == list[y]->getEnergy())
                {
                    cout << list[y]->getName() << endl;
                }
            }
        }
    }
} 
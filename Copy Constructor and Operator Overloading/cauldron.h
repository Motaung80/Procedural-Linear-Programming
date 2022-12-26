#ifndef CAULDRON_H
#define CAULDRON_H
#include "ingredient.h"
#include <string>
#include <fstream>
using namespace std;

class cauldron
{
    private:
        ingredient** ingredients;
        int numIngredients;
        int maxIngredients;

    public:
        cauldron(string, int);
        cauldron(const cauldron*);
        void operator=(const cauldron&);
        ~cauldron();
        void print();
        int getMax() const;
        int getCurr() const;
        ingredient * getIngredient(int) const;
        int addIngredient(string, int);
        void removeIngredient(int);
        void distillPotion(cauldron &, string*, int);
        void listIngredients();
};
#endif
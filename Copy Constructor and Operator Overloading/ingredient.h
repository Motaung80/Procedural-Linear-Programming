#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
using namespace std;

class ingredient
{
    private:
        string name;
        int dangeRating;

    public:
        ingredient(string, int);
        ingredient(const ingredient*);
        ingredient(const ingredient &);
        ~ingredient();
        int getDanger();
        string getName();
};
#endif
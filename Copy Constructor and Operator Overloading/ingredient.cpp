#include "ingredient.h"
#include <iostream>
using namespace std;

ingredient::ingredient(string nam, int danRate)
{
    ingredient::name = nam;
    ingredient::dangeRating = danRate;
}
ingredient::ingredient(const ingredient* newIngredient)
{
    ingredient::name = (*newIngredient).name;
    ingredient::dangeRating = (*newIngredient).dangeRating;

}
ingredient::ingredient(const ingredient & newIngredient)
{
    ingredient::name = newIngredient.name;
    ingredient::dangeRating = newIngredient.dangeRating;
}
ingredient::~ingredient()
{

}
int ingredient::getDanger()
{
    return dangeRating;
}
string ingredient::getName()
{
    return name;
}
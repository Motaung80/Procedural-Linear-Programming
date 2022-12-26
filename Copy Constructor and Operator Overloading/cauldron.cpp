#include "ingredient.h"
#include "cauldron.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

cauldron::cauldron(string ingredientList, int maxIng)
{
    maxIngredients = maxIng;
    string In_name;
    int In_num;
    numIngredients = 0;
    string Str_In_num;
    fstream inFile;

    this->ingredients = new ingredient*[maxIngredients];
    
    inFile.open(ingredientList, ios::in);
    if(maxIngredients == 0)
    {
        for(int x = 0; x < maxIngredients; x++)
        {
            ingredients[x] = NULL;
        }
    }else
    {
        if(inFile)
        {
        for(int x = 0; x < maxIngredients; x++)
            {
                getline(inFile, In_name, ',');
                getline(inFile, Str_In_num);
                istringstream(Str_In_num) >> In_num;
                ingredients[x] = new ingredient(In_name, In_num);
                numIngredients++;
            }
        }
    }
}
cauldron::cauldron(const cauldron* oldCauldron)
{
    cauldron::maxIngredients = (*oldCauldron).maxIngredients;
    cauldron::numIngredients = (*oldCauldron).numIngredients;

    this->ingredients = new ingredient*[maxIngredients];

    for(int x = 0; x < maxIngredients; x++)
    {
        ingredients[x] = NULL;
    }

    for(int x = 0; x < numIngredients; x++)
    {
        this->ingredients[x] = new ingredient(oldCauldron->ingredients[x]->getName(),oldCauldron->ingredients[x]->getDanger());
    }
}
void cauldron::operator=(const cauldron& oldCauldron)
{
    for(int x = 0; x < numIngredients; x++)
    {
        delete ingredients[x];
    }
    delete [] ingredients;

    cauldron::maxIngredients = oldCauldron.maxIngredients;
    cauldron::numIngredients = oldCauldron.numIngredients;

    this->ingredients = new ingredient*[maxIngredients];

    for(int x = 0; x < maxIngredients; x++)
    {
        ingredients[x] = NULL;
    }

    for(int x = 0; x < numIngredients; x++)
    {
        this->ingredients[x] = new ingredient(oldCauldron.ingredients[x]->getName(),oldCauldron.ingredients[x]->getDanger());
    }
}
cauldron::~cauldron()
{

}
void cauldron::print()
{

    double average;
    double total = 0;
    int maxRating = 0;
    int minRating = 10;
    int check;

    cout << "Number of Ingredients: " << numIngredients << endl;

    for(int x = 0; x < numIngredients; x++)
    {
        total += ingredients[x]->getDanger(); 
    }
    average = total / maxIngredients;

    for(int x = 0; x < numIngredients; x++)
    {
        check = ingredients[x]->getDanger();
        if(maxRating < check)
        {
            maxRating = check;
        }

        if(minRating > check)
        {
            minRating = check;
        }
    }

    cout << "Average Dnger Rating: " << average << endl;
    cout << "Maximum Danger Rating: " << maxRating << endl;
    cout << "Minimum Danger Rating: " << maxRating << endl;
}
int cauldron::getMax() const
{
    return maxIngredients;
}
int cauldron::getCurr() const
{
    return numIngredients;
}
ingredient * cauldron::getIngredient(int a) const
{
    return ingredients[a];
}
int cauldron::addIngredient(string in, int dR) 
{
    int a = -1;
    int b;
    int c = 0;

    for(int x = 0; x < maxIngredients; x++)
    {
        if(ingredients[x] == NULL)
        {
            b = x;
        }
    }
    if(b != a)
    {
        ingredients[b] = new ingredient(in, dR);
        ++numIngredients;
        return a;
    }else
    {
        ingredient **Other = new ingredient*[numIngredients+1];

        while(c < numIngredients)
        {
            Other[c] = ingredients[c];
            c++;
        }
        delete [] ingredients;
        delete [] Other;

        ++numIngredients;
        ++maxIngredients;

        ingredients[numIngredients-1] = new ingredient(in, dR);

        return numIngredients-1;
    }
}
void cauldron::removeIngredient(int in)
{
    delete ingredients[in];

    for(int x = 0; x < numIngredients; x++)
    {
        ingredients[x] = ingredients[x+1];
    }
    ingredients[numIngredients-1] = NULL;
    --numIngredients;
}
void cauldron::distillPotion(cauldron &currCauldron, string* list, int numRemove)
{
    for(int x = 0; x < numRemove; x++)
    {
        if(currCauldron.ingredients[x]->getName() == list[x])
        {
            delete currCauldron.ingredients[x];
            currCauldron.ingredients[x] = NULL;
        }
    }

    int a = 0;
    int count = 0;

    ingredient **Other = new ingredient*[currCauldron.maxIngredients];

    while(count < currCauldron.numIngredients)
    {
        if(currCauldron.ingredients[count] != NULL)
        {
            Other[a++] = currCauldron.ingredients[count];
        }
        count++;
    }

    delete [] currCauldron.ingredients;

    currCauldron.numIngredients = a;
    currCauldron.ingredients = Other;

    delete[] Other;
}
void cauldron::listIngredients()
{
    for(int x = 0; x < maxIngredients; x++)
    {
        cout << this->ingredients[x] << endl;
    }
}
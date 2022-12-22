#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    fstream File;
    string line;
    string item;
    int count;
    int NumRows = 0;
    int i = 0;
    int y = 0;
    int cols = 1;
    int itemId;

    File.open("data.txt", ios::in);
    while(getline(File,line))
    {
        count = 0;
        stringstream lin(line);
        while(getline(lin, item, ','))
        {
            count++;
        }
        NumRows++;
    }
    File.close();

    int colSizes[NumRows];

    File.open("data.txt", ios::in);
    while(getline(File,line) && i < NumRows)
    {
        count = 0;
        stringstream lin(line);
        while(getline(lin, item, ','))
        {
            count++;
        }
        colSizes[i] = count;
        i++;
    }
    File.close();

    
    string **Items = new string*[NumRows];
    for(int x = 0; x < NumRows; x++)
    {
        Items[x] = new string[colSizes[x]];
    }
    int rowindex = 0;
    int colindex;

    File.open("data.txt", ios::in);
    while(getline(File,line))
    {
        colindex = 0;
        stringstream lin(line);
        while(getline(lin,Items[rowindex][colindex],','))
        {
            colindex++;
        }
        rowindex++;
    }
    File.close();
    
    /* Sort */

    int comp1, comp2;
    int tempCol;
    string *tempItem;
    bool move;

    do
    {
        move = false;
		for(int i = 0 ;i < (NumRows-1); i++)
        {
            stringstream lin1;
            stringstream lin2;
			lin1 << Items[i][0];
			lin1 >> comp1;
			lin2 << Items[(i+1)][0];
			lin2 >> comp2;
			
			if(comp1 > comp2)
            {
				tempItem = Items[i];
				Items[i] = Items[(i+1)];
				Items[(i+1)] = tempItem;

				tempCol = colSizes[i];
				colSizes[i] = colSizes[(i+1)];
				colSizes[(i+1)] = tempCol;
				move = true;
			}
        }
        /* code */
    } while (move);

    for(int x = 0; x < NumRows; x++)
    {
        for(int y = 0; y < colSizes[x]; y++)
        {
            cout << Items[x][y];
            if(y < (colSizes[x]-1)){
                cout<< ",";
            }
        }
        cout << endl;
    }
    

    return 0;
}
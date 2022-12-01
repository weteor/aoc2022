#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define ELFS_PER_SUM (3)

void addDescMaximums(unsigned int* const buffer, const unsigned int bufferLength, const unsigned int val )
{
    for(unsigned short i = 0; i < bufferLength; ++i)
    {
        if(buffer[i] < val)
        {
            for(unsigned short j = bufferLength-1; j > i; j--)
            {
                buffer[j] = buffer[j-1];
            }
            buffer[i] = val;
            break;
        }
    }
}

int main (void)
{
    unsigned int calories = 0;
    unsigned int maxCalories[ELFS_PER_SUM] = {0};

    fstream inputFile;
    
    inputFile.open("input.txt", ios::in );
    if(!inputFile.is_open()) {return -1;}

    string line;
    while(getline(inputFile, line))
    {   
        if(line.empty())
        {
            addDescMaximums(maxCalories, ELFS_PER_SUM, calories);
            calories =  0;
        }
        else
        {
            calories += stoi(line);
        }
    }

    inputFile.close();

    cout << "max: " << maxCalories[0] << endl;
    cout << "max3: " << maxCalories[0] + maxCalories[1] + maxCalories[2] << endl;
}

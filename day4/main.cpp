#include <fstream>
#include <iostream>

using namespace std;


int main(void)
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in );
    if(!inputFile.is_open()) {return -1;}

    string line, first, second;
    unsigned int f1,f2, s1, s2;
    unsigned int containedPairs, overlapPairs = 0;

    while(getline(inputFile, line))
    {
        f1 = stoi(line.substr(                0, line.find("-")  ) );
        f2 = stoi(line.substr(line.find("-") +1, line.find(",")  ) );
        s1 = stoi(line.substr(line.find(",") +1 ,line.rfind("-") ) );
        s2 = stoi(line.substr(line.rfind("-")+1                  ) );
         
        if( ((f1<=s1) && (f2>=s2)) || ((s1<=f1) && (s2>=f2)) )
        {
            containedPairs++;
        }

        if( (f2 >= s1) && (s2 >= f1) )
        {
            overlapPairs++;
        }
    }

    cout << "contained pairs: " << containedPairs << endl;
    cout << "overlap pairs: " << overlapPairs << endl;
}

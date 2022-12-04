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
        size_t splitPos = line.find(",");
        first = line.substr(0,splitPos);
        second = line.substr(splitPos+1);

        f1 = stoi(first.substr(0,first.find("-",0)));
        f2 = stoi(first.substr(first.find("-")+1));
        s1 = stoi(second.substr(0,second.find("-",0)));
        s2 = stoi(second.substr(second.find("-")+1));
         
        if( ((f1<=s1) && (f2>=s2)) || 
            ((s1<=f1) && (s2>=f2)) )
        {
            containedPairs++;
        }

        if( (f2 >= s1) && 
            (s2 >= f1) )
        {
            overlapPairs++;
        }
    }

    cout << "contained pairs: " << containedPairs << endl;
    cout << "overlap pairs: " << overlapPairs << endl;
}

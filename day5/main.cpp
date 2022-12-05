#include <fstream>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;
#define LISTS_NO (9)

void printLists(list<string>* lists)
{
    for (unsigned int i = 0; i < LISTS_NO; i++)
    {
        cout << "List " << i << ": ";
        for (auto x:lists[i])
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}

int main(void)
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in );
    if(!inputFile.is_open()) {return -1;}

    list<string> lists9000[9] = {
    { "W", "T", "H", "P", "J", "C", "F" },
    { "H", "B", "J", "Z", "F", "V", "R", "G" },
    { "R", "T", "P", "H" } ,
    { "T", "H", "P", "N", "S", "Z"},
    { "D", "C", "J", "H", "Z", "F", "V", "N" },
    { "Z", "D", "W", "F", "G", "M", "P" },
    { "P", "D", "J", "S", "W", "Z", "V", "M" },
    { "S", "D", "N" },
    { "M", "F", "S", "Z", "D" } };
    
    list<string> lists9001[9];
    for(unsigned int i = 0; i < LISTS_NO; i++)
    {
        lists9001[i] = lists9000[i];
    }

    printLists(lists9001);
    string line;
    unsigned int move, from, to;

    while(getline(inputFile, line))
    {
        /* cout << line.substr(line.find("move ")+5,line.find(" from ")-5) << " / "; */
        move = stoi(line.substr(line.find("move ")+5, line.find(" from ")-line.find("move ") - 5));
        from = stoi(line.substr(line.find(" from ")+6, line.find(" to ")-line.find(" from ") - 6)) - 1;
        to   = stoi(line.substr(line.find(" to ")+4)) - 1;
        
        for( unsigned int i = 0; i < move; i++ )
        {
            lists9000[to].splice(lists9000[to].begin(), lists9000[from], lists9000[from].begin());
        }
        
        list<string>::iterator endIt = lists9001[from].begin();
        advance(endIt, move);
        lists9001[to].splice(lists9001[to].begin(), lists9001[from], lists9001[from].begin(), endIt);

//        printLists(lists);

    }

    cout << "CraneMover9000" << endl;
    printLists(lists9000);
    cout << "CraneMover9001" << endl;
    printLists(lists9001);
}

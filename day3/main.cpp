#include <string>
#include <fstream>
#include <iostream>

using namespace std;
#define ASCII_OFFSET_UPPER (64)
#define ASCII_OFFSET_LOWER (96)
#define GROUP_SIZE (3)

unsigned int convertAsciiToScore(unsigned int asciiVal)
{
    unsigned int score = 0;
    if(asciiVal > ASCII_OFFSET_LOWER)
    {   
        score = asciiVal - ASCII_OFFSET_LOWER;
    }
    else
    {
        score = asciiVal - ASCII_OFFSET_UPPER + 26;
    }
    return score;
}

unsigned int getDuplicateAsciiVal(string& line)
{
    unsigned int i;
    for(i = 0; i < line.size()/2; ++i)
    {
        if(string::npos != line.find(line[i], line.size()/2))
        { break;}
    }
    return (unsigned int)line[i];
}

unsigned int getGroupAsciiVal(string* lines)
{
    unsigned int i,j = 0;
    for(i = 0; i < lines[0].size(); i++)
    {
        if(string::npos != lines[1].find(lines[0][i]))
        {
            if( string::npos != lines[2].find(lines[0][i]))
            {
                break;
            }
        }
    }

    return (unsigned int)lines[0][i];
}

int main(void)
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in );
    if(!inputFile.is_open()) {return -1;}
    
    string lines[GROUP_SIZE];
    unsigned int curLine = 0;
    unsigned int scoreDup, scoreGroup = 0;

    while(getline(inputFile, lines[curLine]))
    {
        scoreDup += convertAsciiToScore(getDuplicateAsciiVal(lines[curLine]));
        if((GROUP_SIZE-1) == curLine)
        {
            scoreGroup += convertAsciiToScore(getGroupAsciiVal(lines));
        }
        curLine = ++curLine % GROUP_SIZE;
    }
    inputFile.close();

    cout << "duplicate score: " << scoreDup << endl;
    cout << "group score: " << scoreGroup << endl;
}

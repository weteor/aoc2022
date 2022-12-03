#include <iostream>
#include <fstream>

using namespace std;

#define L_POINTS (0)
#define D_POINTS (3)
#define W_POINTS (6)

#define ROCK_POINTS (1)
#define PAPER_POINTS (2)
#define SCISSORS_POINTS (3)

unsigned int getVal(const char rps)
{
    unsigned int val = 0;
    switch (rps)
    {
        case 'X':
        case 'A':
            val = ROCK_POINTS;
            break;
        case 'Y':
        case 'B':
            val = PAPER_POINTS;
            break;
        case 'Z':
        case 'C':
            val = SCISSORS_POINTS;
            break;
        default:
            break;
    }
    return val;
}

int roundScore(int oppVal, int ownVal)
{
    int score = 0;

    if (oppVal == ownVal)
    { score = D_POINTS; }
    else if ((oppVal%3) == (ownVal-1))
    { score = W_POINTS; }

    return score+ownVal;
}

int stratScore(int oppVal, const char own)
{
    int score = 0;
    switch (own)
    {
        case 'X':
            score = (oppVal == ROCK_POINTS ) ? SCISSORS_POINTS : (oppVal-1) ;
            break;
        case 'Y':
            score = oppVal + D_POINTS;
            break;
        case 'Z':
            score = (oppVal == SCISSORS_POINTS) ? ROCK_POINTS : (oppVal+1);
            score += W_POINTS;
            break;
        default:
            score = 0;
            break;
    }
    return score;
}

int main(void)
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in );
    if(!inputFile.is_open()) {return -1;}
    
    char opp, own;
    int oppVal, ownVal;

    unsigned int score_1 = 0;
    unsigned int score_2 = 0;
    
    while(!inputFile.eof())
    {
        inputFile >> opp >> own;
        oppVal = getVal(opp);
        ownVal = getVal(own);

        score_1 += roundScore(oppVal, ownVal);
        score_2 += stratScore(oppVal, own);
    }
    
    score_1 -= roundScore(oppVal, ownVal);
    score_2 -= stratScore(oppVal, own);

    inputFile.close();

    cout << "score_1: " << score_1 << endl;
    cout << "score_2: " << score_2 << endl;
}

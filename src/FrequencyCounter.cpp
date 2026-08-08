#include "FrequencyCounter.h"
#include <iostream>
using namespace std;

FrequencyCounter::FrequencyCounter()
{

    for(int i=0; i<256; i++)
    {
        frequency[i]=0;
    }

}



void FrequencyCounter::countFrequency(vector<unsigned char> data)
{

    for(int i=0; i<data.size(); i++)
    {
        frequency[data[i]]++;
    }

}



void FrequencyCounter::displayFrequency()
{

    for(int i=0; i<256; i++)
    {

        if(frequency[i] > 0)
        {
            cout << (char)i 
                 << " : "
                 << frequency[i]
                 << endl;
        }

    }

}
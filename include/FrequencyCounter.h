#ifndef FREQUENCY_COUNTER_H
#define FREQUENCY_COUNTER_H

#include <vector>

using namespace std;


class FrequencyCounter
{

public:

    int frequency[256];

    FrequencyCounter();


    void countFrequency(vector<unsigned char> data);


    void displayFrequency();

};


#endif
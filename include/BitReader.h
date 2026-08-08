#ifndef BIT_READER_H
#define BIT_READER_H

#include <fstream>

using namespace std;


class BitReader
{

private:

    ifstream file;

    unsigned char buffer;

    int bitCount;


public:

    BitReader(string filename);

    int readBit();

    void close();

};

#endif
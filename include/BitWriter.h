#ifndef BIT_WRITER_H
#define BIT_WRITER_H

#include <fstream>

using namespace std;

class BitWriter
{

private:

    ofstream file;

    unsigned char buffer;

    int bitCount;


public:

    BitWriter(string filename);

    void writeBit(int bit);

    void close();

};

#endif
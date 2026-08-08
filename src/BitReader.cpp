#include "BitReader.h"


BitReader::BitReader(string filename)
{

    file.open(filename, ios::binary);

    buffer = 0;

    bitCount = 0;

}



int BitReader::readBit()
{

    if(bitCount == 0)
    {

        file.read((char*)&buffer,1);


        if(file.eof())
        {
            return -1;
        }


        bitCount = 8;

    }



    int bit = (buffer >> (bitCount-1)) & 1;


    bitCount--;


    return bit;

}




void BitReader::close()
{

    file.close();

}
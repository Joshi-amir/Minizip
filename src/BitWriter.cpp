#include "BitWriter.h"



BitWriter::BitWriter(string filename)
{

    file.open(filename, ios::binary | ios::app);


    buffer = 0;

    bitCount = 0;

}




void BitWriter::writeBit(int bit)
{

    buffer = buffer << 1;


    if(bit == 1)
    {
        buffer = buffer | 1;
    }


    bitCount++;



    if(bitCount == 8)
    {

        file.put(buffer);


        buffer = 0;

        bitCount = 0;

    }

}





void BitWriter::close()
{

    if(bitCount > 0)
    {

        buffer = buffer << (8 - bitCount);


        file.put(buffer);

    }


    file.close();

}
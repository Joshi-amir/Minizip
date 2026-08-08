#include "FileHeader.h"



void FileHeader::writeHeader(ofstream &file,
                             int frequency[],
                             int size)
{

    for(int i=0;i<256;i++)
    {

        file.write((char*)&frequency[i],
                   sizeof(int));

    }


    file.write((char*)&size,
               sizeof(int));

}




void FileHeader::readHeader(ifstream &file,
                            int frequency[],
                            int &size)
{

    for(int i=0;i<256;i++)
    {

        file.read((char*)&frequency[i],
                  sizeof(int));

    }


    file.read((char*)&size,
              sizeof(int));

}
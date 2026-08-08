#ifndef FILE_HEADER_H
#define FILE_HEADER_H


#include <fstream>

using namespace std;


class FileHeader
{

public:

    void writeHeader(ofstream &file,
                     int frequency[],
                     int size);



    void readHeader(ifstream &file,
                    int frequency[],
                    int &size);

};


#endif
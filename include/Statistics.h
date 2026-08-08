#ifndef STATISTICS_H
#define STATISTICS_H


#include <string>

using namespace std;


class Statistics
{

private:

    long getFileSize(string filename);


    bool compareFiles(string file1,
                      string file2);


public:

    void showStatistics(string originalFile,
                        string compressedFile,
                        string decompressedFile);

};


#endif
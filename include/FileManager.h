#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include <string>

using namespace std;


class FileManager
{
public:

    vector<unsigned char> readFile(string fileName);

    void writeFile(string fileName, vector<unsigned char> data);

};


#endif
#include "FileManager.h"
#include <fstream>
#include <iostream>


vector<unsigned char> FileManager::readFile(string fileName)
{
    vector<unsigned char> data;


    ifstream file(fileName, ios::binary);


    if(!file)
    {
        cout << "File cannot be opened!" << endl;
        return data;
    }


    unsigned char byte;


    while(file.read((char*)&byte, sizeof(byte)))
    {
        data.push_back(byte);
    }


    file.close();


    return data;
}



void FileManager::writeFile(string fileName, vector<unsigned char> data)
{

    ofstream file(fileName, ios::binary);


    for(int i=0; i<data.size(); i++)
    {
        file.write((char*)&data[i], sizeof(data[i]));
    }


    file.close();

}
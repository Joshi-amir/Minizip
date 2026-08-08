#ifndef COMPRESSOR_H
#define COMPRESSOR_H


#include "Node.h"
#include "FileHeader.h"

#include <string>
#include <vector>


using namespace std;



class Compressor
{

private:

    void generateCodes(Node* node, string code);


    string codes[256];


public:

    Compressor();


    void compress(vector<unsigned char> data,
                  string outputFile,
                  Node* root,
                  int frequency[]);


};


#endif
#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H


#include "Node.h"

#include <string>


using namespace std;


class Decompressor
{

private:

    Node* root;


    void buildTree(int frequency[]);


public:

    Decompressor();


    void decompress(string inputFile,
                    string outputFile);

};


#endif
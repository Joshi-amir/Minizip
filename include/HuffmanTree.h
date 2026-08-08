#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <string>

#include "Node.h"
#include "MinHeap.h"


using namespace std;


class HuffmanTree
{

private:

    Node* root;


    void generateCodes(Node* node, string code);


public:

    HuffmanTree();

    void buildTree(int frequency[]);

    void displayCodes();

    Node* getRoot();
};


#endif
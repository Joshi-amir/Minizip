#include "HuffmanTree.h"

#include <iostream>

using namespace std;


HuffmanTree::HuffmanTree()
{
    root = NULL;
}



void HuffmanTree::buildTree(int frequency[])
{
    MinHeap heap;


    for(int i = 0; i < 256; i++)
    {
        if(frequency[i] > 0)
        {
            Node* node = new Node((unsigned char)i, frequency[i]);

            heap.insert(node);
        }
    }



    while(heap.getSize() > 1)
    {
        Node* left = heap.removeMin();

        Node* right = heap.removeMin();


        Node* parent = new Node('\0',
                               left->frequency + right->frequency);


        parent->left = left;

        parent->right = right;


        heap.insert(parent);
    }


    root = heap.removeMin();
}




void HuffmanTree::generateCodes(Node* node, string code)
{
    if(node == NULL)
    {
        return;
    }


    if(node->left == NULL && node->right == NULL)
    {
        cout << (char)node->data
             << " : "
             << code
             << endl;

        return;
    }


    generateCodes(node->left, code + "0");

    generateCodes(node->right, code + "1");
}




void HuffmanTree::displayCodes()
{
    cout << "\nHuffman Codes:\n";

    generateCodes(root, "");
}

Node* HuffmanTree::getRoot()
{
    return root;
}
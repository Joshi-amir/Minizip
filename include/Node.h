#ifndef NODE_H
#define NODE_H
#include <cstddef>

class Node
{
public:

    unsigned char data;
    int frequency;

    Node* left;
    Node* right;


    Node(unsigned char value, int freq)
    {
        data = value;
        frequency = freq;

        left = NULL;
        right = NULL;
    }
};

#endif
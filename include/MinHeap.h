#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "Node.h"


class MinHeap
{

private:

    Node* heap[256];

    int size;


    void heapifyUp(int index);

    void heapifyDown(int index);

    void swapNodes(int a, int b);


public:

    MinHeap();


    void insert(Node* node);

    Node* removeMin();


    bool isEmpty();

    int getSize();

};


#endif
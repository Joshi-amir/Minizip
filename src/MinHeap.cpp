#include "MinHeap.h"


MinHeap::MinHeap()
{
    size = 0;

    for(int i = 0; i < 256; i++)
    {
        heap[i] = NULL;
    }
}



void MinHeap::swapNodes(int a, int b)
{
    Node* temp = heap[a];

    heap[a] = heap[b];

    heap[b] = temp;
}



void MinHeap::insert(Node* node)
{
    heap[size] = node;

    int index = size;

    size++;

    heapifyUp(index);
}



void MinHeap::heapifyUp(int index)
{

    while(index > 0)
    {

        int parent = (index - 1) / 2;


        if(heap[index]->frequency < heap[parent]->frequency)
        {
            swapNodes(index, parent);

            index = parent;
        }

        else
        {
            break;
        }

    }

}



Node* MinHeap::removeMin()
{

    if(size == 0)
    {
        return NULL;
    }


    Node* minNode = heap[0];


    heap[0] = heap[size - 1];


    size--;


    heapifyDown(0);


    return minNode;

}



void MinHeap::heapifyDown(int index)
{

    while(true)
    {

        int smallest = index;


        int left = 2 * index + 1;

        int right = 2 * index + 2;



        if(left < size &&
           heap[left]->frequency < heap[smallest]->frequency)
        {
            smallest = left;
        }



        if(right < size &&
           heap[right]->frequency < heap[smallest]->frequency)
        {
            smallest = right;
        }



        if(smallest != index)
        {
            swapNodes(index, smallest);

            index = smallest;
        }

        else
        {
            break;
        }

    }

}



bool MinHeap::isEmpty()
{
    return size == 0;
}



int MinHeap::getSize()
{
    return size;
}
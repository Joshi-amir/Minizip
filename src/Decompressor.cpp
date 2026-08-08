#include "Decompressor.h"

#include "FileHeader.h"
#include "BitReader.h"
#include "MinHeap.h"


#include <fstream>
#include <iostream>


using namespace std;



Decompressor::Decompressor()
{
    root = NULL;
}




void Decompressor::buildTree(int frequency[])
{

    MinHeap heap;


    for(int i=0;i<256;i++)
    {

        if(frequency[i]>0)
        {

            Node* node =
            new Node((unsigned char)i,
                     frequency[i]);


            heap.insert(node);

        }

    }



    while(heap.getSize()>1)
    {

        Node* left = heap.removeMin();

        Node* right = heap.removeMin();


        Node* parent =
        new Node('\0',
        left->frequency + right->frequency);


        parent->left = left;

        parent->right = right;


        heap.insert(parent);

    }


    root = heap.removeMin();

}





void Decompressor::decompress(string inputFile,
                              string outputFile)
{


    ifstream file(inputFile,
                  ios::binary);



    int frequency[256];

    int size;



    FileHeader header;


    header.readHeader(file,
                      frequency,
                      size);



    file.close();



    buildTree(frequency);



    BitReader reader(inputFile);



    // Skip header bits

    int headerBits =
    (256*sizeof(int)+sizeof(int))*8;


    for(int i=0;i<headerBits;i++)
    {
        reader.readBit();
    }




    ofstream output(outputFile);



    Node* current = root;


    int count = 0;



    while(count<size)
    {

        int bit = reader.readBit();



        if(bit==0)
        {
            current=current->left;
        }

        else
        {
            current=current->right;
        }



        if(current->left==NULL &&
           current->right==NULL)
        {

            output<<(char)current->data;


            count++;


            current=root;

        }

    }



    output.close();


    reader.close();



    cout<<"Decompression completed!"<<endl;

    cout<<"Output file: "
        <<outputFile<<endl;

}
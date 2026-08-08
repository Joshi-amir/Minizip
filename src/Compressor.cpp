#include "Compressor.h"
#include "BitWriter.h"

#include <iostream>
#include <fstream>


using namespace std;



Compressor::Compressor()
{

    for(int i = 0; i < 256; i++)
    {
        codes[i] = "";
    }

}




void Compressor::generateCodes(Node* node, string code)
{

    if(node == NULL)
    {
        return;
    }


    if(node->left == NULL && node->right == NULL)
    {

        codes[node->data] = code;

        return;

    }



    generateCodes(node->left, code + "0");


    generateCodes(node->right, code + "1");

}





void Compressor::compress(vector<unsigned char> data,
                          string outputFile,
                          Node* root,
                          int frequency[])
{

    generateCodes(root, "");



    // Write header first

    ofstream file(outputFile, ios::binary);


    FileHeader header;


   header.writeHeader(file,
                   frequency,
                   data.size());


    file.close();



    // Write compressed bits

    BitWriter writer(outputFile);



    for(int i = 0; i < data.size(); i++)
    {

        string code = codes[data[i]];


        for(int j = 0; j < code.length(); j++)
        {

            if(code[j] == '1')
            {
                writer.writeBit(1);
            }

            else
            {
                writer.writeBit(0);
            }

        }

    }



    writer.close();



    cout << "Compression completed!" << endl;


    cout << "Compressed file: "
         << outputFile
         << endl;

}
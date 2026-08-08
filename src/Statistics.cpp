#include "Statistics.h"

#include <iostream>
#include <fstream>


using namespace std;



long Statistics::getFileSize(string filename)
{

    ifstream file(filename,
                  ios::binary | ios::ate);


    if(!file)
    {
        return 0;
    }


    return file.tellg();

}




bool Statistics::compareFiles(string file1,
                              string file2)
{

    ifstream first(file1, ios::binary);

    ifstream second(file2, ios::binary);



    if(!first || !second)
    {
        return false;
    }



    string data1(
        (istreambuf_iterator<char>(first)),
        istreambuf_iterator<char>()
    );



    string data2(
        (istreambuf_iterator<char>(second)),
        istreambuf_iterator<char>()
    );



    // Handle Windows/Linux newline difference

    string clean1 = "";

    string clean2 = "";



    for(int i = 0; i < data1.length(); i++)
    {

        if(data1[i] != '\r')
        {
            clean1 += data1[i];
        }

    }



    for(int i = 0; i < data2.length(); i++)
    {

        if(data2[i] != '\r')
        {
            clean2 += data2[i];
        }

    }



    return clean1 == clean2;

}





void Statistics::showStatistics(string originalFile,
                                string compressedFile,
                                string decompressedFile)
{

    long originalSize =
    getFileSize(originalFile);



    long compressedSize =
    getFileSize(compressedFile);



    long decompressedSize =
    getFileSize(decompressedFile);



    cout << "\n========== Statistics ==========\n\n";



    cout << "Original File: "
         << originalFile
         << endl;



    cout << "Original Size: "
         << originalSize
         << " bytes\n\n";



    cout << "Compressed File: "
         << compressedFile
         << endl;



    cout << "Compressed Size: "
         << compressedSize
         << " bytes\n\n";



    if(originalSize > 0)
    {

        double saved =
        ((double)(originalSize - compressedSize)
        / originalSize) * 100;



        cout << "Space Saved: "
             << saved
             << "%\n\n";

    }




    cout << "Decompressed File: "
         << decompressedFile
         << endl;



    cout << "Decompressed Size: "
         << decompressedSize
         << " bytes\n\n";




    if(compareFiles(originalFile,
                    decompressedFile))
    {

        cout << "Verification: SUCCESS\n";

    }

    else
    {

        cout << "Verification: FAILED\n";

    }


}
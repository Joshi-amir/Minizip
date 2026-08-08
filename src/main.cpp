#include <iostream>


#include "FileManager.h"
#include "FrequencyCounter.h"
#include "HuffmanTree.h"
#include "Compressor.h"
#include "Decompressor.h"
#include "Statistics.h"


using namespace std;



int main()
{

    int choice;



    while(true)
    {

        cout << "\n========== MiniZip ==========\n";

        cout << "1. Compress File\n";

        cout << "2. Decompress File\n";

        cout << "3. Show Statistics\n";

        cout << "4. Exit\n";


        cout << "Enter choice: ";

        cin >> choice;




        if(choice == 1)
        {

            FileManager manager;


            vector<unsigned char> data;


            data =
            manager.readFile("input/test.txt");



            FrequencyCounter counter;


            counter.countFrequency(data);



            HuffmanTree tree;


            tree.buildTree(counter.frequency);



            Compressor compressor;


            compressor.compress(
                data,
                "output/compressed.mz",
                tree.getRoot(),
                counter.frequency
            );


        }



        else if(choice == 2)
        {

            Decompressor decompressor;


            decompressor.decompress(
                "output/compressed.mz",
                "output/decompressed.txt"
            );

        }



        else if(choice == 3)
        {

            Statistics stats;


            stats.showStatistics(
                "input/test.txt",
                "output/compressed.mz",
                "output/decompressed.txt"
            );

        }



        else if(choice == 4)
        {

            cout << "Exiting MiniZip...\n";

            break;

        }



        else
        {

            cout << "Invalid choice!\n";

        }

    }



    return 0;

}
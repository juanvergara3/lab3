#include <iostream>
#include "encription.h"
using namespace std;

int main()
{

    string data;

    data = "I met a traveller from an antique land,\n"
            "Who said-\"Two vast and trunkless legs of stone\n"
            "Stand in the desert. . . . Near them, on the sand,\n"
            "Half sunk a shattered visage lies, whose frown,\n"
            "And wrinkled lip, and sneer of cold command,\n"
            "Tell that its sculptor well those passions read\n"
            "Which yet survive, stamped on these lifeless things,\n"
            "The hand that mocked them, and the heart that fed;\n"
            "And on the pedestal, these words appear:\n"
            "My name is Ozymandias, King of Kings;\n"
            "Look on my Works, ye Mighty, and despair!\n"
            "Nothing beside remains. Round the decay\n"
            "Of that colossal Wreck, boundless and bare\n"
            "The lone and level sands stretch far away\".";

    //write_file("poem.txt", data);

    encrypt("poem", 2, 5);
    decrypt("poem", 2, 5);

    data = read_file("poem.txt");

    cout<<data<<endl<<endl;
/*
    data = "I met a traveller from an antique land,\n"
            "Who said-\"Two vast and trunkless legs of stone\n"
            "Stand in the desert. . . . Near them, on the sand,\n"
            "Half sunk a shattered visage lies, whose frown,\n"
            "And wrinkled lip, and sneer of cold command,\n"
            "Tell that its sculptor well those passions read\n"
            "Which yet survive, stamped on these lifeless things,\n"
            "The hand that mocked them, and the heart that fed;\n"
            "And on the pedestal, these words appear:\n"
            "My name is Ozymandias, King of Kings;\n"
            "Look on my Works, ye Mighty, and despair!\n"
            "Nothing beside remains. Round the decay\n"
            "Of that colossal Wreck, boundless and bare\n"
            "The lone and level sands stretch far away\".";

    write_file("poem.txt", data);

    encrypt("poem",2,4);
    decrypt("poem",2,4);

    data = read_file("poem.txt");

    cout<<data<<endl<<endl;*/

    /*
    unsigned long long ass = data.length();

    char char_data[ass];
    char bin_data[ass*8];

    for(unsigned long long i = 0; i<ass; i++){

        char_data[i] = data[i];

        char_data[i+1] = '\0';

    }


    cout<<char_data<<endl;

    text_to_bin(char_data, ass, bin_data);

    cout<<bin_data<<endl;

    bin_to_text(bin_data, ass*8, char_data);

    cout<<"\n\n"<<char_data<<endl;*/

    /*string data = "I met a traveller from an antique land,\n"
                  "Who said-\"Two vast and trunkless legs of stone\n"
                  "Stand in the desert. . . . Near them, on the sand,\n"
                  "Half sunk a shattered visage lies, whose frown,\n"
                  "And wrinkled lip, and sneer of cold command,\n";

    write_file("test.txt", data);

    encrypt("test", 2, 5);
    decrypt("test", 2, 5);

    data = read_file("test.txt");

    cout<<data<<endl<<endl;

    data = "I met a traveller from an antique land,\n"
           "Who said-\"Two vast and trunkless legs of stone\n"
           "Stand in the desert. . . . Near them, on the sand,\n"
           "Half sunk a shattered visage lies, whose frown,\n"
           "And wrinkled lip, and sneer of cold command,\n";

    write_file("test.txt", data);

    encrypt("test", 2, 4);
    decrypt("test", 2, 4);

    data = read_file("test.txt");

    cout<<data<<endl<<endl;*/

    return 0;
}

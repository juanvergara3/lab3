#include <iostream>
#include "encription.h"
using namespace std;

int main()
{
/*
    short method;
    int seed;
    string archivo_natural;

    cout<<"Ingrese el nombre del archivo (sin extencion de archivo) metodo de codificacion deseado y la semilla: ";
    cin>>archivo_natural>>method>>seed;

    encrypt(archivo_natural, method, seed);

    decrypt(archivo_natural, method, seed);*/

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

    encrypt("poem",2,5);
    decrypt("poem",2,5);

    data = read_file("poem.txt");

    cout<<data<<endl<<endl;

    cout<<endl;

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

    cout<<data<<endl<<endl;

    return 0;
}

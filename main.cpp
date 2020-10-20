#include <iostream>
#include "encription.h"
using namespace std;

int main()
{
    /*
    short method;
    int seed;
    string archivo_natural = "test.txt";

    cout<<"Ingrese el metodo de codificacion deseado y la semilla: ";
    cin>>method>>seed;*/

    string test;
    cin>>test;

    test = text_to_bin(test);

    partition(test, 3);

    cout<<test<<endl;

    return 0;
}

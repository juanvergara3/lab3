#include <iostream>
#include "encription.h"
using namespace std;

int main()
{

    short method;
    int seed;
    string archivo_natural;

    cout<<"Ingrese el nombre del archivo (sin extencion de archivo) metodo de codificacion deseado y la semilla: ";
    cin>>archivo_natural>>method>>seed;

    encrypt(archivo_natural, method, seed);

    //unsigned long long size = size_of_file(name);

    //char *data_char = new char[size];
    //char *res_char = new char[size*8];

    //leer_txt(name, data_char);

    //cout<<"\n"<<data_char<<endl;

    //text_to_bin(data_char, res_char);

    //cout<<"\n"<<res_char<<endl;

    //delete [] data_char;
    //delete [] res_char;

    return 0;
}

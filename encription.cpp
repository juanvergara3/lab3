#include "encription.h"

void encrypt(string name, short method, int seed){

    string text;
    text = leer_txt(name);

}

string text_to_bin(string text){

    string bin;

    for(unsigned long long i = 0; i<text.length(); i++){

        for(int k = 0; k<8; k++){

            bin.push_back( char( ( ((text[i]<<k)&(0x80))/128) + 48 ) );

        }
    }
    return bin;
}

void partition(string bin, int seed)
{
    string partitioned;

   for(unsigned long long i = 0, k = 0; i<bin.length(); i++){

       partitioned.push_back(bin[i]);

       if((k+1)*seed-1 == i){

           k++;

           cout<<partitioned<<endl; //que hacer con los partidos

           partitioned.clear();
       }
   }
}

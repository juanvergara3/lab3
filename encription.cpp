#include "encription.h"

void encrypt(string name, short method, int seed){

    if(method == 1){
        string text;
        text = leer_txt(name+".txt");

        text = text_to_bin(text);

        text = method_1(text, seed);

        escribir_txt(name+".dat", text);
    }
    else if(method == 2){
        //unsigned long long size = size_of_file(name);
        //char *data_char = new char[size];
        //char *res_char = new char[size*8];

    }
    else cout<<"Metodo invalido."<<endl;
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

void text_to_bin(char *text, char *res){ //revisar******

    unsigned long long size = size_of_array(text);
    unsigned long long index = 0;

    for(unsigned long long i = 0; i<size-1; i++){

        for(int k = 0; k<8; k++){

            res[index] = ( char( ( ((text[i]<<k)&(0x80))/128) + 48 ) );
            index++;

        }
    }
}

void partition(string bin, int seed){ //Possibly useless
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

string method_1(string data, int seed){

    string partitioned, prev, result;
    int ones, ceros;

    for(int i = 0; i<seed; i++){ //se toma el primer grupo

        partitioned.push_back(data[i]);

    }

    prev = partitioned; //se guarda el primer grupo sin codificar para despues

    for(int k = 0; k < seed; k++){ //se invierten todos los bits

        if(partitioned[k]  == '0') partitioned[k] = '1';
        else partitioned[k] = '0';

    }

    result.append(partitioned);
    partitioned.clear();

    for(unsigned long long i = seed, k = 1; i < data.length(); i++){ //empieza desde el segundo grupo

        partitioned.push_back(data[i]);

        if((k+1)*seed-1 == i){

            k++;

            ones = count(prev.begin(), prev.end(), '1'); //se halla la cantidad de 1s y 0s en el grupo anterior
            ceros = count(prev.begin(), prev.end(), '0'); //para poder aplicar las reglas de codificacion

            prev = partitioned; //se toma el grupo actual sin codificar para usar en la siguiente iteracion

            for(int w = 0, index = 1; w<seed; w++){ // recorre cada grupo

                if(ceros == ones){ // cada bit del grupo se invierte

                    if(partitioned[w]  == '0') partitioned[w] = '1';
                    else if(partitioned[w]  == '1') partitioned[w] = '0';
                }

                else if(ceros > ones){ //se invierte cada 2 bits

                    if(index == 2){

                        if(partitioned[w]  == '0') {
                            partitioned[w] = '1';
                            index = 1;
                        }
                        else if(partitioned[w]  == '1') {
                            partitioned[w] = '0';
                            index = 1;
                        }
                    }
                    else index++;
                }

                else if(ceros < ones){ //se invierte cada 3 bits

                    if(index == 3){

                        if(partitioned[w]  == '0') {
                            partitioned[w] = '1';
                            index = 1;
                        }
                        else if(partitioned[w]  == '1') {
                            partitioned[w] = '0';
                            index = 1;
                        }
                    }
                    else index++;
                }

            } //final del for que recorre cada grupo

            result.append(partitioned);

            partitioned.clear();

        }
    }
    return result;
}

void method_2(string name, char *data, int seed){ //terminar***

}

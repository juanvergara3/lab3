#include "encription.h"

void encrypt(string name, string text, short method, int seed){

    if(method == 1){

        text = text_to_bin(text);

        text = encrypt_method_1(text, seed);

        text = bin_to_text(text);

        write_file(name+".dat", text);
    }

    else if(method == 2){

        unsigned long long size = text.length()+1;

        char data_char[size];
        char bin_char[size*8];

        strcpy (data_char, text.c_str());

        text_to_bin(data_char, size, bin_char);

        encrypt_method_2(bin_char, size*8, seed);

        bin_to_text(bin_char, size*8, data_char);

        write_file(name+".dat", size, data_char);

    }
    else cout<<"Metodo invalido."<<endl;
}

string decrypt(string name, short method, int seed){

    string text;

    if(method == 1){

        text = read_file(name+".dat");

        text = text_to_bin(text);

        text = decrypt_method_1(text, seed);

        text = bin_to_text(text);

        return text;
    }

    else if(method == 2){

        unsigned long long size = size_of_file(name+".dat");

        char data_char[size];
        char bin_char[size*8];

        read_file(name+".dat", data_char);

        text_to_bin(data_char, size, bin_char);

        decrypt_method_2(bin_char, size*8, seed);

        bin_to_text(bin_char, size*8, data_char);

        text = data_char;

        return text;

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

void text_to_bin(char *text, unsigned long long size, char *res){

    unsigned long long index = 0;

    for(unsigned long long i = 0; i<size; i++){

        for(int k = 0; k<8; k++){


                res[index] = ( char( ( ((text[i]<<k)&(0x80))/128) + 48 ) );
                index++;

        }
    }
    res[index] = '\0';
}

string bin_to_text(string text){

    string temp, res;
    int bin, dec, rem, base;

    for(unsigned long long i = 0; i<text.length(); i++){

        temp += text[i];

        if(temp.length() == 8){

            bin = stoi(temp);

            base = 1;
            dec = 0;

            while (bin > 0){
                rem = bin % 10;
                dec = dec + rem * base;
                base = base * 2;
                bin = bin / 10;
            }

            res += char(dec);

            temp.clear();

        }

    }
    return res;
}

void bin_to_text(char *text, unsigned long long size, char *res){

    char *temp = new char[9];
    int bin, dec, rem, base, temp_index = 0, res_index  = 0;

    for(unsigned long long i = 0; i<size; i++, temp_index++){

        temp[temp_index] = text[i];

        if(temp_index == 7){

            temp_index = -1;

            temp[8] = '\0';

            sscanf(temp, "%d", &bin); //what

            //int index = 0;
            //for (; temp[index]  != '\0'; ++index)
                //bin = bin * 10 + temp[index] - '0'; // borrar en el siguiente commit ****

            base = 1;
            dec = 0;

            while (bin > 0){
                rem = bin % 10;
                dec = dec + rem * base;
                base = base * 2;
                bin = bin / 10;
            }

            //if(char(dec) == '\0') dec = 32; //wtf????

            //if(char(dec) == '`') dec = 32; //What the actual damn //borrar en el siguiente commit ****

            res[res_index] = char(dec);

            res_index++;

        }
    }

    delete[] temp;
}

string encrypt_method_1(string data, int seed){

    unsigned long long seed_reference = seed;

    string group, prev, res;

    bool first = false;

    int ceros, unos;

    for(unsigned long long current_index = 0, previous_index = 0; current_index<data.length()+1; current_index++){ //recorre todo el string data

        group += data[current_index]; //crea un grupo de tamaño seed

        if( current_index - previous_index + 1 == seed_reference || current_index == data.length()){ //cuando pasa un grupo

            previous_index = current_index + 1;

           if(first == false){ //para el primer grupo

               prev = group;

               for(unsigned long long k = 0; k<group.length(); k++){ //invierte todos los bits del primer grupo

                   if(group[k] == '0') group[k] = '1';
                   else if (group[k] == '1') group[k] = '0';

               }

               //res = group;
               first = true;
           }

           else{//para los demas grupos

               unos = count(prev.begin(), prev.end(), '1'); //se halla la cantidad de 1s y 0s en el grupo anterior
               ceros = count(prev.begin(), prev.end(), '0'); //para poder aplicar las reglas de codificacion

               prev.clear();
               prev = group;

               if(ceros == unos){ //invierte todos los bits

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if(group[k] == '0') group[k] = '1';
                       else if (group[k] == '1') group[k] = '0';

                   }
               }
               else if (ceros>unos){

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if((k+1)%2 == 0){

                           if(group[k] == '0') group[k] = '1';
                           else if (group[k] == '1') group[k] = '0';

                       }
                   }
               }
               else if(ceros < unos){

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if((k+1)%3 == 0){

                           if(group[k] == '0') group[k] = '1';
                           else if (group[k] == '1') group[k] = '0';

                       }
                   }
               }

           }

           //para todos los grupos:
           res.append(group);
           group.clear();

        }
    }

    return res;
}

string decrypt_method_1(string data, int seed){

    unsigned long long seed_reference = seed;

    string group, prev, res;

    bool first = false;

    int ceros, unos;

    for(unsigned long long current_index = 0, previous_index = 0; current_index<data.length()+1; current_index++){ //recorre todo el string data

        group += data[current_index]; //crea un grupo de tamaño seed

        if( current_index - previous_index + 1 == seed_reference  || current_index == data.length() ){ //cuando pasa un grupo

            previous_index = current_index + 1;

           if(first == false){ //para el primer grupo

               for(unsigned long long k = 0; k<group.length(); k++){ //invierte todos los bits del primer grupo

                   if(group[k] == '0') group[k] = '1';
                   else if (group[k] == '1') group[k] = '0';

               }

               //res = group;
               prev = group;

               first = true;
           }

           else{//para los demas grupos

               unos = count(prev.begin(), prev.end(), '1'); //se halla la cantidad de 1s y 0s en el grupo anterior
               ceros = count(prev.begin(), prev.end(), '0'); //para poder aplicar las reglas de codificacion

               prev.clear();

               if(ceros == unos){ //invierte todos los bits

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if(group[k] == '0') group[k] = '1';
                       else if (group[k] == '1') group[k] = '0';

                   }
               }
               else if (ceros>unos){

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if((k+1)%2 == 0){

                           if(group[k] == '0') group[k] = '1';
                           else if (group[k] == '1') group[k] = '0';

                       }
                   }
               }
               else if(ceros < unos){

                   for(unsigned long long k = 0; k<group.length(); k++){

                       if((k+1)%3 == 0){

                           if(group[k] == '0') group[k] = '1';
                           else if (group[k] == '1') group[k] = '0';

                       }
                   }
               }

               prev = group;


           }

           //para todos los grupos:
           res.append(group);
           group.clear();

        }
    }
    return res;

}

void encrypt_method_2(char *data, unsigned long long size, int seed){

    unsigned long long seed_reference = seed;

    char *group = new char[seed+1]; //tiene en cuenta el \0

    for(unsigned long long current_index = 0, previous_index = 0, group_index = 0; current_index<size; current_index++){ //recorre todo el array data

        group[group_index] = data[current_index]; //crea un grupo de tamaño seed
        group_index++;

        if( current_index - previous_index + 1== seed_reference){ //cuando pasa un grupo

             group[group_index] = '\0';

            previous_index = current_index + 1;

            group_index--;

            for(int it = 0, temp = seed; it<seed; it++, group_index++){ //encripta el grupo creado anteriormente

                data[ (current_index + 1) - temp ] = group[group_index];

                temp--;

                if(group_index == seed_reference -1){ //despues de asignar el ultimo bit de group al primero de data
                    group_index = -1; // resetea group_index a -1 porque el for le suma 1 en la siguiente iteracion
                }

            }//final for de encripcion individual

            group_index = 0; //reseta group_index para poder crear el siguiente grupo
        }
    }
    delete[] group;
}

void decrypt_method_2(char *data, unsigned long long size, int seed){

    unsigned long long seed_reference = seed;

    char *group = new char[seed+1]; //tiene en cuenta el \0

    for(unsigned long long current_index = 0, previous_index = 0, group_index = 0; current_index<size; current_index++){ //recorre todo el array data

        group[group_index] = data[current_index]; //crea un grupo de tamaño seed
        group_index++;

        if( current_index - previous_index + 1== seed_reference){ //cuando pasa un grupo

            previous_index = current_index + 1;

            group_index = 0;

            for(int it = 0, temp = 0; it<seed; it++, group_index++, temp--){ //desencripta el grupo creado anteriormente

                data[ (current_index) - temp ] = group[group_index]; // el primer bit de group se asigna al ultimo de data

                if(group_index == 0) temp =  seed; // despues de la asignacion del primer bit

            }//final for de desencripcion individual

            group_index = 0; //reseta group_index para poder crear el siguiente grupo
        }
    }
    delete[] group;

}



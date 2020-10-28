#include "file_handling.h"

void write_file(string name, string data) {

    fstream file (name, fstream::out | fstream::binary);

    //file<<data;

    file.write(data.c_str(), data.length());

    file.close();
}

void write_file(string name, unsigned long long size, char *data){

    fstream file (name, fstream::out | fstream::binary);

    file.write(data, size);

    file.close();

}

/*
string leer_txt(string name) { //linea a linea

    fstream file(name, fstream::in);

    if(file.is_open()){

        string temp, temp2;

        while(! file.eof() ){

            getline(file, temp2);
            temp.append(temp2);
            temp.append("\n");

        }
        file.close();

        return temp;

    } else{
       cout<<"Error de apertura!"<<endl;
       return "";
    }
}*/

string read_file(string name) {

    fstream file(name, fstream::in | fstream::binary);

    if(file.is_open()){

        string res;
        char temp;

         unsigned long long size = size_of_file(name);

        for(unsigned long long k = 0; k<size; k++){

            temp = file.get();

            res.push_back(temp); //the EOF here was breaking my program smh

        }

        file.close();

        return res;

    } else{
       cout<<"Error de apertura!"<<endl;
       return "";
    }
}

void read_file(string name, char *res){

    fstream file(name, fstream::in | fstream::binary);

    if(file.is_open()){

        unsigned long long size = size_of_file(name);
        char temp;

        for(unsigned long long k = 0; k<size; k++){

            temp = file.get();

            if(temp != EOF) res[k] = temp;
            else res[k] = '\0';
        }

        file.close();

    }
    else cout<<"Error de apertura!"<<endl;
}

unsigned long long size_of_file(string name){

    fstream file(name, fstream::in | fstream ::ate | fstream::binary);

     if(file.is_open()){

         unsigned long long size;

         size = file.tellg();

         file.close();

         return size;
     }

     else{
         cout<<"Error de apertura!"<<endl;
         return 0;
     }
}

unsigned long long size_of_array(char *array){ //Posiblemente inutil

    unsigned long long size = 0;

    for(unsigned long long k = 0;;k++){ // calcula el tamaño del arreglo de caracteres array

        if(array[k] != '\0') size++;
        else{
            size++;
            break;
        }
    }

    return size;
}

bool is_number(string s){

    for(unsigned long long k = 0; k<s.length(); k++){

        if(isdigit(s[k]) == false) return false;

    }

    return true;

}

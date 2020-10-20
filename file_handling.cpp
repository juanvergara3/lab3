#include "file_handling.h"

void escribir_txt(string name, string data) {

    fstream file (name, fstream::out | fstream::binary);

    file<<data;

    //file.write(data.c_str(), data.length());

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
/*
string leer_txt(string name) { //letra a letra

    fstream file(name, fstream::in);

    if(file.is_open()){

        string res;

        while(! file.eof() ){

            res.push_back(file.get());

        }
        file.close();

        return res;

    } else{
       cout<<"Error de apertura!"<<endl;
       return "";
    }
}*/

string leer_txt(string name) { //letra a letra pero de otra forma

    fstream file(name, fstream::in);

    if(file.is_open()){

        string res;

         long long size = size_of_file(name);

        for(long long k = 0; k<size; k++) res.push_back(file.get());

        file.close();

        return res;

    } else{
       cout<<"Error de apertura!"<<endl;
       return "";
    }
}

int size_of_file(string name){

fstream file(name, fstream::in | fstream ::ate);

return file.tellg();

}

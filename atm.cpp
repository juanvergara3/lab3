#include "atm.h"

bool validate_user(string user, string password, short method, int seed){

    string ref;

    if(user == "admin"){

        ref = decrypt("sudo", method, seed);

        if(password == ref) return true;

        else return false;
    }

    else{
        ref  = decrypt("users", method, seed);

        if (ref.find(user+','+password) != string::npos)
            return true;
        else
            return false;
    }
}

void register_user(string user, string password, string amount, short method, int seed){

}

void withdraw(string user, int retiro, short method, int seed){

    string ref, res, first, second;
    int value;
    unsigned long long start, finish;

    ref  = decrypt("users", method, seed);

    //cout<<ref<<endl;

    start = ref.find(user) + user.length() + 1;

    start = ref.find(',' , start) + 1;

    finish = ref.find('\r', start);

    char * cstr = new char [ref.length()+1];

    strcpy (cstr, ref.c_str());

    for(unsigned long long k = 0; k < start; k ++) first += cstr[k];

    for(unsigned long long k = finish + 2; k < ref.length(); k ++) second += cstr[k];

    for(unsigned long long k = start; k < finish; k ++) res += cstr[k];

    delete [] cstr;

    value = stoi(res); //convertir el saldo a entero

    res.clear();

    value -= retiro; //retirar

    res = to_string(value); //convertir a string de nuevo

    res += "\r\n";

    ref.clear();

    ref += first;
    ref += res;
    ref+= second;

    encrypt("users", ref, method, seed);

}

void check_balance(string user, short method, int seed){

    string ref, res;
    unsigned long long start, finish;

    ref  = decrypt("users", method, seed);

    start = ref.find(user) + user.length() + 1;

    start = ref.find(',' , start) + 1;

    finish = ref.find('\r', start);

    char * cstr = new char [ref.length()+1];

    strcpy (cstr, ref.c_str());

    for(;start < finish; start ++) res += cstr[start];

    delete [] cstr;

    cout<<"Su saldo actual es: "<<res<<endl;

}

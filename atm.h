#ifndef ATM_H
#define ATM_H

//#include<iostream>
//#include <string>
#include "encription.h"

using namespace std;

bool validate_user(string user, string password, short method, int seed);
void register_user(string user, string password, string amount, short method, int seed);
void withdraw(string user, int retiro, short method, int seed);
void check_balance(string user, short method, int seed);

#endif // ATM_H

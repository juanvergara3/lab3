#ifndef ATM_H
#define ATM_H

//#include<iostream>
//#include <string>
#include "encription.h"

using namespace std;

bool validate_user(string user, string password);
void register_user(string user, string password, string amount);
void withdraw(string user, int retiro);
void check_balance(string user);

#endif // ATM_H

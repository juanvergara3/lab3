#ifndef ATM_H
#define ATM_H

#include "encription.h"

using namespace std;

bool validate_user(string user, string password, short method, int seed);
void register_user(string user, string password, int amount, short method, int seed);
void withdraw(string user, int retiro, short method, int seed);
void check_balance(string user, short method, int seed);
void display_users(short method, int seed);
void new_admin_password(string password, short method, int seed);
#endif // ATM_H

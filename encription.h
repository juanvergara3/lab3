#ifndef ENCRIPTION_H
#define ENCRIPTION_H

#include<iostream>
#include <string>
#include "file_handling.h"

using namespace std;

void encrypt(string name, short method,  int seed);
string text_to_bin(string text);
void partition(string bin, int seed);

#endif // ENCRIPTION_H

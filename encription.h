#ifndef ENCRIPTION_H
#define ENCRIPTION_H

#include<iostream>
#include <string>
#include <bits/stdc++.h>
#include "file_handling.h"

using namespace std;

void encrypt(string name, short method,  int seed);
string text_to_bin(string text);
void text_to_bin(char *text, char *res);
void partition(string bin, int seed);
string method_1(string data, int seed);
void method_2(char *data, int seed);

#endif // ENCRIPTION_H

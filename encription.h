#ifndef ENCRIPTION_H
#define ENCRIPTION_H

#include<iostream>
#include <string>
#include <bits/stdc++.h>
#include "file_handling.h"

using namespace std;

void encrypt(string name, short method,  int seed);
void decrypt(string name, short method,  int seed);

string text_to_bin(string text);
void text_to_bin(char *text, unsigned long long size,char *res);

string bin_to_text(string text);
void bin_to_text(char *text, unsigned long long size, char *res);

string encrypt_method_1(string data, int seed);
void encrypt_method_2(char *data, unsigned long long size,  int seed);

string decrypt_method_1(string data, int seed);
void decrypt_method_2(char *data, unsigned long long size, int seed);

#endif // ENCRIPTION_H

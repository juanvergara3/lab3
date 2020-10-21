#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void escribir_txt(string name, string data);
void escribir_txt(string name, char *data);
string leer_txt(string name);
void leer_txt(string name, char *res);
unsigned long long size_of_file(string name);
unsigned long long size_of_array(char *array);

#endif // FILE_HANDLING_H

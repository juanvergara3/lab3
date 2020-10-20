#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include<iostream>
#include <fstream>
#include <string>

using namespace std;

void escribir_txt(string name, string data);
string leer_txt(string name);
int size_of_file(string name);

#endif // FILE_HANDLING_H

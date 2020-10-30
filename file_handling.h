#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include<iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

void write_file(string name, string data);
void write_file(string name, unsigned long long size, char *data);

string read_file(string name);
void read_file(string name, char *res);

unsigned long long size_of_file(string name);
//unsigned long long size_of_array(char *array);

bool is_number(string s);

#endif // FILE_HANDLING_H

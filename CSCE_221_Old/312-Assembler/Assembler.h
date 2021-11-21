// File: Assembler.h
// Author: Joseph Shumway
// Date: 11/4/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file is the header file for Assembler.cpp

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>
#include <map>
#include <bitset>


using std::cout;
using std::endl;
using std::string;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::map;
using std::bitset;

// symbol definition
struct symbol
{
    public:
        symbol(string n = "", int v = 0) : name(n), value(v) {}
        string name;
        int value;
};

// setup functions
void setup_predefined_symbols();
void setup_mnemonics();
ifstream get_ifs_from_file(string file);
void setup_ofs(string file);

// iterations
void first_iteration(string filename);
void second_iteration(string filename);

// symbol table building functions
bool skippable_line(string line);
bool label_line(string line);
bool variable_line(string line);
bool C_line(string line);

void add_symbol(string s_name, int value);
bool symbol_exists(string s_name);
int find_s_by_name(string s_name);
string rmv_identifiers(string line);
int add_variable(string line);
void make_C_parts(string line);
string code_C_parts_to_binary();

string parse_comp(string line);
string parse_dest(string line);
string parse_jump(string line);

// utility functions
void print_s_table();
string clean_line(string line);
void write_line(string line);

#endif
// File: Assembler.cpp
// Author: Joseph Shumway
// Date: 11/4/2021
// Section: 504
// E-mail: joseph.shumway@tamu.edu 
// Description:
// This file assembles an .asm file into a .hack binary file

#include "Assembler.h"

// declare our symbol table
vector<symbol> s_table;
int var_line_num = 16;
int var_address = 0;

string dest;
string comp;
string jump;

string c_dest;
string c_comp;
string c_jump;

map<string, string> m_dest;
map<string, string> m_comp;
map<string, string> m_jump;

ofstream ofs;


int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "No supplied file! Make sure you specify a file while starting the program" << endl;
        exit(1);
    }

    
    string filename = argv[1];    
    cout << filename << endl;
    // setup 
    setup_predefined_symbols();
    setup_mnemonics();
    setup_ofs("MyProg.hack");

    // do some iterations on our .asm file
    first_iteration(filename);
    second_iteration(filename);

    // print out symbol table
    //print_s_table();

    return 0;
}

// setup functions
void setup_predefined_symbols() {
    // add R symbols
    add_symbol("R0", 0);
    add_symbol("R1", 1);
    add_symbol("R2", 2);
    add_symbol("R3", 3);
    add_symbol("R4", 4);
    add_symbol("R5", 5);
    add_symbol("R6", 6);
    add_symbol("R7", 7);
    add_symbol("R8", 8);
    add_symbol("R9", 9);
    add_symbol("R10", 10);
    add_symbol("R11", 11);
    add_symbol("R12", 12);
    add_symbol("R13", 13);
    add_symbol("R14", 14);
    add_symbol("R15", 15);

    // add screen and keyboard
    add_symbol("SCREEN", 16384);
    add_symbol("KBD", 24576);

    // add other symbols
    add_symbol("SP", 0);
    add_symbol("LCL", 1);
    add_symbol("ARG", 2);
    add_symbol("THIS", 3);
    add_symbol("THAT", 4);
}

void setup_mnemonics() {
    m_dest = {
        {"", "000"},
        {"M",    "001"},
        {"D",    "010"},
        {"MD",   "011"},
        {"A",    "100"},
        {"AM",   "101"},
        {"AD",   "110"},
        {"AMD",  "111"}
    };


    m_comp = {
        {"0",     "0101010"},
        {"1",     "0111111"},
        {"-1",    "0111010"},
        {"D",     "0001100"},
        {"A",     "0110000"},
        {"M",     "1110000"},
        {"!D",    "0001101"},
        {"!A",    "0110001"},
        {"!M",    "1110001"},
        {"-D",    "0001111"},
        {"-A",    "0110011"},
        {"-M",    "1110011"},
        {"D+1",   "0011111"},
        {"A+1",   "0110111"},
        {"M+1",   "1110111"},
        {"D-1",   "0001110"},
        {"A-1",   "0110010"},
        {"M-1",   "1110010"},
        {"D+A",   "0000010"},
        {"D+M",   "1000010"},
        {"D-A",   "0010011"},
        {"D-M",   "1010011"},
        {"A-D",   "0000111"},
        {"M-D",   "1000111"},
        {"D&A",   "0000000"},
        {"D&M",   "1000000"},
        {"D|A",   "0010101"},
        {"D|M",   "1010101"}
    };


    m_jump = {
        {"",   "000"},
        {"JGT",    "001"},
        {"JEQ",    "010"},
        {"JGE",    "011"},
        {"JLT",    "100"},
        {"JNE",    "101"},
        {"JLE",    "110"},
        {"JMP",    "111"}
    };


   
    
}

ifstream get_ifs_from_file(string file) {
    ifstream ifs(file);
    if (!ifs.is_open()) {
        cout << "File not found!";
        exit(1);
    }

    return ifs;
}

void setup_ofs(string file) {
    ofs.open(file);
    if (!(ofs.is_open())) {
        cout << "File not found!";
        exit(1);
    }
}


// iterations
void first_iteration(string filename) {
    ifstream stream = get_ifs_from_file(filename);
    string line;
    int line_num = 0;

    //cout << "First Iteration: " << endl << endl;

    // iterate through file
    while (getline(stream, line)) {
        
        // clear whitespace and comments
        line = clean_line(line);

        // grab labels and add symbols for them
        if (label_line(line)) {
            add_symbol(rmv_identifiers(line), line_num);
            
            // account for creation of label in line num
            if (line_num > 0) {
                line_num--;
            }
            //cout << "added: " << rmv_identifiers(line) << "  value:" << line_num << endl;
        }

        // if line isn't empty
        if (line.size() > 0) {
            
            // print current line
            // cout << line << endl;

            // increment line num
            line_num++;
        }
    }
}

void second_iteration(string filename) {
    ifstream in_stream = get_ifs_from_file(filename);
    //ofstream* tmp_out_stream = get_ofs_from_file("/mnt/c/.School/CSCE_221/312-Assembler/output.tmp");
    string line;
    string binary_line;
    int line_num = 0;
    int A = 0;

    
    

    // cout << "\n\n\n" << "Second Iteration:" << endl << endl;

    // iterate through file
    while (getline(in_stream, line)) {
        
        line = clean_line(line);

        //cout << "r? " << line.find("\r") << endl;

        // A instruction
        // grab variables and add symbols for them
        if (variable_line(line)) {
            A = add_variable(line);
            binary_line = bitset<16>(A).to_string();
            // cout << "A: " << line << endl;
            // cout << "a: " << A << endl;
            // cout << "A:";
            binary_line.append("\n");
            //cout << binary_line;
            write_line(binary_line);
        } else {

        }


        // C instruction translation
        if (C_line(line)) {
            make_C_parts(line);

            // translate C parts into binary
            binary_line = code_C_parts_to_binary();
            // cout << "C:" << line << endl;
            //cout << binary_line;
            write_line(binary_line);
        }

        // increment line number
        line_num++;
    }
    // tmp_out_stream->close();
}



// symbol table building functions
bool skippable_line(string line) {
    if (line.size() <= 0) {return true;}
    return (line.at(0) == '/' || line.at(0) == ' ' || line.size() <= 1);
}

bool label_line(string line) {
    //cout << line << endl;
    return (line.front() == '(' && line.back() == ')');
}

bool variable_line(string line) {
    
    if (line.front() == '@') {
        string t_line = line.substr(1, line.size() - 1);
        //cout << t_line << endl;
        return true;
    }
    return false;
}

bool C_line(string line) {
    return (line.front() =='0' || line.front() == 'A' || line.front() == 'D' || line.front() == 'M');
}


void add_symbol(string s_name, int value) {
    s_table.push_back(symbol(s_name, value));
}

bool symbol_exists(string s_name) {

    // s_name.erase(s_name.size() - 1);
    for (auto each : s_table) {
        //cout << each.name << " =? " << s_name << endl;
        //cout << each.name.size() << " =? " << s_name.size() << endl;
        if (each.name == s_name) {
            //cout << each.name << " = " << s_name << endl;
            return true;
        }
    }
    return false;
}

int find_s_by_name(string s_name) {
    for (auto each : s_table) {
        if (each.name == s_name) {
            return each.value;
        }
    }
    return -1;
}

string rmv_identifiers(string line) {
    if (line.at(0) == '(') {
        return line.substr(1, line.size() - 2);
    }

    if (line.at(0) == '@') {
        return line.substr(1, line.size() - 1);
    }
    return "";
}


void make_C_parts(string line) {
    // parse C instruction into 3 pieces: dest, comp, and jump
    dest = parse_dest(line);
    if (dest != "") {
        // cout << "Dest " << dest << " found in: " << line << endl;
    }

    comp = parse_comp(line);
    if (comp != "") {
        // cout << "Comp " << comp << " found in: " << line << endl;
    }

    jump = parse_jump(line);
    if (jump != "") {
        // cout << "Jump " << jump << " found in: " << line << endl;
    }
}

string code_C_parts_to_binary() {
    c_dest = m_dest[dest];
    c_comp = m_comp[comp];
    c_jump = m_jump[jump];
    string output;
    output.append("111");
    output.append(c_comp);
    output.append(c_dest);
    output.append(c_jump);
    output.append("\n");
    return output;
}


int add_variable(string line) {

    // cout << rmv_identifiers(line) << endl;

    // first check if the value is a number or letter
    if (isalpha(rmv_identifiers(line).at(0))) {
        // check if variable already exists in table and inserts if unique
        if (!symbol_exists(rmv_identifiers(line))) {
            add_symbol(rmv_identifiers(line), var_line_num);
            var_address = var_line_num;
            var_line_num++;
            return var_address;
        
        // if variable already exists, find in table and assign value to var address
        } else {
            var_address = find_s_by_name(rmv_identifiers(line));
            return var_address;
        }
    }
    return std::stoi(rmv_identifiers(line));
    
}


string parse_comp(string line) {
    if (line.find("=") == string::npos) {
        string token = line.substr(0, line.find(";"));
        return token;
    } else {
        string token = line.substr(line.find("=") + 1, line.find(";"));
    return token;
    }
}

string parse_dest(string line) {
    if (line.find("=") == string::npos) {
        return "";
    } else {
        string token = line.substr(0, line.find("="));
        return token;
    }
}

string parse_jump(string line) {
    if (line.find(";") == string::npos) {return "";}
    string token = line.substr(line.find(";") + 1, line.size() - 1);
    return token;
}

// utility functions
void print_s_table() {
    cout << endl << "Symbol :  Address" << endl;
    cout << "-------:---------" << endl;

    for (auto s : s_table) {
        cout << s.name << "     :     " << s.value << endl;
    }
    cout << endl << endl;
}

string clean_line(string l) {
    
    // remove spaces
    while(l.find(" ") != string::npos) {
        l.erase(l.find(" "), 1);
    }

    // remove that dagnabbit "\r"
    while(l.find("\r") != string::npos) {
        l.erase(l.find("\r"), 1);
    }

    // remove comments
    if (l.find("/") != string::npos) {
        // cout << "SUBSTRING:" << l.substr(0, l.find("/")) << endl << endl;
        l = l.substr(0, l.find("/"));
    }
    return l;
}

void write_line(string line) {
    ofs << line;
}
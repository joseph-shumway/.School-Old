#include <iostream>
#include "Record.h"
#include <string>

using std::cout;
using std::endl;

// getters and setters
string Record::get_title() const {
    return title;
}
string Record::get_author() const {
    return author;
}
string Record::get_ISBN() const {

    return ISBN;
}
string Record::get_year() const {
    return year;
}
string Record::get_edition() const {
    return edition;
}
void Record::set_title(string t) {
    title = t;
}
void Record::set_author(string a) {
    author = a;
}
void Record::set_ISBN(string i) {
    ISBN = i;
}
void Record::set_year(string y) {
    year = y;
}
void Record::set_edition(string e) {
    edition = e;
}


// constructors
Record::Record() {
    title = "";
    author = "";
    ISBN = "";
    year = "";
    edition = "";
}

Record::Record(string t, string a, string i, string y, string e) {
    title = t;
    author = a;
    ISBN = i;
    year = y;
    edition = e;
}





// operator methods
std::istream& operator>>(std::istream& is, Record& rec) {
    string line;
    std::getline(is, line);

    // skip the first empty line if it exists

    //cout << '"' << line.size() << '"' << endl;
    if (line.size() == 1) {
        std::getline(is, line);
        //cout << "Skip line" << endl;
    }

    if (line.size() == 0) {
        std::getline(is, line);
        //return is;
    }

    // grab data
    rec.set_title(line);
    //cout << "Title: " << line << endl;

    std::getline(is, line);
    rec.set_author(line);
    //cout << "Author: " << line << endl;

    std::getline(is, line);
    rec.set_ISBN(line);
    //cout << "ISBN: " << line << endl;

    std::getline(is, line);
    rec.set_year(line);
    //cout << "Year: " << line << endl;

    std::getline(is, line);
    rec.set_edition(line);
    //cout << "Edition: " << line << endl << endl;
    
    return is;
}

std::ostream& operator<<(std::ostream& os, Record& rec) {
    
    os << rec.get_title() << endl;
    os << rec.get_author() << endl;
    os << rec.get_ISBN() << endl;
    os << rec.get_year() << endl;
    os << rec.get_edition();
    
    return os;
}

bool operator==(const Record& r1, const Record& r2){
    if (r1.get_title() != r2.get_title()) {
        return false;
    }
    if (r1.get_author() != r2.get_author()) {
        return false;
    }
    if (r1.get_ISBN() != r2.get_ISBN()) {
        return false;
    } 
    return true;
}

bool operator<(const Record& lhs, const Record& rhs) {
    if (lhs.get_title() < rhs.get_title()) {
        return true;
    }
    
    if (lhs.get_author() < rhs.get_author()) {
        return true;
    }

    if (lhs.get_ISBN() < rhs.get_ISBN()) {
        return true;
    }
    
    return false;
}
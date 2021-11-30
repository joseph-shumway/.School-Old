#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>
using std::string;

class Record {
private:
    //member variables
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    std::string edition;
public:
    
    Record(string t, string a, string i, string y, string e);
    Record();
    
    string get_title() const;
    string get_author() const;
    string get_ISBN() const;
    string get_year() const;
    string get_edition() const;

    void set_title(string t);
    void set_author(string a);
    void set_ISBN(string i);
    void set_year(string y);
    void set_edition(string e);
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
bool operator<(const Record& lhs, const Record& rhs);
#endif
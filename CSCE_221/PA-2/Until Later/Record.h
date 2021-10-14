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
    //accessor/mutator functions
    // std::string get_title(void) const;
    // ... for all 5 fields

    string get_title();
    string get_author();
    string get_ISBN();
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
bool operator<(const Record& lhs, const Record& rhs);
#endif
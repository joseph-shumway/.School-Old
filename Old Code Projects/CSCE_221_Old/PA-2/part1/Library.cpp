#include "Library.h"
using std::vector;
using std::string;

//Searches for a title in the database and returns vector of matching records
vector<Record> Library::search(const std::string title) const {
    vector<Record> records;
    
    return records;
}

//Imports records from a file.  Does not import duplicates.
// Return the number of records added to the database
int Library::import_database(const std::string filename) {
    return 0;
}

//Exports the current database to a file
//Return the number of records exported
int Library::export_database(const std::string filename) const {
    return 0;
}

void Library::print_database() const {
    
    book_db.at(0).print_list();
}

//add record to database, avoid complete duplicates
//  return true if unique
bool Library::add_record(const Record r) {
    int c = 0;

    c = (int) r.get_title().at(0) - 65;
    cout << "C: " << c << endl;

    book_db.at(c).insert_last(r);
    
    return true;
}

//Deletes a record from the database
void Library::remove_record(const Record r) {
    int c;
    c = (int) r.get_title().at(0) - 65;

    //book_db.at(c).remove_after();
}

// The following functions are tentative, pending a redo of Part 2
// Please do not implmenet them until we provide more details.

//Prompts user for yes or no and returns choice Y or N
char Library::prompt_yes_no() {
    return 'Y';
}

//Given a vector of menu options returns index of choice
int Library::prompt_menu(std::vector<std::string>) {
    return 0;
}

//Prompts user for a new record
Record Library::prompt_record() {
    Record r;
    return r;
}

//Prompt for a valid title
string Library::prompt_title() {
    return "hello";
}

// Prompt for a valid string
string Library::prompt_string(std::string prompt) {
    return "hello";
}
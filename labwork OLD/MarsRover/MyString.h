// TODO: Implement this header file
#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
using std::ostream;

class MyString {
private:
    int strSize;
    char* stringContent;

public:
    MyString();
    MyString(const MyString& str);
    MyString(const char* s);
    ~MyString();

    void resize(int n);
    int capacity();
    unsigned int size() const;
    int length();
    const char* data();
    bool empty();
    char& front() const;
    char& at(size_t pos) const;
    void clear();

    friend ostream& operator<< (ostream& os, const MyString& str);
    friend bool operator== (const MyString& str1, const MyString& str2);
    //friend MyString& operator+ (const MyString& str1, const MyString& str2);

    MyString& operator= (const MyString& str);
    MyString& operator+= (const MyString& str);
    
    
    int find (const MyString& str, size_t pos = 0);

};

#endif

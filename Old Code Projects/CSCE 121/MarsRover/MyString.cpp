// TODO: Implement this source file


#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

MyString::MyString() : strSize(0), stringContent(new char()) {
  //strSize(0);
  //stringContent = new char[1];
}

MyString::MyString(const MyString& str) : strSize(str.strSize), stringContent(str.stringContent) {
  // nothing to see here
}

MyString::MyString(const char* s) : strSize(1), stringContent(nullptr) {
  

  int counter = 0;
  while (s[counter] != '\0') {
    counter++;
  }
  //cout << "COUNTER: " << counter << endl;

  stringContent = new char[counter + 1];
  for (int i = 0; i < counter; i++)
  {
    stringContent[i] = s[i];
  }

  stringContent[counter + 1] = '\0';

  // for (int i = 0; i < counter; i++) 
  // {
  //   cout << stringContent[i];
  // }
  strSize = counter;
  
}

MyString::~MyString() {
  //delete[] stringContent;
}

void MyString::resize(int n) {
  char* newString = new char[n + 1];
  int end = 0;

  if (n < strSize) {end = n;}
  if (n > strSize) {end = strSize;}

  for (int i = 0; i < end; i++)
  {
    newString[i] = stringContent[i];
  }
  newString[n + 1] = '\0';
  //delete[] stringContent;
  stringContent = newString;
  strSize = n;
}

int MyString::capacity() {
  return strSize + 1;
}

unsigned int MyString::size() const{
  return strSize;
}

int MyString::length() {
  return strSize;
}

const char* MyString::data() {
  return stringContent;
}

bool MyString::empty() {
  return strSize == 0;
}

char& MyString::front() const {
  return stringContent[0];
}

char& MyString::at(size_t pos) const {

  if (strSize == 0) {
    throw std::out_of_range("Error: out of range");
  }
  
  if (pos > (size_t) strSize - 1) {
    throw std::out_of_range("Error: out of range");
  }

  return this->stringContent[pos];
}

void MyString::clear() {
  //delete[] stringContent;
  stringContent = new char[1];
  stringContent[0] = '\0';
  strSize = 0;
  
} 

ostream& operator<< (ostream& os, const MyString& str) {
  os << str.stringContent;
  return os;
}

MyString& MyString::operator= (const MyString& str) {
  //delete[] stringContent;
  stringContent = str.stringContent;
  return *this;
}

MyString& MyString::operator+= (const MyString& str) {
  char* newString = new char[str.strSize + strSize];

  for (unsigned int i = 0; i < strSize; i++){
    newString[i] = stringContent[i];
  }

  for (unsigned int i = 0; i < str.strSize; i++){
    newString[strSize + i] = str.stringContent[i];
  }

  strSize += str.strSize;
  newString[strSize] = '\0';

  //delete[] stringContent;
  
  stringContent = newString;
  return *this;
}

bool operator== (const MyString& str1, const MyString& str2) {
  //int length = 0;
  
  if (str1.size() > str2.size()) {return false;}
  
  for (int i = 0; i < str1.size(); i++)
  {
    if (str1.stringContent[i] != str2.stringContent[i]) {return false;}
  }

  return true;
  
}

// MyString& operator+ (MyString& str1, MyString& str2) {
//   char* newString = new char[str1.size() + str2.size()];
  
//   for (int i = 0; i < strSize; i++)
//   {
//     newString[i] = stringContent[i];
//   }

//   for (int i = 0; i < str.strSize; i++)
//   {
//     newString[strSize + i] = str.stringContent[i];
//   }
//   strSize += str.strSize;
//   newString[strSize] = '\0';

//   return str1 += str2;
// }

int MyString::find (const MyString& str, size_t pos) {
  //cout << endl;
  //cout << "String to search in: " << stringContent << endl;
  //cout << "String to find: " << str << endl;
  //cout << "Start at: " << pos << endl;

  //i = current string index for main string
  for (int i = pos; i < strSize; i++) {
    if (stringContent[i] == str.stringContent[0]) {
      //cout << "First letter match: '" << stringContent[i] << "' at: " << i << endl;

      // edge case where string size is 1
      if (str.strSize == 1) {return i;}

      //j = current string index for other string
      for (int j = 1; j < str.strSize; j++) {
        if (stringContent[i + j] != str.stringContent[j]) {break;}
        //cout << "Found next letter '" << stringContent[i+j] <<"'" << endl;
        if (j == str.strSize - 1) {return i;}
      }
    }
    
    
  }
  
  
  return -1;
}

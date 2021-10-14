
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;

int main()
{
  int x = 50000;

  for (int i = 2018; i < 2025; i++)
  {
    /* code */
    x = x + (1000) + (.05 * x);

  }
  
  

  cout << endl << x << endl << endl;
}
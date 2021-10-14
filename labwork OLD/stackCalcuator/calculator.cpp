#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";

  Stack stack;
  string input = "";

  getline(cin, input);

  istringstream ss;
  ss.str(input);

  input = "";

  
  
  push(stack, 0);
  // cout << "Initial ";
  // printStack(stack);

  int RHS = 0;
  int LHS = 0;
  int value = 0;
  while(ss >> input) {
    if (input == "+" || input == "-" || input == "*" || input == "/" || input == "=") {
      switch (input[0]) {
        case '+': 
          RHS = pop(stack);
          LHS = pop(stack);
          push(stack, LHS + RHS);
          // cout << "+ found" << endl;
          // cout << "RHS: " << RHS << endl;
          // cout << "LHS: " << LHS << endl;
          // printStack(stack);
          break;

        case '-':
          RHS = pop(stack);
          LHS = pop(stack);
          push(stack, LHS - RHS);
          // printStack(stack);
          break;

        case '*':
          RHS = pop(stack);
          LHS = pop(stack);
          push(stack, LHS * RHS);
          // printStack(stack);
          break;

        case '/':
          RHS = pop(stack);
          LHS = pop(stack);
          push(stack, LHS / RHS);
          //printStack(stack);
          break;
        case '=':
          cout << "Ans: " << pop(stack) << endl;
          // printStack(stack);
          break; break;
        default:
          break;
      }
    } else {
      value = std::stoi(input);
      push(stack, value);
    }
      
  }

  delete[] stack.numbers;
  

  //cout << endl;
  return 0;
}
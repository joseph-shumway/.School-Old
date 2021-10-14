#include "functions.h"
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  //cout << endl;

  if (stack.count + 1 > stack.capacity) {
    int* numbers = new int[stack.capacity * 2];

    for (int i = 0; i < stack.capacity; i++) {
      numbers[i] = stack.numbers[i];
    }
    stack.count = stack.capacity;
    stack.capacity *= 2;
    delete[] stack.numbers;
    stack.numbers = numbers;
  }

  stack.numbers[stack.count] = number;
  //cout << stack.numbers[stack.count] << endl;
  stack.count++;


  

}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  if (stack.count == 0) {
    return INT32_MAX;
  }

  int* numbers = new int[stack.capacity - 1];
  for (int i = 0; i < stack.capacity - 1; i++) {
      numbers[i] = stack.numbers[i];
  }
  int value = stack.numbers[stack.count - 1];
  delete[] stack.numbers;
  stack.numbers = numbers;
  stack.count--;
  //cout << value << endl;
  return value;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack
  return stack.numbers[stack.count - 1];
}

void printStack(Stack& stack) 
{
  cout << "STACK: ";
  for (int i = 0; i < stack.count; i++)
  {
    cout << stack.numbers[i] << ",";
  }
  cout << endl << endl;
}
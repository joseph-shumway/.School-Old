#include <iostream>

#include <string>

#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int
digit_to_decimal(char digit)
{
  // TODO(student): implement

  switch (digit)
  {
  case '0':
    return 0;
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  default:
    throw std::invalid_argument("Input is not an integer");
  }

  return 0;
}

char decimal_to_digit(unsigned int decimal)
{
  // TODO(student): implement

  switch (decimal)
  {
  case 0:
    return '0';
  case 1:
    return '1';
  case 2:
    return '2';
  case 3:
    return '3';
  case 4:
    return '4';
  case 5:
    return '5';
  case 6:
    return '6';
  case 7:
    return '7';
  case 8:
    return '8';
  case 9:
    return '9';
  default:
    throw std::invalid_argument("Input is not an integer");
  }

  return '\0';
}

string trim_leading_zeros(string num)
{
  // TODO(student): implement

  if (num.at(0) == '-')
  {
    for (unsigned int i = 1; i < num.size(); i++)
    {

      if (num.at(i) != '0')
      {
        break;
      }
      else
      {
        if (i == (num.size() - 1))
        {
          return "0";
        }
      }
    }

    while (num.at(1) == '0')
    {
      num.erase(1, 1);
    }
  }
  else
  {
    for (unsigned int i = 0; i < num.size(); i++)
    {
      if (num.at(i) != '0')
      {
        break;
      }
      else
      {
        if (i == (num.size() - 1))
        {
          return "0";
        }
      }
    }

    while (num.at(0) == '0')
    {
      num.erase(0, 1);
    }
  }

  return num;
}

string add(string lhs, string rhs)
{
  // TODO(student): implement

  lhs = trim_leading_zeros(lhs);
  rhs = trim_leading_zeros(rhs);

  bool negativeLHS = false;
  bool negativeRHS = false;

  //cout << "adding " << lhs << " to " << rhs << endl;

  if (lhs.at(0) == '-')
  {
    negativeLHS = true;
    cout << "Negative" << endl;
  }

  if (rhs.at(0) == '-')
  {
    negativeRHS = true;
    cout << "Negative" << endl;
  }

  int current = 0;
  int carry = 0;
  string result = "";
  string rev = "";

  //add zeros to smaller digit number to prepare for adding
  if (lhs.size() < rhs.size())
  {
    //cout << "LHS: " << lhs << endl;

    string temp = "";

    for (unsigned int i = 0; i < rhs.size() - lhs.size(); i++)
    {
      temp.append("0");
    }
    temp.append(lhs);
    lhs = temp;

    //cout << "LHS: " << lhs << endl;
  }

  if (lhs.size() > rhs.size())
  {
    //cout << "RHS: " << rhs << endl;

    string temp = "";
    for (unsigned int i = 0; i < lhs.size() - rhs.size(); i++)
    {
      temp.append("0");
    }
    temp.append(rhs);
    rhs = temp;

    //cout << "RHS: " << rhs << endl;
  }

  if (!negativeLHS && negativeRHS)
  {

    for (int i = lhs.size() - 1; i > 0; i--)
    {
      current = (lhs.at(i) - 48) - (rhs.at(i) - 48) + carry;
      //cout << current << " ";

      if (current < 10)
      {
        result.append(std::to_string(current));
        carry = 0;
      }
      else
      {
        result.append(std::to_string(current % 10));
        carry = 1;
      }
    }

    if (carry == 1)
    {
      result.append(std::to_string(1));
      carry = 0;
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
      rev = rev.append(1, result.at(i));
    }
  }

  else
  {
    for (int i = lhs.size() - 1; i >= 0; i--)
    {
      current = (lhs.at(i) - 48) + (rhs.at(i) - 48) + carry;
      //cout << current << " ";

      if (current < 10)
      {
        result.append(std::to_string(current));
        carry = 0;
      }
      else
      {
        result.append(std::to_string(current % 10));
        carry = 1;
      }
    }

    if (carry == 1)
    {
      result.append(std::to_string(1));
      carry = 0;
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
      rev = rev.append(1, result.at(i));
    }
  }

  //cout << "\n" << "result: " << rev << "\n\n";

  return rev;
}

string multiply(string lhs, string rhs)
{
  int lhs_start = 0;
  int rhs_start = 0;

  if (lhs.at(0) == '-') {
    lhs_start = 1;
  }

  if (rhs.at(0) == '-') {
    rhs_start = 1;
  }

  


  //cout << lhs << " x " << rhs << endl << endl;
  /*
  // TODO(student): implement
  string swap = "";
  if (lhs.size() < rhs.size()) {
    swap = lhs;
    lhs = rhs;
    rhs = swap;
  }
  */

  int currentLHS = 0;
  int currentRHS = 0;
  int carry = 0;
  int temp = 0;
  int temp_1 = 0;
  string rev_temp = "";
  string rev2 = "";
  string result1 = "";
  string result2 = "0";
  string rev = "";
  int counter = 0;

  for (int i = rhs.size() - 1; i >= rhs_start; i--)
  {
    counter = 0;

    for (int j = lhs.size() - 1; j >= lhs_start; j--)
    {
      counter++;
      currentLHS = lhs.at(j) - 48;
      currentRHS = rhs.at(i) - 48;
      
      //cout << "currentLHS: " << currentLHS << endl;
      //cout << "currentRHS: " << currentRHS << endl;
      //cout << "temp: " << currentLHS * currentRHS << endl;
      //cout << "carry: " << carry << "              j=" << j << "        counter=" << counter << endl;
      //temp.append(std::to_string(currentLHS));
      

      //get the multiplication of the digits at i and j
      temp = (currentLHS * currentRHS) + carry; //25
      temp_1 = (temp % 10);                     //5
      
      carry = (temp / 10);                      //2
      
      
      //cout << carry << temp_1 << endl << endl;
      temp = temp_1;

      
      if (temp > 9) {
        
        //cout << endl << "temp: " << temp << endl;
        //cout << "UPGRADE CARRY" << endl;
        carry = (temp / 10) + carry;
        temp = temp % 10;
        //cout << "Next carry: " << carry << endl;
      } else {
        //cout << "Next carry: " << carry << endl;
      }
      

      
      //append the reversed temp variable
      result1.append(std::to_string(temp));

      if (j == lhs_start && carry != 0) {
        //cout << "Final carry: " << carry << endl;
        result1.append(std::to_string(carry));
      }
      //cout << "result1: " << result1 << endl << endl;
      


      /*
      //if its the last digit in the lhs, append the carry
      if (i == 0 && carry > 0)
      {
        result1.append(std::to_string(carry));
        cout << "result1 after carry: " << result1 << endl << endl;
      }
      */
     
    }

    

    carry = 0;

    //if its the second time running or more, add a 0 for each time (adding 0s each iteration)
    if (((unsigned) i < (rhs.size()) - 1))
    {
      for (unsigned int k = 0; k < rhs.size() - 1 - i; k++)
      {
        result1.insert(0, "0");
      }
    }

    //reverse the final result
    for (int m = result1.size() - 1; m >= 0; m--)
    {
      rev = rev.append(1, result1.at(m));
    }

    result1 = rev;

    //cout << "result1: " << result1 << endl;
    //cout << "result2: " << result2 << endl << endl << endl;

    //cout << "------------------------" << endl;

    //add this result to the final result
    
    
    result2 = add(result1, result2);
    result1 = "";
    rev = "";
  }


  if (lhs_start != rhs_start) {
    result2.insert(0, "-");
  }

  return result2;
}
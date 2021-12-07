#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    

    string num1 = "";
    string oper = "";
    string num2 = "";

    //cout << "\n\n";

    // cout << multiply("6", "7") << endl;
    // cout << multiply("4", "2") << endl;
    // cout << multiply("18", "51") << endl;
    // cout << multiply("2", "73") << endl;
    // cout << multiply("15", "29") << endl;
    // cout << multiply("-175", "170") << endl;

    // cout << "\n\n";
    

    
    while ((num1 != "q" || num1 != "quit" ) && !cin.eof())
    {
        cout << ">> ";
        cin >> num1;
        if (num1 == "q" || num1 == "quit") {
            cout <<endl << "farvel!" << endl << endl;
            break;
        }
        cin >> oper;
        cin >> num2;

        cout << endl;
        

        if (oper == "+")
        {
            string result = add(num1, num2);
            cout << "ans =\n\n    " << result << endl  << endl;
        }

        if (oper == "*")
        {
            string result = multiply(num1, num2);
            cout << "ans =\n\n    " << result << endl  << endl;
        }
    }
    

    // TODO(student): implement the UI
    //cout << trim_leading_zeros("-00123") << endl;
    //cout << trim_leading_zeros("-00000") << endl;
    //cout << trim_leading_zeros("-500") << endl;
}

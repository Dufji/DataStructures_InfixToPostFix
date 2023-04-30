// Programming_Exercise_17_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include <vector>
#include "infixToPostFix.h"


using namespace std;

int main()
{
    vector<string> infixList;
    infixList.push_back("A + B - C");
    infixList.push_back("(A + B) * C");
    infixList.push_back("(A + B) * (C - D)");
    infixList.push_back("A + ((B + C) * (E - F) - G) / (H - I)");
    infixList.push_back("A + B * (C + D) - E / F * G + H");

    for (string infx : infixList) {
        infixToPostfix expression(infx);
        expression.showInfix();
        expression.showPostfix();
        cout << endl;
    }






    return 0;
}

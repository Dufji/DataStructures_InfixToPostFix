// Header file: infixToPostFix.h
#ifndef H_infixToPostFix
#define H_infixToPostFix

#include "myStack.h"

class infixToPostfix
{
public:

    infixToPostfix();
    ~infixToPostfix();
    infixToPostfix(const string& infix);

    void getInfix(std::string input);

    string getInfx() const;
    string getPfx() const;

    void showInfix() const;
    void showPostfix() const;

    bool isOperator(char c);

    bool precedence(char op1, char op2);

    void convertToPostfix();

private:

    stackType<char> stack;

    std::string infx;
    std::string pfx;

};

infixToPostfix::~infixToPostfix() {
    // Destructor
}

infixToPostfix::infixToPostfix() {
    this->infx = "";
}

infixToPostfix::infixToPostfix(const string& infix) {
    this->infx = infix;
    convertToPostfix();
}


bool infixToPostfix::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
} // end isOperator


bool infixToPostfix::precedence(char op1, char op2) {
    int prec1, prec2;

    // Assigning precedence value to operator 1
    if (op1 == '+' || op1 == '-')
        prec1 = 1;
    else if (op1 == '*' || op1 == '/')
        prec1 = 2;
    else
        prec1 = 0;

    // Assigning precedence value to operator 2
    if (op2 == '+' || op2 == '-')
        prec2 = 1;
    else if (op2 == '*' || op2 == '/')
        prec2 = 2;
    else
        prec2 = 0;

    return prec1 >= prec2;
}

void infixToPostfix::getInfix(std::string input)
{
    this->infx = input;
    convertToPostfix();
} // end getInfix




// Getters
string infixToPostfix::getPfx() const {
    return this->pfx;
} // end getPfx

string infixToPostfix::getInfx() const {
    return this->infx;
}
// end getters



// Print Functions
void infixToPostfix::showInfix() const {
    std::cout << "Infix: " << this->infx << std::endl;
} // end showInfix

void infixToPostfix::showPostfix() const {
    std::cout << "Postfix: " << this->pfx << std::endl;
} // end showPostFix
// End print functions



// Main function for converting the infix to post fix
void infixToPostfix::convertToPostfix() {
    stackType<char> stack;

    for (int i = 0; i < this->infx.length(); i++) {
        char sym = this->infx[i];

        if (isalnum(sym)) {
            this->pfx += sym;
        }
        else if (isOperator(sym)) {
            while (!stack.isEmptyStack() && precedence(stack.top(), sym))
            {
                this->pfx += stack.top();
                stack.pop();
            }
            stack.push(sym);
        }
        else if (sym == '(') {
            stack.push(sym);
        }
        else if (sym == ')') {
            while (!stack.isEmptyStack() && stack.top() != '(') {
                this->pfx += stack.top();
                stack.pop();
            }
            stack.pop();
        }
    }

    while (!stack.isEmptyStack()) {
        this->pfx += stack.top();
        stack.pop();
    }
} // end convertToPostFix


#endif

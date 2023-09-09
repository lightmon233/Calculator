//
// Created by 35358 on 2023/9/9.
//

#ifndef CALCULATOR_BASEEXPRESSION_H
#define CALCULATOR_BASEEXPRESSION_H

#endif //CALCULATOR_BASEEXPRESSION_H

#include <iostream>
#include "Digit.h"
#include <stack>
#include <unordered_map>

using namespace std;

class BaseExpression {
protected:
    string s;
    stack<Digit> num;
    stack<char> op;
    unordered_map<char, int> priority {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
    };
public:
    BaseExpression(string s);
    void eval();
    virtual Digit calc(ifstream &ifs, ofstream &ofs) = 0;
};
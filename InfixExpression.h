//
// Created by 35358 on 2023/9/9.
//

#ifndef CALCULATOR_INFIXEXPRESSION_H
#define CALCULATOR_INFIXEXPRESSION_H

#include "BaseExpression.h"

using namespace std;

class InfixExpression : public BaseExpression {
public:
    InfixExpression(string s);
    void repair();
    Digit calc(ifstream &ifs, ofstream &ofs) override;
};

#endif //CALCULATOR_INFIXEXPRESSION_H

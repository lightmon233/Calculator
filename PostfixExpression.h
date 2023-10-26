//
// Created by 35358 on 2023/9/10.
//

#ifndef CALCULATOR_POSTFIXEXPRESSION_H
#define CALCULATOR_POSTFIXEXPRESSION_H

#include "BaseExpression.h"

class PostfixExpression : public BaseExpression {
public:
    PostfixExpression(string s);
    void repair();
    Digit calc(ifstream &ifs, ofstream &ofs) override;
};

#endif //CALCULATOR_POSTFIXEXPRESSION_H

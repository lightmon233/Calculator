//
// Created by 35358 on 2023/9/12.
//

#ifndef CALCULATOR_PREFIXEXPRESSION_H
#define CALCULATOR_PREFIXEXPRESSION_H

#include "BaseExpression.h"

class PrefixExpression : public BaseExpression {
public:
    PrefixExpression(string s);
    void repair();
    Digit calc(ifstream &ifs, ofstream &ofs) override;
    void eval() override;
};

#endif //CALCULATOR_PREFIXEXPRESSION_H


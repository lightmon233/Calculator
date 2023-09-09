//
// Created by 35358 on 2023/9/9.
//

#include "BaseExpression.h"

using namespace std;

BaseExpression::BaseExpression(string s) {
    this->s = s;
}

void BaseExpression::eval() {
    auto a = num.top();
    num.pop();
    auto b = num.top();
    num.pop();
    char p = op.top();
    op.pop();
    if (p == '+') {
        auto r = b + a;
        num.push(r);
    }
    else if (p == '-') {
        auto r = b - a;
        num.push(r);
    }
    else if (p == '*') {
        auto r = b * a;
        num.push(r);
    }
    else {
        auto r = b / a;
        num.push(r);
    }
}


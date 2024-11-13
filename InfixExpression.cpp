//
// Created by 35358 on 2023/9/9.
//

#include "InfixExpression.h"

InfixExpression::InfixExpression(string s) : BaseExpression(s){
    ;
}

void InfixExpression::repair() {
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '-' && (i == 0 || s[i - 1] == '(')) {
            s.insert(i, 1, '0');
        }
    }
}

Digit InfixExpression::calc(ifstream &ifs, ofstream &ofs) {
    repair();
    int s_len = s.size();
    int i = 0;
    while (i < s_len) {
        string tmp;
        while (isdigit(s[i]) && i < s_len) {
            tmp += s[i];
            i ++;
        }
        if (!tmp.empty()) {
            // cout << tmp << endl;
            i -= 1;
            num.push(Digit(tmp));
        }
        else if (s[i] == '(') {
            op.push(s[i]);
        }
        else if (s[i] == ')') {
            while (op.top() != '(') eval();
            op.pop();
        }
        else {
            while (!op.empty() && priority[op.top()] >= priority[s[i]])
                eval();
            op.push(s[i]);
        }
        i ++;
    }
    while (!op.empty()) eval();
    return num.top();
}
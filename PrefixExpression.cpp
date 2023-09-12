//
// Created by 35358 on 2023/9/12.
//

#include <algorithm>
#include "PrefixExpression.h"

PrefixExpression::PrefixExpression(string s) : BaseExpression(s){
    ;
}

void PrefixExpression::repair() {
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '-' && (i < s.length() - 1 || isdigit(s[i + 1]))) {
            string tmp;
            int j = i + 1;
            while (isdigit(s[j]) && j < s.length()) {
                tmp += s[j];
                j ++;
            }
            cout << tmp << endl;
            s.replace(i, j - i, "- 0 " + tmp);
            i = j + 2;
        }
    }
}

Digit PrefixExpression::calc(std::ifstream &ifs, std::ofstream &ofs) {
    repair();
    cout << s << endl;
    int s_len = s.size();
    int i = s_len - 1;
    while (i >= 0) {
        string tmp;
        while (isdigit(s[i]) && i >= 0) {
            tmp += s[i];
            i --;
        }
        if (!tmp.empty()) {
            reverse(tmp.begin(), tmp.end());
            // cout << tmp << endl;
            i += 1;
            num.push(Digit(tmp));
        }
        else if (s[i] != ' '){
            op.push(s[i]);
            eval();
        }
        i --;
    }
    return num.top();
}

void PrefixExpression::eval() {
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
        auto r = a - b;
        num.push(r);
    }
    else if (p == '*') {
        auto r = b * a;
        num.push(r);
    }
    else if (p == '/'){
        auto r = a / b;
        num.push(r);
    }
    else {
        auto r = a % b;
        num.push(r);
    }
}
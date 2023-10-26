//
// Created by 35358 on 2023/9/10.
//

#include "PostfixExpression.h"

PostfixExpression::PostfixExpression(string s) : BaseExpression(s){
    ;
}

void PostfixExpression::repair() {
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '-' && (i < s.length() - 1 || isdigit(s[i + 1]))) {
            string tmp;
            int j = i + 1;
            while (isdigit(s[j]) && j < s.length()) {
                tmp += s[j];
                j ++;
            }
            // cout << tmp << endl;
            s.replace(i, j - i, "0 " + tmp + " -");
            i = j + 2;
        }
    }
}

Digit PostfixExpression::calc(std::ifstream &ifs, std::ofstream &ofs) {
    repair();
    cout << s << endl;
    int s_len = s.size();
    int i = 0;
    while (i < s_len) {
        string tmp;
        while (isdigit(s[i]) && i < s_len) {
            tmp += s[i];
            i ++;
        }
        if (!tmp.empty()) {
            //cout << tmp << endl;
            i -= 1;
            num.push(Digit(tmp));
        }
        else if (s[i] != ' '){
            op.push(s[i]);
            eval();
        }
        i ++;
    }
    return num.top();
}
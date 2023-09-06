#include <iostream>
#include <stack>
#include <unordered_map>
#include "Digit.h"
#include <fstream>

using namespace std;

void repair(string &s) {
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '-' && (i == 0 || s[i - 1] == '(')) {
            s.insert(i, 1, '0');
        }
    }
}

void eval(stack<Digit> &num, stack<char> &op) {
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

int main() {
    stack<Digit> num;
    stack<char> op;
    unordered_map<char, int> priority {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
    };
    ifstream ifs;
    ifs.open("../input.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "failed to open input.txt." << endl;
        exit(1);
    }
    ofstream ofs;
    ofs.open("../output.txt", ios::out);
    if (!ofs.is_open()) {
        cout << "failed to open output.txt" << endl;
        exit(1);
    }
    string s;
    // printf("Please enter the expression:\n");
    ifs >> s;
    repair(s);
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
            while (op.top() != '(') eval(num, op);
            op.pop();
        }
        else {
            while (!op.empty() && priority[op.top()] >= priority[s[i]])
                eval(num, op);
            op.push(s[i]);
        }
        i ++;
    }
    while (!op.empty()) eval(num, op);
    num.top().show(ofs);
    ifs.close();
    ofs.close();
    cout << "Answer successfully generated." << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include "InfixExpression.h"

using namespace std;

int main() {
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
    while (ifs >> s) {
        InfixExpression expression(s);
        Digit ans = expression.calc(ifs, ofs);
        ans.show(ofs);
    }
    ifs.close();
    ofs.close();
    cout << "Answer successfully generated." << endl;
    return 0;
}
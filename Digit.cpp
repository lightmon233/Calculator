//
// Created by 35358 on 2023/9/5.
//
#include "Digit.h"

using namespace std;

Digit::Digit(string s) {
    digits = s.size();
    p = new int[digits + 2]();
    for (int i = 1; i <= s.size(); i ++) {
        p[i] = s[s.size() - i] - '0';
    }
}

Digit::Digit(int max_digits) {
    digits = max_digits;
    p = new int[max_digits + 2]();
}

Digit::Digit(const Digit &b) {
    digits = b.digits;
    p = new int[b.digits + 2]();
    for (int i = 1; i <= digits; i ++) {
        p[i] = b.p[i];
    }
}

Digit::~Digit() {
    delete p;
}

bool comparePostive(const Digit &a, const Digit &b) {
    if (a.digits != b.digits) return a.digits > b.digits;
    for (int i = 1; i < a.digits; i ++) {
        if (a.p[i] != b.p[i]) return a.p[i] > b.p[i];
    }
    return true;
}

Digit addPostive(const Digit &a, const Digit &b) {
    Digit res(max(a.digits, b.digits) + 1);
    for (int i = 1; i <= res.digits; i ++) {
        res.p[i] += a.p[i] + b.p[i];
        res.p[i + 1] = res.p[i] / 10;
        res.p[i] = res.p[i] % 10;
    }
    if (res.p[res.digits] == 0 && res.digits > 0) res.digits --;
    return res;
}

void swapDigit(Digit &a, Digit &b) {
    Digit tmp(b);
    b.p = a.p, b.digits = a.digits;
    a.p = tmp.p, a.digits = tmp.digits;
}

Digit minusPostive(const Digit &a, const Digit &b) {
    Digit aa(a), bb(b);
    if (!comparePostive(aa, bb)) {
        swapDigit(aa, bb);
    }
    Digit res(max(aa.digits, bb.digits));
    for (int i = 1; i <= res.digits; i ++) {
        if (aa.p[i] < bb.p[i]) {
            aa.p[i + 1] --;
            aa.p[i] += 10;
        }
        res.p[i] = aa.p[i] - bb.p[i];
    }
    while (res.p[res.digits] == 0 && res.digits > 1) res.digits --;
    return res;
}

Digit operator+(const Digit& a, const Digit& b) {
    if (a.p[0] ^ b.p[0]) {
        Digit res = minusPostive(a, b);
        res.p[0] = 1;
        return res;
    }
    else if (a.p[0] == 0) return addPostive(a, b);
    else {
        Digit res = addPostive(a, b);
        res.p[0] = 1;
    }
}

Digit operator-(const Digit& a, const Digit& b) {
    if (a.p[0] == 0 && b.p[0] == 0) {
        Digit res = minusPostive(a, b);
        if (comparePostive(a, b)) return res;
        else {
            res.p[0] = 1;
            return res;
        }
    }
    else if (a.p[0] == 1 && b.p[0] == 1) {
        Digit res = minusPostive(a, b);
        if (comparePostive(a, b)) {
            res.p[0] = 1;
            return res;
        }
        else return res;
    }
    else if (a.p[0] == 0 && b.p[0] == 1) {
        return minusPostive(a, b);
    }
    else {
        Digit res = minusPostive(a, b);
        res.p[0] = 1;
        return res;
    }
}

Digit operator*(const Digit& a, const Digit& b) {

}

Digit operator/(const Digit& a, const Digit& b) {

}

void Digit::show() {
    if (p[0] == 1) printf("-1");
    for (int i = digits; i >= 1; i --) {
        printf("%d", p[i]);
    }
    puts("");
}
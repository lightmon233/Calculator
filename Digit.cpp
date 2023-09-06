//
// Created by 35358 on 2023/9/5.
//
#include "Digit.h"
#include <iostream>

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
    p = new int[digits + 2]();
    for (int i = 0; i <= digits; i ++) {
        p[i] = b.p[i];
    }
}

void Digit::setDigits(int n) {
    if (n < digits) {
        int *newp = new int[n + 2]();
        delete[] p;
        p = newp;
        digits = n;
    }
    else if (n == digits) return;
    int *newp = new int[n + 2]();
    for (int i = 0; i <= digits; i ++) {
        newp[i] = p[i];
    }
    delete[] p;
    p = newp;
    digits = n;
}

void Digit::leftShift(int n) {
    int pre_digits = digits;
    setDigits(pre_digits + n);
    for (int i = pre_digits; i >= 1; i --) {
        p[i + n] = p[i];
    }
    for (int i = 1; i <= n; i ++) p[i] = 0;
}

Digit& Digit::operator=(const Digit &b) {
    if (this == &b) return *this;
    else {
        setDigits(b.digits);
        for (int i = 0; i <= b.digits; i ++) {
            p[i] = b.p[i];
        }
        return *this;
    }
}

Digit::~Digit() {
    delete[] p;
}

int comparePostive(Digit &a, Digit &b) {
    if (a.digits != b.digits) return a.digits > b.digits ? 1 : -1;
    for (int i = a.digits; i >= 1; i --) {
        if (a.p[i] != b.p[i]) return a.p[i] > b.p[i] ? 1 : -1;
    }
    return 0;
}

Digit addPostive(Digit &a, Digit &b) {
    Digit res(max(a.digits, b.digits) + 1);
    a.setDigits(res.digits + 1), b.setDigits(res.digits + 1);
    for (int i = 1; i < res.digits; i ++) {
        res.p[i] += a.p[i] + b.p[i];
        res.p[i + 1] = res.p[i] / 10;
        res.p[i] = res.p[i] % 10;
    }
    while (res.p[res.digits] == 0 && res.digits > 1) res.digits --;
    return res;
}

void swapDigit(Digit &a, Digit &b) {
    int *bp = b.p, bdigits = b.digits;
    b.p = a.p, b.digits = a.digits;
    a.p = bp, a.digits = bdigits;
}

Digit minusPostive(Digit &a, Digit &b) {
    Digit aa(a), bb(b);
    if (comparePostive(aa, bb) == -1) {
        swapDigit(aa, bb);
    }
    Digit res(max(aa.digits, bb.digits));
    aa.setDigits(res.digits), bb.setDigits(res.digits);
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

Digit operator+(Digit& a, Digit& b) {
    if (a.p[0] == 0 && b.p[0] == 0) {
        return addPostive(a, b);
    }
    else if (a.p[0] == 1 && b.p[0] == 1) {
        Digit res = addPostive(a, b);
        res.p[0] = 1;
        return res;
    }
    else if (a.p[0] == 0 && b.p[0] == 1) {
        if (comparePostive(a, b) != -1) {
            return minusPostive(a, b);
        }
        else {
            Digit res = minusPostive(a, b);
            res.p[0] = 1;
            return res;
        }
    }
    else {
        if (comparePostive(a, b) != 1) {
            return minusPostive(a, b);
        }
        else {
            Digit res = minusPostive(a, b);
            res.p[0] = 1;
            return res;
        }
    }
}

Digit operator-(Digit& a, Digit& b) {
    if (a.p[0] == 0 && b.p[0] == 0) {
        Digit res = minusPostive(a, b);
        if (comparePostive(a, b) != -1) return res;
        else {
            res.p[0] = 1;
            return res;
        }
    }
    else if (a.p[0] == 1 && b.p[0] == 1) {
        Digit res = minusPostive(a, b);
        if (comparePostive(a, b) == 1) {
            res.p[0] = 1;
            return res;
        }
        else return res;
    }
    else if (a.p[0] == 0 && b.p[0] == 1) {
        return addPostive(a, b);
    }
    else {
        Digit res = addPostive(a, b);
        res.p[0] = 1;
        return res;
    }
}

Digit operator*(Digit& a, Digit& b) {
    Digit res(a.digits + b.digits);
    for (int i = 1; i <= a.digits; i ++) {
        for (int j = 1; j <= b.digits; j ++) {
            res.p[i + j - 1] += a.p[i] * b.p[j];
            res.p[i + j] += res.p[i + j - 1] / 10;
            res.p[i + j - 1] %= 10;
        }
    }
    while (res.p[res.digits] == 0 && res.digits > 1) res.digits --;
    if (a.p[0] ^ b.p[0]) res.p[0] = 1;
    return res;
}

Digit operator/(Digit& a, Digit& b) {
    if (b.p[b.digits] == 0) {
        puts("illegal arguments at the call of function 'operator/'!");
        exit(1);
    }
    else if (a.digits - b.digits + 1 <= 0) {
        Digit res("0");
        return res;
    }
    else {
        Digit res(a.digits - b.digits + 1);
        Digit aa(a);
        for (int i = res.digits; i >= 1; i --) {
            Digit tmp(b);
            tmp.leftShift(i - 1);
            while (comparePostive(aa, tmp) >= 0) {
                res.p[i] ++;
                aa = minusPostive(aa, tmp);
            }
        }
        while (res.p[res.digits] == 0 && res.digits > 1) res.digits --;
        if (a.p[0] ^ b.p[0]) res.p[0] = 1;
        return res;
    }
}

void Digit::show(ostream& out) {
    // printf("Here's the answer, master:\n");
    if (p[0] == 1) out << '-';
    for (int i = digits; i >= 1; i --) {
        out << p[i];
    }
    out << endl;
}
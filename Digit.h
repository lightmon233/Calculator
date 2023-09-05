//
// Created by 35358 on 2023/9/5.
//

#ifndef CALCULATOR_DIGIT_H
#define CALCULATOR_DIGIT_H

#endif //CALCULATOR_DIGIT_H

#include <string>

using namespace std;

class Digit {
private:
    int *p;
    int digits;
public:
    Digit(string s);
    Digit(const Digit& b);
    explicit Digit(int max_digits);
    ~Digit();
    friend void swapDigit(Digit &a, Digit& b);
    friend bool comparePostive(const Digit& a, const Digit& b);
    friend Digit addPostive(const Digit& a, const Digit& b);
    friend Digit minusPostive(const Digit& a, const Digit& b);
    friend Digit operator+(const Digit& a, const Digit& b);
    friend Digit operator-(const Digit& a, const Digit& b);
    friend Digit operator*(const Digit& a, const Digit& b);
    friend Digit operator/(const Digit& a, const Digit& b);
    void show();
};
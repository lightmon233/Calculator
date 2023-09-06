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
    void setDigits(int n);
    void leftShift(int n);
    ~Digit();
    friend void swapDigit(Digit &a, Digit& b);
    friend int comparePostive(Digit& a, Digit& b);
    friend Digit addPostive(Digit& a, Digit& b);
    friend Digit minusPostive(Digit& a, Digit& b);
    friend Digit operator+(Digit& a, Digit& b);
    friend Digit operator-(Digit& a, Digit& b);
    friend Digit operator*(Digit& a, Digit& b);
    friend Digit operator/(Digit& a, Digit& b);
    Digit& operator=(const Digit& b);
    void show();
};
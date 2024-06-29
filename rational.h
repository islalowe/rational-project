//
// Created by Isla Lowe on 6/29/24.
//

#ifndef RATIONAL_PROJECT_RATIONAL_H
#define RATIONAL_PROJECT_RATIONAL_H



#include "string"
#include "set"
#include<cmath>
#include<iostream>
using std::string;
using std::ostream;

class Rational {
    int _numerator, _denominator;
public:
    //Constructors
    Rational(int numerator, int denominator);
    Rational(double number);

    //-Rational
    Rational operator-() const;

    //Rational += Rational
    const Rational &operator+=(const Rational &rhs);

    //Rational -= Rational
    const Rational &operator-=(const Rational &rhs);

    //Rational *= Rational
    const Rational &operator*=(const Rational &rhs);

    //Rational /= Rational
    const Rational &operator/=(const Rational &rhs);

    //Rational = Rational
    const Rational &operator=(const Rational &rhs);

    //Rational == Rational
    bool operator==(const Rational& rhs) const;

    //Rational != Rational
    bool operator!=(const Rational &rhs) const;

    //Rational > Rational
    bool operator>(const Rational &rhs) const;

    //Rational >= Rational
    bool operator>=(const Rational &rhs) const;

    //Rational <= Rational
    bool operator<=(const Rational &rhs) const;

    //Rational < Rational
    bool operator<(const Rational &rhs) const;

    //formatting methods
    string ToString() const;
    double ToDouble() const;

    //friends - require two operators
    friend Rational operator+(const Rational &lhs, const Rational &rhs);    //Rational + Rational
    friend Rational operator-(const Rational &lhs, const Rational &rhs);    //Rational - Rational
    friend Rational operator*(const Rational &lhs, const Rational &rhs);    //Rational * Rational
    friend Rational operator/(const Rational &lhs, const Rational &rhs);    //Rational / Rational
    friend ostream& operator<<(ostream& output, const Rational& rational);  //stream insertion operator
    //>>>>>> REMEMBER THE NUMBER IS ALWAYS SIMPLIFIED <<<<<<<
    void Simplify();
};

//Helper function GCD
int FindGCD(int lhs, int rhs);



#endif //RATIONAL_PROJECT_RATIONAL_H

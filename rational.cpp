//
// Created by Isla Lowe on 6/29/24.
//

#include "rational.h"

/**
 * Constructor. Initializes data members.
 * @param: numerator: the value for _numerator
 * @param: denominator: the value for _denominator
 */
Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        std::cerr << "Denominator cannot be zero" << std::endl;
    }
    _numerator = numerator;
    _denominator = denominator;
    Simplify();
}

/**
 * Constructor. Converts the double number to a rational number
 * @param: number: the number that will be converted to a rational number.
 */
Rational::Rational(double number) {
    // Step 1: Identify the double - convert the double to a string
    string doubleVal = std::to_string(number);
    // Step 2: Determine the place value of the last digit
    int decimalIndex = doubleVal.find(".");
    int tensPwr = doubleVal.length() - decimalIndex - 1;
    // Step 3: Calculate the numerator and denominator
    _numerator = static_cast<int>(number * std::pow(10, tensPwr));
    _denominator = static_cast<int>(std::pow(10, tensPwr));
    // Step 4: Simplify using GCD
    int GCD = FindGCD(_numerator, _denominator);
    _numerator /= GCD;
    _denominator /= GCD;
}

/**
 * Returns a rational number that is the negative of the current object
 */
Rational Rational::operator-() const {
    return Rational(-_numerator, _denominator);
}

/**
 * Returns a rational number that is the sum of the current object and rhs
 * @param: rhs: the number that will be added tot he current object.
 */
const Rational &Rational::operator+=(const Rational &rhs) {
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    Simplify();
    return *this;
}

/**
 * Returns a rational number that is the difference of the parameter and the current object
 * @param: number: the value subtracted from the current object
 */
const Rational &Rational::operator-=(const Rational &rhs) {
    //calculate the common denominator
    int commonDenominator = _denominator * rhs._denominator;
    //adjust the numerators to have the same denominator before subtraction
    int newNumerator1 = _numerator * rhs._denominator;
    int newNumerator2 = rhs._numerator * _denominator;
    //subtract the adjusted numerators
    int newNumerator = newNumerator1 - newNumerator2;
    _numerator = newNumerator;
    _denominator = commonDenominator;
    Simplify();
    return *this;
}

/**
 * Returns a rational number that is the product of the parameter and the current object
 * @param: number: the value multiplied to the current object
 */
const Rational& Rational::operator*=(const Rational& rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    Simplify();
    return *this;
}

/**
 * Returns a rational number that is the quotient of the parameter and the current object
 * @param: number: the value divided from the current object
 */
const Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs._numerator == 0) {
        throw std::invalid_argument("Cannot divide by a rational number with zero numerator");
    }
    _numerator *= rhs._denominator;
    _denominator *= rhs._numerator;
    Simplify();
    return *this;
}

/**
 * Returns a rational number that is equal to the current object
 * But this is not a copy constructor
 * @param: rhs: the Rational whose values are assigned to the current object
 */
const Rational &Rational::operator=(const Rational &rhs) {
    if (this != &rhs) {
        _numerator = rhs._numerator;
        _denominator = rhs._denominator;
    }
    return *this;
}

/**
 * Returns true if the current object is equal to the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator==(const Rational& rhs) const {
    return (_numerator == rhs._numerator && _denominator == rhs._denominator);
}

/**
 * Returns true if the current object is not equal to the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator!=(const Rational& rhs) const {
    return !(*this == rhs);
}

/**
 * Returns true if the current object is greater than the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator>(const Rational &rhs) const {
    //multiply to make one comparable value
    //rather than comparing _numerator and _denominator separately
    return (_numerator * rhs._denominator > rhs._numerator * _denominator);
}

/**
 * Returns true if the current object is greater than or equal to the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator>=(const Rational &rhs) const {
    //multiply to make one comparable value
    //rather than comparing _numerator and _denominator separately
    return (_numerator * rhs._denominator >= rhs._numerator * _denominator);
}

/**
 * Returns true if the current object is less than or equal to the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator<=(const Rational &rhs) const {
    //multiply to make one comparable value
    //rather than comparing _numerator and _denominator separately
    return (_numerator * rhs._denominator <= rhs._numerator * _denominator);
}

/**
 * Returns true if the current object is less than the parameter and false otherwise
 * @param: rhs: the Rational whose values are compared to the current object
 */
bool Rational::operator<(const Rational &rhs) const{
    //multiply to make one comparable value
    //rather than comparing _numerator and _denominator separately
    return (_numerator * rhs._denominator < rhs._numerator * _denominator);
}

/**
 * Returns a string representation of the Rational number
 */
string Rational::ToString() const{
    if (_numerator == _denominator) {
        return "1";
    }
    string returnVal = std::to_string(_numerator);
    //whole numbers are output without denominators
    if (_denominator != 1) {
        returnVal = returnVal + "/" + std::to_string(_denominator);
    }
    return returnVal;
}

/**
 * Returns the value of the rational number converted to a decimal
 */
double Rational::ToDouble() const{
    return static_cast<double>(_numerator) / _denominator;
}

/**
 * Returns a sum number that is the product of lhs and rhs
 * @param: lhs: one of the values added
 * @param: rhs: one of the values added
 */
Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational result(lhs);
    result += rhs;
    return result;
}

/**
 * Returns a rational number that is the difference of lhs and rhs
 * @param: lhs: the value rhs is subtracted from
 * @param: rhs: the value subtracted from lhs
 */
Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational result(lhs);
    result -= rhs;
    return result;
}

/**
 * Returns a rational number that is the product of lhs and rhs
 * @param: lhs: one of the values multiplied
 * @param: rhs: one of the values multiplied
 */
Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational result(lhs);
    result *= rhs;
    return result;
}

/**
 * Returns a rational number that is the quotient of lhs and rhs
 * @param: lhs: the value divided by rhs
 * @param: rhs: the value lhs is divided by
 */
Rational operator/(const Rational &lhs, const Rational &rhs) {
    Rational result(lhs);
    result /= rhs;
    return result;
}

/**
 * Sends a rational number to the specified output stream
 * @param: output: the output stream the rational number will be sent to
 * @param: rational: the rational number to be output
 */
ostream& operator<<(ostream& output, const Rational& rational) {
    output << rational.ToString();
    return output;
}

/**
 * Returns the simplified version of the current rational number
 */
void Rational::Simplify() {
    if (_denominator == 0) {
        return;
    }
    if (_denominator < 0) {
        // Adjust the sign of both numerator and denominator
        _denominator = -_denominator;
        _numerator = -_numerator;
    }
    if (abs((_numerator / _denominator)) < 1) {
        return;
    }
    int gcd = FindGCD(_numerator, _denominator);
    if (gcd < 0) {
        gcd *= -1;
    }
    if (gcd > 1) {
        _numerator /= gcd;
        _denominator /= gcd;
    }
}

/**
 * Returns the greatest common divisor of lhs and rhs.
 * @param: rhs: one value checked for the GCD
 * @param: lhs: one value checked for the GCD
 */
int FindGCD(int lhs, int rhs) {
    while (rhs != 0) {
        int temp = rhs;
        rhs = lhs % rhs;
        lhs = temp;
    }
    return lhs;
}




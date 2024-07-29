# Rational Project
## Overview
This project implements a Rational class for representing and manipulating rational numbers. The class supports basic arithmetic operations, comparisons, and conversions between rational numbers and their string or double representations.

# Features
- Constructors: Initialize rational numbers from integers or doubles.
- Arithmetic Operations: Addition, subtraction, multiplication, division.
- Comparison Operations: Equal, not equal, greater than, less than, greater than or equal to, less than or equal to.
- String and Double Conversions: Convert rational numbers to strings or doubles.
- Simplification: Automatically simplify rational numbers upon creation or after arithmetic operations.

# Comparison Operations
- bool operator==(const Rational &rhs) const: Checks if the current rational number is equal to the given rational number.
- bool operator!=(const Rational &rhs) const: Checks if the current rational number is not equal to the given rational number.
- bool operator>(const Rational &rhs) const: Checks if the current rational number is greater than the given rational number.
- bool operator>=(const Rational &rhs) const: Checks if the current rational number is greater than or equal to the given rational number.
- bool operator<=(const Rational &rhs) const: Checks if the current rational number is less than or equal to the given rational number.
- bool operator<(const Rational &rhs) const: Checks if the current rational number is less than the given rational number.

# String and Double Conversions
- std::string ToString() const: Returns the string representation of the rational number.
- double ToDouble() const: Returns the double representation of the rational number.

# Utility Methods
- void Simplify(): Simplifies the current rational number.
- int FindGCD(int lhs, int rhs): Returns the greatest common divisor of the two given integers.

# Non-Member Functions
- Rational operator+(const Rational &lhs, const Rational &rhs): Returns the sum of two rational numbers.
- Rational operator-(const Rational &lhs, const Rational &rhs): Returns the difference between two rational numbers.
- Rational operator*(const Rational &lhs, const Rational &rhs): Returns the product of two rational numbers.
- Rational operator/(const Rational &lhs, const Rational &rhs): Returns the quotient of two rational numbers.
- std::ostream &operator<<(std::ostream &output, const Rational &rational): Outputs the given rational number to the specified output stream.

# Unit Tests
The 'main' function includes a series of tests to validate the functionality of the Rational class. These tests cover:
- Construction and conversion methods.
- String and double representations.
- Arithmetic operations.
- Comparison operations.
- Run the main function 

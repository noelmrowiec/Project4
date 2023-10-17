#ifndef MONEY_H
#define MONEY_H

#include <cstdlib>
#include <cctype>
#include <iostream>

//Class for amounts of money in U.S. currency.
// C++20 Compiler required 
class Money
{
public:
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with the
    //dollars and cents given by the arguments. If the amount is negative,
    //then both dollars and cents must be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00
    Money();
    
    auto operator<=>(const Money&) const = default;
    //This is the C++20 way of comparing
    //Performs comparisons.Overloaded function performs >, >=, <, <=, ==, and != 
    // (note: with the 'default' keyword, no implementation is necessary) 

    double getValue() const;
    //Returns the value of the Money object in dollars with the decimal as the cents

    friend std::istream& operator >>(std::istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in −$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    friend std::ostream& operator <<(std::ostream& outs, const Money& amount);
    //Overloads the < operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream,
    //then outs has already been connected to a file.
    double percent(int) const;
    //Returns a percentage of the money amount in the calling object
private:
    long allCents;
};

int digitToInt(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digitToInt('3') returns 3.

#endif
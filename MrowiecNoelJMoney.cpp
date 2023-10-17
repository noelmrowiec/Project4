/*
* Money class definition 
Author: Noel Mrowiec with code from textbook
*/
#include "MrowiecNoelJMoney.h"

Money::Money(long dollars, int cents) 
{
    if (dollars * cents < 0)
    {
        std::cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars * 100 + cents;
}

Money::Money(long dollars)
{
    allCents = dollars * 100;
}

Money::Money() : allCents{0}
{

}

double Money::getValue() const
{
    return allCents * 0.01;
}

double Money::percent(int percentFigure) const
{
    return getValue() * (.01 * percentFigure);      //convert percentFigure from in to a percentage 
}

std::istream& operator >>(std::istream& ins, Money& amount)
{
    char oneChar, decimalPoint,
        digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'
    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    if (oneChar != '$' || decimalPoint != '.'|| !isdigit(digit1) || !isdigit(digit2))
    {
        std::cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    amount.allCents = dollars * 100 + cents;
    if (negative)
        amount.allCents = -amount.allCents;
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Money& amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.allCents < 0)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}


int digitToInt(char c)
{
    return static_cast<int>(c) - static_cast<int>('0');
}
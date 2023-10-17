/*
* Application file to use Money class. Tests Money class.
Author: Noel Mrowiec with code from textbook
*/

#include "MrowiecNoelJMoney.h"
#include <fstream>
#include <cassert> // for assert()

int main()
{
    Money amount;
    std::ifstream inStream;
    std::ofstream outStream;

    inStream.open("infile.dat");
    if (inStream.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }

    outStream.open("outfile.dat");
    if (outStream.fail())
    {
        std::cout << "Output file opening failed.\n";
        exit(1);

    }
    inStream >> amount;
    outStream << amount
        << " copied from the file infile.dat.\n";
    std::cout << amount
        << " copied from the file infile.dat.\n";

    inStream.close();
    outStream.close();

    //my tests
    //Test percent(int) and constructors
    Money ten{ 10 };
    auto expected_result{ 1.0 };
    assert(ten.percent(10) == expected_result);

    Money ninehun{ 900, 10 };
    expected_result = 90.01 ;
    assert(ninehun.percent(10) == expected_result);

    expected_result = 108.012;
    assert(ninehun.percent(12) == expected_result);
    
    //Test comparisions and default constructor
    Money ninehun2{ 900, 10 };
    assert(ninehun == ninehun2);
    assert(ninehun != Money{});     //Money{} is $0.00 by default
    assert(ninehun >= Money{});     
    assert(Money{} <= ninehun);
    assert(ninehun > Money{});
    assert(Money{} < ninehun);

    //Test getValue()
    Money five{ 5, 5 };
    expected_result = 5.05;
    assert(five.getValue() == expected_result);

    std::cout << "All tests passed\n";
    return 0;

}




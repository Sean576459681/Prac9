// this file is Convert header file.
// adds prac9
#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <string>
class Convert{
    public:
    std::string convertToInfix(std::string);
    bool isOperator(char Operator);
    bool isPlusMinus(char);
    int doCalculation(char Operator, int operand1, int operand2);
};
#endif

// * - 5 6 7
// (5 - 6) * 7 = -7
// (5 - 6) * 7 = -7
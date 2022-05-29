// this file is Convert cpp file
// adds prac9
#include <stack>
#include "Convert.h"
#include <typeinfo>
using namespace std;
string Convert::convertToInfix(string PrefixStr){
    //get the length of the prefix string 
    int strLength = PrefixStr.length();

    // firstly traverse through the PrefixStr to make sure it is valid
    int numOperands = 0;
    int numOperators = 0;
    for(int i = 0; i < strLength; i++){
        if(isOperator(PrefixStr[i])){
            numOperators++;
        }else if(PrefixStr[i]==' '){
            continue;
        }else{
            numOperands++;
        }
    }
    // testing the accurancy of numOperands and numOperators
    // cout<<PrefixStr<<endl<<numOperands<<" operands "<<numOperators<<" operators "<<endl;
    numOperators++;
    if(numOperators!=numOperands){
        cout<<"Error"<<endl;
        exit(1);
    }
    
    //create an empty string stack to store the infix notation
    stack<string> infixNotation;
    //create an empty number stack to store the numbers for calculation
    stack<int> numbers;

    //traverse through each elements in the prefix string
    for(int i = strLength-1; i >= 0; i--){

        // if the current element is a space, skip this loop
        if(PrefixStr[i] == ' '){
            continue;
        }

        // if the current element is an operator
        if(isOperator(PrefixStr[i])){
            // get the last in element and delete it
            string operand1 = infixNotation.top();
            infixNotation.pop();
            string operand2 = infixNotation.top();
            infixNotation.pop();

            // get the last in numbers and delete it
            int op1_cal = numbers.top();
            numbers.pop();
            int op2_cal = numbers.top();
            numbers.pop();

            //if it is a plus or minus operator, using parenthesis
            if(isPlusMinus(PrefixStr[i])){
                // create the infix notation and push to the infixnotation string
                string tempStr = "(" + operand1 + " " + PrefixStr[i] + " " + operand2 + ")";
                int tempNum = doCalculation(PrefixStr[i], op1_cal, op2_cal);
                infixNotation.push(tempStr);
                numbers.push(tempNum);
                
                // if it is a multiply or divide operations
            }else{
                string tempStr = operand1 + " " + PrefixStr[i] + " " + operand2;
                int tempNum = doCalculation(PrefixStr[i], op1_cal, op2_cal);
                infixNotation.push(tempStr);
                numbers.push(tempNum);
            }

            // if the current element is a operands
        }else{
            // push string
            infixNotation.push(string(1, PrefixStr[i]));
            // push numbers 
            // cout << typeid((int)PrefixStr[i]).name() << endl;
            // cout<<"NUMBER PUSH IN NUM STACK: "<<PrefixStr[i] - '0'<<endl;
            numbers.push(PrefixStr[i]-'0');
            //stoi(PrefixStr[i], nullptr, 10)
        }
    }
    // cout<<numbers.top()<<endl;
    string final_res = infixNotation.top() + " = " + to_string(numbers.top());

    return final_res;
}

int Convert::doCalculation(char Operator, int operand1, int operand2){
    int res = -1;
    switch (Operator){
    case '+':
        return operand1+operand2;
    case '-':
        return operand1-operand2;
    case '/':
        return operand1/operand2;
    case '*':
        return operand1*operand2;
    }
    return res;
}

bool Convert::isOperator(char Operator){
    switch (Operator){
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

bool Convert::isPlusMinus(char Operator){
    switch (Operator){
    case '+':
    case '-':
        return true;
    }
    return false;
}
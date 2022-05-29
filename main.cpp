// main for submitting
// adds prac9
#include <iostream>
#include <string>
#include "Convert.h"
using namespace std;
int main(){
    string prefix_notation;
    getline(std::cin, prefix_notation);
    // cout<<prefix_notation<<endl;
    Convert con1;
    string infix_notation = con1.convertToInfix(prefix_notation);
    // cout<<"P: "<<prefix_notation<<endl;
    cout<<infix_notation<<endl;
}
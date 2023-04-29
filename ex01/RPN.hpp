#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
class RPN
{
private:
    std ::stack<std ::string> mystack;
    std ::stack<int> my_valour;
    std ::stack<char> car;

public:
    RPN(){};
    RPN(char *des);
    RPN(const RPN &src);
    ~RPN(){};
    RPN &operator=(const RPN &typs);
};
#endif
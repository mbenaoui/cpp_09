#include "RPN.hpp"

RPN::RPN(char * des)
{
    char *str = strtok(des, " ");
    while (str)
    {
        mystack.push(str);
        str = strtok(NULL, " ");
    }
    while (!mystack.empty())
    {
        if (mystack.top().size() > 1)
        {
            std ::cout << "erreor: " << std ::endl;
            return ;
        }
        car.push(mystack.top()[0]);
        mystack.pop();
    }
    while (!car.empty())
    {
        if (isdigit(car.top()))
        {
            my_valour.push(car.top() - '0');
        }

        else if (car.top() == '-' && my_valour.size() >= 2)
        {
            int prim = my_valour.top();
            my_valour.pop();
            int second = my_valour.top();
            my_valour.pop();
            my_valour.push(second - prim);
        }
        else if (car.top() == '+' && my_valour.size() >= 2)
        {
            int prim = my_valour.top();
            my_valour.pop();
            int second = my_valour.top();
            my_valour.pop();
            my_valour.push(second + prim);
        }
        else if (car.top() == '*' && my_valour.size() >= 2)
        {
            int prim = my_valour.top();
            my_valour.pop();
            int second = my_valour.top();
            my_valour.pop();
            my_valour.push(second * prim);
        }
        else if (car.top() == '/' && my_valour.size() >= 2)
        {
            int prim = my_valour.top();
            my_valour.pop();
            int second = my_valour.top();
            my_valour.pop();
            if (prim == 0)
            {
                std ::cout << "error: " << std::endl;
                return ;
            }
            my_valour.push(second / prim);
        }
        else if (my_valour.size() <= 1)
        {
            std ::cout << "error: " << std::endl;
            return ;
        }

        car.pop();
    }
    if (!my_valour.empty())
        std ::cout << my_valour.top() << std::endl;

}
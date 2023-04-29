#include <iostream>
#include <stack>
using namespace std;

int main(int ac, char **av)
{
    stack<std ::string> mystack;
    stack<int> my_valour;
    stack<char> car;
    char *str = strtok(av[1], " ");
    while (str)
    {
        mystack.push(str);
        str = strtok(NULL, " ");
    }
    while (!mystack.empty())
    {
        //  std ::cout << mystack.top() << std::endl;
        if (mystack.top().size() > 1)
        {
            std ::cout << "erreor: " << std ::endl;
            return 0;
        }
        car.push(mystack.top()[0]);
        mystack.pop();
    }
    while (!car.empty())
    {
        //  std ::cout << "hna 1" << std::endl;
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
                return 1;
            }
            my_valour.push(second / prim);
        }
        else if (my_valour.size() <= 1)
        {
            std ::cout << "error: " << std::endl;
            return 0;
        }

        car.pop();
    }
    if (!my_valour.empty())
        std ::cout << my_valour.top() << std::endl;

    // mystack.push(5);
    // mystack.push(1);
    // mystack.push(6);

    return 0;
}
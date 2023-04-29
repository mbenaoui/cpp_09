#include "BitcoinExchange.hpp"

int ft_check_is(std ::string url)
{
    for (int i = 0; i < url.size(); i++)
    {
        if (url[i] == ' ')
            ;
        else if (url[i] < '0' || url[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int check_date(std::string date)
{
    std ::string url = strtok((char *)date.c_str(), "-");
    std ::string url1 = strtok(NULL, "-");
    std ::string url2 = strtok(NULL, "-");
    int j = atoi(url1.c_str());
    int d = atoi(url2.c_str());
    if ((url1 == "02" && atoi(url2.c_str()) > 28))
        return 1 ;
    if (j > 12 || j < 1 || d < 1 || d > 31 || !ft_check_is(url1) || !ft_check_is(url2))
        return 1;
    return 0;
}
std ::vector<std ::string> split(std::string str, std::string delimiter)
{
    std ::vector<std ::string> v;
    if (!str.empty())
    {
        int start = 0;
        do
        {
            size_t idx = str.find(delimiter, start);
            if (idx == std ::string::npos)
            {
                break;
            }

            int length = idx - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        v.push_back(str.substr(start));
    }
    return v;
}
std::string int_to_string(int numb)
{
    std::ostringstream ss;
    ss << numb;
    return ss.str();
}

int main(int ac, char **av)
{
    // std :: string  str = av[1];

    // using stringstream

    BitcoinExchange dt(av[1]);
    return 0;
}
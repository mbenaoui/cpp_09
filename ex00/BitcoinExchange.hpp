#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
private:
    std ::map<std::string, std ::string> mymap;
    std ::string red_file;
    std ::string excve_file;

public:
    BitcoinExchange(){};
    BitcoinExchange(char *des);
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange(){};
    BitcoinExchange &operator=(const BitcoinExchange &typs);
};
std ::vector<std ::string> split(std::string str, std::string delimiter);
int check_date(std::string date);
int ft_check_is(std ::string url);
std::string int_to_string(int numb);

#endif
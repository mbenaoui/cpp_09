#include "BitcoinExchange.hpp"

BitcoinExchange ::BitcoinExchange(char *des)
{
    red_file = "./data.csv";
    excve_file = des;
    std::ifstream file(red_file);
    std::string headr;
    if (file)
    {
        std::ostringstream str;
        str << file.rdbuf();
        headr = str.str();
    }
    std ::vector<std ::string> res = split(headr, "\n");
    for (size_t i = 0; i < res.size(); i++)
    {
        std ::string key = res[i].substr(0, res[i].find(","));
        std ::string value = res[i].substr(res[i].find(",") + 1);
        mymap.insert(std ::pair<std ::string, std::string>(key, value));
    }
    std::ifstream file1(excve_file);
    std::string check;
    if (file1)
    {
        std::ostringstream str;
        str << file1.rdbuf();
        check = str.str();
    }
    std ::vector<std ::string> res1 = split(check, "\n");
    for (size_t i = 1; i < res1.size(); i++)
    {
        std ::string key = res1[i].substr(0, res1[i].find("|"));
        std ::string first_key;
        std ::string value = res1[i].substr(res1[i].find("|") + 1);
        for (int j = 0; j < key.size(); j++)
        {
            if (key[j] == ' ')
                ;
            else
                first_key += key[j];
        }
        double fd = std::stod(value);
        if (check_date(first_key))
            std ::cout << "Error: bad input => " << first_key << std::endl;
        else if (fd < 0)
            std ::cout << "Error: not a positive number.\n";
        else if (fd > 2147483647)
            std ::cout << "Error: too large a number.\n";
        else
        {
            //  std :: cout << "|" <<first_key  << "|" << value << std::endl;
            if (mymap[first_key].empty())
            {
                std ::string first_key1 = first_key;
                std ::string url = strtok((char *)first_key.c_str(), "-");
                std ::string url1 = strtok(NULL, "-");
                std ::string url2 = strtok(NULL, "-");
             
                int ent = 0;
                int d = atoi(url2.c_str());
                int m = atoi(url1.c_str());
                int ans = atoi(url.c_str());
                std ::string str = url + "-" + url1 + "-" + int_to_string(d);
                while (d != 0)
                {
                    if (mymap[str].empty())
                    {
                        d--;
                        std ::string des = int_to_string(d);
                        if (des.size() > 1)
                            str = url + "-" + url1 + "-" + int_to_string(d);
                        else
                            str = url + "-" + url1 + "-" + "0" + int_to_string(d);
                    }
                    else
                    {
                        ent = 1;
                        double fd1 = std::stod(mymap[str]);
                        double re = fd * fd1;

                        std ::cout << first_key1 << " => " << value << " = " << re << std::endl;

                        break;
                    }
                }
                int ent1 = 0;
                if (ent == 0)
                {
                    int days = 31;
                    m--;
                    while (m != 0)
                    {
                        std ::string meth;
                        if (int_to_string(m).size() > 1)
                            meth = int_to_string(m);
                        else
                            meth = "0" + int_to_string(m);

                        str = url + "-" + meth + "-" + int_to_string(days);
                        while (days != 0)
                        {
                            if (mymap[str].empty())
                            {
                                days--;
                                std ::string des = int_to_string(days);
                                if (des.size() > 1)
                                    str = url + "-" + meth + "-" + int_to_string(days);
                                else
                                    str = url + "-" + meth + "-" + "0" + int_to_string(days);
                            }
                            else
                            {
                                ent1 = 1;
                                double fd1 = std::stod(mymap[str]);
                                double re = fd * fd1;

                                std ::cout << first_key1 << " => " << value << " = " << re << std::endl;

                                break;
                            }
                        }
                        if (ent1 == 1)
                            break;
                        days = 31;
                        m--;
                    }
                }
                if (ent == 0 && ent1 == 0)
                {
                    int days = 31;
                    int month = 12;
                    ans--;
                    int ent2 = 0;
                    while (ans >= 2009)
                    {
                        while (month != 0)
                        {
                            // std ::cout << str << std::endl;
                            std ::string meth;
                            if (int_to_string(month).size() > 1)
                                meth = int_to_string(month);
                            else
                                meth = "0" + int_to_string(month);

                            str = int_to_string(ans) + "-" + meth + "-" + int_to_string(days);
                            while (days != 0)
                            {
                                if (mymap[str].empty())
                                {
                                    days--;
                                    std ::string des = int_to_string(days);
                                    if (des.size() > 1)
                                        str = int_to_string(ans) + "-" + meth + "-" + int_to_string(days);
                                    else
                                        str = int_to_string(ans) + "-" + meth + "-" + "0" + int_to_string(days);
                                }
                                else
                                {
                                    ent2 = 1;
                                    double fd1 = std::stod(mymap[str]);
                                    double re = fd * fd1;

                                    std ::cout << first_key1 << " => " << value << " = " << re << std::endl;

                                    break;
                                }
                            }
                            if (ent2 == 1)
                                break;
                            days = 31;
                            month--;
                        }
                        if (ent2 == 1)
                            break;
                        month = 12;

                        ans--;
                    }
                }
            }
            else
            {
                double fd1 = std::stod(mymap[first_key]);
                double re = fd * fd1;

                std ::cout << first_key << " => " << value << " = " << re << std::endl;
            }
        }
    }
}
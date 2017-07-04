#include "basic_funcs.h"

std::string int_to_str(int num)
{
    std::string str;
    char ch;

    if (num == 0)
    {
        str += "0";
        return str;
    }

    while(num > 0)
    {
        str += char(num % 10 + 48);
        num /= 10;
    }

    for(int i = 0; i < str.length() / 2; i++)
    {
        ch = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = ch;
    }

    return str;
}

int str_to_int(std::string str)
{
    int num = 0;

    for(int i = 0; i < str.length(); i++)
    {
        num = num * 10 + int(str[i]) - 48;
    }

    return num;
}

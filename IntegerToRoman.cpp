/*************************************************************************
	> File Name: IntegerToRoman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 21时03分41秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string intRoman(int num)
{
    int basicInt[]      = {1000, 900,  500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    string basicRoman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    string result = "";
    int i = 0;
    while(num > 0)
    {
        while(num >= basicInt[i])
        {
            result += basicRoman[i];
            num -= basicInt[i];
        }
        i++;
    }
    return result;
}

int main()
{
    int num1 = 3999;
    int num2 = 1999;
    int num3 = 1;

    cout<<num1<<":"<<intRoman(num1)<<endl;
    cout<<num2<<":"<<intRoman(num2)<<endl;
    cout<<num3<<":"<<intRoman(num3)<<endl;

    return 0;
}


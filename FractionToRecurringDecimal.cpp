/*************************************************************************
	> File Name: FractionToRecurringDecimal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月19日 星期日 17时53分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
#include<cmath>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if(numerator == 0) return string("0");
    string result;
    bool flag = (numerator < 0) ^ (denominator < 0);
    long long Numerator = abs((long long)numerator);
    long long Denominator = abs((long long)denominator);
    if(flag) result += "-";
    ostringstream out;
    out << (Numerator / Denominator);
    result += out.str();
    Numerator = Numerator % Denominator;
    if(Numerator == 0) return result;
    result += ".";
    unordered_map<int, int> m;
    for(int i = result.size(); Numerator != 0; ++i)
    {
        if(m.find(Numerator) != m.end()) break;
        m[Numerator] = i;
        Numerator *= 10;
        result += (Numerator / Denominator + '0');
        Numerator %= Denominator;
    }
    if(Numerator == 0) return result;
    result.insert(m[Numerator], "(");
    result += ")";
    return result;
}

int main()
{
    int numerator = 2;
    int denominator = 3;
    cout<<fractionToDecimal(numerator, denominator)<<endl;

    return 0;
}


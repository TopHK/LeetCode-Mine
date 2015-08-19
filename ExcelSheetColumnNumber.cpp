/*************************************************************************
	> File Name: ExcelSheetColumnNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 08时59分31秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int titleToNumber(string s)
{
    map<char, int> charToInt;
    char ch = 'A';
    int num = 1;
    while(ch <= 'z') charToInt[ch++] = num++;

    int size = s.size();
    int base = 1;
    int number = 0;

    for(int i=size-1; i>=0; --i)
    {
        char currentChar = s[i];
        int currentNum = charToInt[currentChar];
        number += currentNum*base;
        base *= 26;
    }
    return number;
}

int main()
{
    string str1 = "A";
    cout<<titleToNumber(str1)<<endl;
    string str2 = "AA";
    cout<<titleToNumber(str2)<<endl;
    string str3 = "Z";
    cout<<titleToNumber(str3)<<endl;
    string str4 = "ZA";
    cout<<titleToNumber(str4)<<endl;
    
    return 0;
}

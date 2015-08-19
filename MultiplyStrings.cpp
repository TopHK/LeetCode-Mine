/*************************************************************************
	> File Name: MultiplyStrings.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月02日 星期四 09时47分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void add(string& str1, string& str2)
{
    int flag = 0;
    int size = str1.size();
    for(int i=0; i<size; ++i)
    {
        int temp = (str1[i]-'0')+(str2[i]-'0')+flag;
        if(temp >= 10)
        {
            temp -= 10;
            flag = 1;
        }
        else flag = 0;
        str1[i] = temp+'0';
    }
    if(flag == 1) str1.append("1");
}

string multiplyCore(const string& s, const char ch)
{
    int flag = 0;
    int num = ch-'0';
    string result;
    for(int i=0; i<s.size(); ++i)
    {
        int temp = (s[i]-'0')*num + flag;
        if(temp >= 10)
        {
            flag = temp/10;
            temp %= 10; 
        }
        else flag = 0;
        result.push_back(temp+'0');
    }
    if(flag != 0) 
        result.push_back(flag+'0');
    return result;
}

string multiply(string num1, string num2)
{
    if(num1=="0" || num2=="0") return "0";
    if(num1=="1") return num2;
    if(num2=="1") return num1;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int size = num2.size();
    
    string result;
    for(int i=0; i<size; ++i)
    {
        string temp = multiplyCore(num1, num2[i]);
        cout<<temp<<endl;
        if(i == 0) result = temp;
        else 
        {
            temp.insert(0, i, '0');
            int diffSize = temp.size()-result.size();
            if(diffSize > 0) result.append(diffSize, '0');
            add(result, temp);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string num1 = "923";
    string num2 = "345329";
    cout<<multiply(num1, num2)<<endl;

    return 0;
}


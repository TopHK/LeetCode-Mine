/*************************************************************************
	> File Name: ExcelSheetColumnTitle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 15时39分40秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string convertToTitle(int n)
{
    string result;
    while(n > 26)
    {
        int digit = n%26;
        if(digit == 0) 
        {
            while(n > 0)
            {
                result.insert(0, 1, 'Z');
                int next = n/26-1;
                if(next >= 26) result.insert(0, 1, 'Z');
                else result.insert(0, 1, 'A'+next-1);
                n = next-26;
                if(n <= 0) return result;
            }
        }
        if(digit != 0)
        {
            result.insert(0, 1, ('A'+digit-1));   
            n /= 26;
        }
        
    }
    if(n == 0) result.insert(0, 1, 'Z');
    else result.insert(0, 1, ('A'+n-1));
    return result;
}

int main()
{
    int n1 = 104;
    cout<<convertToTitle(n1)<<endl;

    return 0;
}

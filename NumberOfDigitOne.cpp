/*************************************************************************
	> File Name: NumberOfDigitOne.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月09日 星期四 09时12分09秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Solution 
{
public:
    void getDigits(int n, int& digits, int& firstNum, int& restNum)
    {
        int tempN = n;
        digits = 0;
        while(tempN)
        {
            firstNum = tempN%10;
            digits++;
            tempN /= 10;
        }
        restNum = n - firstNum*int(pow(10, digits-1));
    }
    int countDigitOne(int n)
    {
        if(n <= 0) return 0;
        if(n>=1 && n<=9) return 1;
        int digits = 0;
        int firstNum = 0;
        int restNum = 0;
        int count = 0;
        getDigits(n, digits, firstNum, restNum);
        cout<<"digits:"<<digits<<",firstNum:"<<firstNum<<",restNum:"<<restNum<<endl;
        if(firstNum == 1)
        {
            count += (restNum+1);
            count += (digits-1)*int(pow(10, digits-2));
        }
        else 
        {
            count += int(pow(10, digits-1));
            count += firstNum * (digits-1)*int(pow(10, digits-2));
        }
        digits = 0;
        firstNum = 0;
        return count += countDigitOne(restNum);
    }
};

int main()
{
    int n1 = 11;
    Solution sol;
    cout<<sol.countDigitOne(n1)<<endl;

    return 0;
}

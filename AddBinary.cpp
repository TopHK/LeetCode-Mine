/*************************************************************************
	> File Name: AddBinary.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 19时23分23秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void process(string& a, string& b)
    {
        int sizeA = a.size();
        int sizeB = b.size();
        if(sizeA > sizeB) b.insert(0, sizeA-sizeB, '0');
        else if(sizeB > sizeA) a.insert(0, sizeB-sizeA, '0');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    }

    string addBinary(string a, string b)
    {
        process(a, b);
        int flag = 0;
        int size = a.size();
        for(int i=0; i<size; ++i)
        {
            int temp = (a[i]-'0')+(b[i]-'0')+flag;
            a[i] = (temp%2)+'0';
            flag = (temp>=2 ? 1 : 0);
        }
        if(flag == 1) a.append("1");

        reverse(a.begin(), a.end());
        return a;
    }
};

int main()
{
    Solution sol;
    string a = "11";
    string b = "1";
    cout<<sol.addBinary(a, b)<<endl;

    return 0;
}

/*************************************************************************
	> File Name: DecodeWays.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月08日 星期三 10时01分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
class Solution 
{
private:
    int number;
public:
    void numDecodingsCore(string& s)
    {
        if(s.empty()) 
        {
            number++;
            return;
        }
        int size = s.size();
        if(size>=1 && s[0]>='1' && s[0]<='9')
        {
            string temp = s.substr(1);
            numDecodingsCore(temp);
        }
        if(size >= 2)
        {
            string temp = s.substr(0, 2);
            if(temp>="10" && temp<="26")
            {
                temp = s.substr(2);
                numDecodingsCore(temp);
            }
        }
    }
    int numDecodings(string s)
    {
        number = 0;
        numDecodingsCore(s);
        return number;
    }
};
*/

/*
int numDecodings(string s)
{
    size_t size = s.size();
    if(size < 2) return size;
    int number = 1;
    for(int i=1; i<size; ++i)
    {
        number++;
        string temp = s.substr(i-1, 2);
        if(temp>="10" && temp<="26")
            number++;
    }
    return number;
}
*/

int numDecodings(string s)
{
    if(s.empty()) return 0;
    size_t size = s.size();
    vector<int> dp(size+1, 0);
    dp[0] = 1;
    if(s[0]>='1' && s[0]<='9') dp[1] = 1;

    for(int i=2; i<=size; ++i)
    {
        int currentIndex = i-1;
        char currentCh = s[currentIndex];
        string temp = s.substr(currentIndex-1, 2);
        if(currentCh>='1' && currentCh<='9') 
        {
            dp[i] = dp[i-1];
            if(temp>="10" && temp<="26")
                dp[i] += dp[i-2];           
        }
        else 
        {
            char preCh = s[currentIndex-1];
            if(preCh>='3' || preCh=='0') return 0;
            else dp[i] = dp[i-2];
        }
    }
    return dp[size];
}
int main()
{
    string s1("12");
    string s2("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253");
    cout<<numDecodings(s2)<<endl;

    return 0;
}

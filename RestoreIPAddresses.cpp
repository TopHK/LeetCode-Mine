/*************************************************************************
	> File Name: RestoreIPAddresses.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 11时01分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
private:
    vector<string> result;
public:
    void restoreIPAddressesCore(string s, int k, string& oneResult)
    {
        if(k == 0)
        {
            if(s.empty()) result.push_back(oneResult);
            return;
        }
        int size = s.size();
        if(size<k || size>4*k) return;
        string maxStr = "255";
        if(s[0] == '0') 
        {
            string tempStr(oneResult);           
            if(k == 4) tempStr = "0";
            else tempStr = tempStr+".0";
            restoreIPAddressesCore(s.substr(1), k-1, tempStr);
        }
        else 
        {
            for(int len=1; len<=3; ++len)
            {
                string tempStr(oneResult);
                if(size >= len)
                {
                    string IP = s.substr(0, len);
                    if((len==3&&IP.compare(maxStr)<=0) || len<=2)
                    {
                        if(k == 4) tempStr += IP;
                        else tempStr = tempStr+"."+IP;
                        restoreIPAddressesCore(s.substr(len), k-1, tempStr);
                    }
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        string oneResult;
        restoreIPAddressesCore(s, 4, oneResult);
        return result;
    }
};

void print(const vector<string>& result)
{
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main()
{
    string address("25525511135");
    Solution sol;
    vector<string> result = sol.restoreIpAddresses(address);
    print(result);

    return 0;
}

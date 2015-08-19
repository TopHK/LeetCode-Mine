/*************************************************************************
    > File Name: DistinctSubsequences.cpp
    > Author: 
    > Mail: 
    > Created Time: 2015年06月27日 星期六 22时00分44秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
class Solution
{
private:
    int number;
public:
    void numDistinctCore(string s, string t)
    {
        if(t.empty()) 
        {
            number++;
            return;
        }
        int sizeOfS = s.size();
        int sizeOfT = t.size();
        if(sizeOfT > sizeOfS) return;
        char ch = t[0];
        int pos = s.find(ch);
        while(pos!=string::npos && sizeOfS-pos>=sizeOfT)
        {
            if(sizeOfT == 1) 
                number++;
            else if(pos+1 < sizeOfS)
                numDistinctCore(s.substr(pos+1), t.substr(1));   
            pos = s.find(ch, pos+1);
            
        }
    }

    int numDistinct(string s, string t)
    {
        number = 0;
        numDistinctCore(s, t);
        return number;
    }
};
*/

int numDistinct(string s, string t)
{
    if(t.empty()) return 1;
    int size1 = s.size();
    int size2 = t.size();
    if(size1 < size2) return 0;

    vector<vector<int> > num;
    for(int i=0; i<=size1; ++i)
    {
        vector<int> temp(size2+1, 0);
        num.push_back(temp);
    }
    for(int i=0; i<=size1; ++i) num[i][0] = 1;

    for(int i=1; i<=size1; ++i)
    {
        for(int j=1; j<=size2; ++j)
        {
            if(j > i) break;
            num[i][j] = num[i-1][j] + (s[i-1]==t[j-1] ? num[i-1][j-1] : 0);
        }
    }
    return num[size1][size2];
}

int main()
{
    string s("rabbbit");
    string t("rabbit");
    cout<<numDistinct(s, t)<<endl;

    return 0;
}

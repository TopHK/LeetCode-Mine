/*************************************************************************
	> File Name: PermutationSequence.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月01日 星期三 21时49分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    /* Solution 1: according to the permutation law
    string startPermutation(int n, int k)
    {
        string str;
        for(int j=n; j>=n-k+1; --j) str += (j+'0');
        string temp;
        for(int j=1; j<=n-k; ++j) temp += (j+'0');
        str = temp+str;
        cout<<str<<endl;
        return str;
    }
    string getPermutation(int n, int k)
    {
        string str;
        if(k == 1) return str;

        // generate start id
        vector<int> startSequence(n+1, 0);
        startSequence[1] = 1;
        int base = 1;
        for(int i=2; i<=n; ++i)
        {
            base *= i;
            startSequence[i] = base;
        }

        int start = 1;
        for(int i=1; i<=n; ++i)
        {
            if(k == startSequence[i]) return startPermutation(n, i);
            else if(k < startSequence[i]) 
            {
                start = i-1;   
                break;
            }
        }
        int startId = startSequence[start];
        str = startPermutation(n, start);
        while(++startId <= k) next_permutation(str.begin(), str.end());
        return str;
    }
    */

    string getPermutation(int n, int k)
    {
        string result;
        vector<int> digits(n, 0);
        vector<bool> hasUsed(n, false);
        int base = 1;
        for(int i=2; i<n; ++i) base *= i;
        
        int sum = k-1;
        for(int i=0; i<n; ++i)
        {
            digits[i] = sum/base;
            sum = sum%base;
            if(base != 1) base /= (n-i-1);
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(!hasUsed[j])
                {
                    if(digits[i] == 0)
                    {
                        result += (j+'1');
                        hasUsed[j] = true;
                        break;
                    }
                    else digits[i]--;
                }
            }
        }
        return result;
    }

};

int main()
{
    int n = 4;
    int k = 6;
    
    Solution sol;
    cout<<sol.getPermutation(n, k)<<endl;
    return 0;
}


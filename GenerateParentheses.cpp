/*************************************************************************
	> File Name: GenerateParentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 19时39分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool isValidParentheses(const vector<int>& nums)
{
    stack<int> parenthesesStack;
    for(int i=0; i<nums.size(); ++i)
    {
        int currentDigit = nums[i];
        if(currentDigit == 0) parenthesesStack.push(0);
        else if(parenthesesStack.empty() || parenthesesStack.top()!=0) return false;
        else parenthesesStack.pop();
    }
    return parenthesesStack.empty();
}

string transferToStr(const vector<int>& nums)
{
    string str(nums.size(), ' ');
    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i] == 0)  str[i] = '(';
        else str[i] = ')';
    }
    return str;
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    if(0 == n) return result;
    vector<int> oneZero(n, 0);
    vector<int> temp(n, 1);
    oneZero.insert(oneZero.end(), temp.begin(), temp.end());
    temp.clear();

    string currentResult = transferToStr(oneZero);
    result.push_back(currentResult);

    while(next_permutation(oneZero.begin(), oneZero.end()))
    {
        if(isValidParentheses(oneZero))
        {
            currentResult = transferToStr(oneZero);
            result.push_back(currentResult);
        }
    }
    return result;
}

void print(const vector<string>& strs)
{
    for(int i=0; i<strs.size(); ++i)
        cout<<strs[i]<<endl;
    return;
}

int main()
{
    int n1 = 3;
    vector<string> result = generateParenthesis(n1);
    print(result);
    
    return 0;
}

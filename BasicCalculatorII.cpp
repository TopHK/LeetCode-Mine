/*************************************************************************
	> File Name: BasicCalculator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月08日 星期三 19时26分41秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<cstdlib>
using namespace std;

// Solution 1
class Solution1 
{
public:
    int calculate(string s)
    {
        map<char, int> precedence;
        precedence['+'] = 0;
        precedence['-'] = 0;
        precedence['*'] = 1;
        precedence['/'] = 1;
        precedence[')'] = -1;
        if(s.empty()) return 0;
        int num1, num2;
        stack<int> nums;
        stack<char> ops;
        s.insert(0, 1, '(');
        s += ")";
        for(int i=0; i<s.size(); ++i)
        {
            char ch = s[i];
            switch(ch)
            {
            case ' ':
                break;
            case '(':
                ops.push(ch);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case ')':
                while(!ops.empty() && ops.top()!='(' && precedence[ch]<=precedence[ops.top()])
                {
                    char op = ops.top();
                    ops.pop();
                    num2 = nums.top();
                    nums.pop();
                    num1 = nums.top();
                    nums.pop();
                    switch(op)
                    {
                    case '+':
                        nums.push(num1 + num2);
                        break;
                    case '-':
                        nums.push(num1 - num2);
                        break;
                    case '*':
                        nums.push(num1 * num2);
                        break;
                    case '/':
                        nums.push(num1 / num2);
                    }
                }
                if(ch == ')') ops.pop();
                else ops.push(ch);
                break;
            default:
                string strNum;
                while(i<s.size() && s[i]>='0' && s[i]<='9') strNum += s[i++];
                i--;
                nums.push(atoi(strNum.c_str()));
            }
        }
        return nums.empty() ? 0 : nums.top();
    }
};

int main()
{
    Solution1 sol;
    string str1("8 + 2*2");
    cout<<sol.calculate(str1)<<endl;
    string str2("3/2");
    cout<<sol.calculate(str2)<<endl;
    string str3("3 + 5/ 2");
    cout<<sol.calculate(str3)<<endl;

    return 0;
}


/*************************************************************************
	> File Name: BasicCalculator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月08日 星期三 19时26分41秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>
using namespace std;

/*
class Solution 
{
public:
    string postExpressionGenerate(string& s)
    {
        string expression;
        stack<char> ops;
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
            case ')':
                while(!ops.empty() && ops.top()!='(')
                {
                    expression += ops.top();
                    ops.pop();
                }
                ops.pop();
                break;
            case '+':
            case '-':
                expression += " ";
                while(!ops.empty() && ops.top()!='(')
                {
                    expression += ops.top();
                    ops.pop();                   
                }
                ops.push(ch);
                break;
            default:
                expression += ch;
            }
        }
        if(!ops.empty()) expression += ops.top();
        return expression;
    }

    int postExpressionCal(string& expression)
    {
        stack<int> nums;
        int num1, num2;
        for(int i=0; i<expression.size(); ++i)
        {
            char ch = expression[i];
            switch(ch)
            {
            case ' ': 
                break;
            case '+':
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                cout<<"num1:"<<num1<<",num2:"<<num2<<endl;
                nums.push(num1 + num2);
                break;
            case '-':
                num2 = nums.top();
                nums.pop();
                num1 = nums.top();
                nums.pop();
                cout<<"num1:"<<num1<<",num2:"<<num2<<endl;
                nums.push(num1 - num2);
                break;
            default:
                string tempStr;
                while(i < expression.size())
                {
                    char tempCh = expression[i];
                    if(tempCh>='0' && tempCh<='9') tempStr += tempCh;
                    else break;
                    i++;
                }
                i--;
                nums.push(atoi(tempStr.c_str()));
            }
        }
        return nums.top();
    }

    int calculate(string s)
    {
        if(s.empty()) return 0;
        string postExpression = postExpressionGenerate(s);
        return postExpressionCal(postExpression);
    }
};
*/

// Solution 1
class Solution1 
{
public:
    int calculate(string s)
    {
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
            case ')':
                while(!ops.empty() && ops.top()!='(')
                {
                    char op = ops.top();
                    ops.pop();
                    num2 = nums.top();
                    nums.pop();
                    num1 = nums.top();
                    nums.pop();
                    if(op == '+') nums.push(num1 + num2);
                    else nums.push(num1 - num2);
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
// Solution 2
int calculate(string s)
{
    if(s.empty()) return 0;
    stack<int> st;
    st.push(1);
    st.push(1);
    int result = 0;
    for(int i=0; i<s.size(); ++i)
    {
        char ch = s[i];
        switch(ch)
        {
        case ' ':
            break;
        case '(':
        case '+':
            st.push(st.top());
            break;
        case '-':
            st.push(-1*st.top());
            break;
        case ')':
            st.pop();
            break;
        default:
            string numStr;
            int num;
            while(i<s.size() && s[i]>='0' && s[i]<='9')
                numStr += s[i++];
            i--;
            num = atoi(numStr.c_str());
            result += num*st.top();
            st.pop();
        }
    }
    return result;
}
int main()
{
    Solution1 sol;
    string str1("1 + 1");
    cout<<sol.calculate(str1)<<endl;
//    string str2("(21 - 210 + 2) + 34 -6");
//    cout<<sol.calculate(str2)<<endl;
    string str3("(1 + (4+5 + 2)- 3) + (6  +8)");
    cout<<sol.calculate(str3)<<endl;

    return 0;
}


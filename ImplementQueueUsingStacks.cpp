/*************************************************************************
	> File Name: ImplementQueueUsingStacks.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 12时09分35秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Queue 
{
private:
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x)
    {
        st1.push(x);
    }
    void pop(void)
    {
        if(!st2.empty()) st2.pop();
        else 
        {
            while(!st1.empty())
            {
                int val = st1.top();
                st2.push(val);
                st1.pop();
            }
            st2.pop();
        }
    }
    int peek(void)
    {
        if(!st2.empty()) return st2.top();
        else 
        {
            while(!st1.empty())
            {
                int val = st1.top();
                st2.push(val);
                st1.pop();
            }
            return st2.top();
        }
    }
    bool empty(void)
    {
        return st1.empty() && st2.empty();
    }
};


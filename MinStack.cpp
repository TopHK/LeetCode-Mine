/*************************************************************************
	> File Name: MinStack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 09时13分46秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
private:
    stack<int> nums;
    stack<int> minNums;
public:
    void push(int x)
    {
        nums.push(x);
        if(minNums.empty() || minNums.top()>x)
            minNums.push(x);
        else minNums.push(minNums.top());
    }

    void pop()
    {
        nums.pop();
        minNums.pop();
    }

    int top()
    {
        return nums.top();
    }

    int getMin()
    {
        return minNums.top();
    }
};

int main()
{
    MinStack minst1;
    int arr[] = {3, 8, 4, 1, 5, 2, 7};
    for(int i=0; i<sizeof(arr)/sizeof(int); ++i)
    {
        minst1.push(arr[i]);
        cout<<minst1.getMin()<<endl;
    }

    minst1.pop();
    cout<<minst1.getMin()<<endl;
    minst1.pop();
    cout<<minst1.getMin()<<endl;
    minst1.pop();
    cout<<minst1.getMin()<<endl;
    minst1.pop();
    cout<<minst1.getMin()<<endl;
    minst1.pop();
    cout<<minst1.getMin()<<endl;
    return 0;
}




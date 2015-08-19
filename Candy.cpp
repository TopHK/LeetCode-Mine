/*************************************************************************
	> File Name: Candy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月15日 星期三 10时45分19秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

/*
int candy2(vector<int>& ratings)
{
    if(ratings.empty()) return 0;
    int size = ratings.size();
    if(size == 1) return 1;
    int sum = 0;
    vector<int> candies(size, 0);

    int i = 0;
    while(i < size)
    {
        if(i == 0)
        {
            if(ratings[0] < ratings[1])
                candies[0] = 1;
            else if(ratings[0] == ratings[1])
            {
                candies[0] = 1;
                candies[1] = 1;
            }
            else 
            {
                candies[0] = 2;
                candies[1] = 1;               
            }
        }
        else if(i == size-1)
        {
            if(candies[i] == 0)
            {
                if(ratings[i] <= ratings[i-1]) candies[i] = 1;
                else candies[i] = candies[i-1] + 1;
            }
        }
        else 
        {
            if(candies[i] == 0)
            {
                if(ratings[i] > max(ratings[i-1], ratings[i+1]))
                {
                    candies[i] = candies[i-1] + 1;
                    candies[i+1] = 1;
                }
            }           
        }
        i++;
    }
    for(int i=0; i<size; ++i) sum += candies[i];
    return sum;
}
*/

/*
int candy(vector<int>& ratings)
{
    if(ratings.empty()) return 0;
    int size = ratings.size();
    if(size == 1) return 1;
    int sum = 0;
    vector<int> candies(size, 0);
    
    candies[0] = 1;
    for(int i=1; i<size; ++i)
    {
        if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
        else if(ratings[i] == ratings[i-1])
            candies[i] = 1;
        else 
        {
            candies[i] = 1;
            if(candies[i-1] == 1) 
            {
                candies[i-1] = 2;
                int j = i-1;
                while(j-1 >= 0 && ratings[j-1] > ratings[j] && candies[j-1] <= candies[j])
                {
                    candies[j-1] = candies[j] + 1;
                    j--;
                }
            }
               
        }
    }
    for(int i=0; i<size; ++i) sum += candies[i];
    return sum;
}
*/

/*
int candy(vector<int>& ratings)
{
    if(ratings.empty()) return 0;
    int size = ratings.size();
    if(size == 1) return 1;
    int sum = 0;
    int previousCandy = 0;
    int begin = 0;
    int end = 0;
    
    for(int i=1; i<size; ++i)
    {
        if(ratings[i] < ratings[i-1])
            end++;
        else 
        {
            int len = (end-begin+1);
            if(len == 1) 
            {
                if(begin == 0)
                {
                    previousCandy = 1;
                    sum += 1;
                }
                else 
                {
                    previousCandy++;
                    sum += previousCandy;
                }
            }
            else 
            {
                sum += len*(len+1)/2;
                previousCandy = 1;
            }
            begin = i;
            end = i;
        }
    }
    if(ratings[size-1] > ratings[size-2]) sum += (previousCandy + 1);
    else if(ratings[size-1] == ratings[size-2]) sum += 1;
    else 
    {
        int len = (end - begin + 1);
        if(len == 1) sum += (previousCandy + 1);
        else sum += len*(len+1)/2;
    }
    return sum;
}
*/

/*
int candy(vector<int>& ratings)
{
    if(ratings.empty()) return 0;
    int size = ratings.size();
    if(size == 1) return 1;
    int sum = 1;
    int currentCandy = 1;
    for(int i=1; i<size; ++i)
    {
        if(ratings[i] == ratings[i-1]) 
            currentCandy = 1;
        if(ratings[i] < ratings[i-1])
        {
            if(i == 1) currentCandy = 2;
            else if(ratings[i-2] >= ratings[i-1]) currentCandy++;
            else 
            {
                sum--;
                currentCandy = 2;
                continue;
            }
        }
        else if(ratings[i] > ratings[i-1])
        {
            if(i == 1) 
                currentCandy = 2;
            else 
            {
                if(ratings[i-2] <= ratings[i-1])
                    currentCandy++;
                else currentCandy = 2;
            }
        }
        sum += currentCandy;
    }
    return sum;
}
*/

int candy(vector<int>& ratings)
{
    if(ratings.empty()) return 0;
    int size = ratings.size();
    if(size == 1) return 1;   
    int sum = 0;
    vector<int> candies(size, 1);

    for(int i=1; i<size; ++i)
    {
        if(ratings[i] > ratings[i-1]) 
            candies[i] = candies[i-1]+1;
    }
    for(int i=size-2; i>=0; --i)
    {
        if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1])
            candies[i] = candies[i+1] + 1;
    }
    for(int i=0; i<size; ++i)
        sum += candies[i];
    return sum; 
}

int main()
{
    int arr[] = {1, 0, 2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<candy(nums)<<endl;

    return 0;
}


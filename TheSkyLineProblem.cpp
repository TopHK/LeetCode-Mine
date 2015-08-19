/*************************************************************************
	> File Name: TheSkyLineProblem.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月17日 星期五 10时05分08秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<multiset>
using namespace std;

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
{
    vector<pair<int, int> > height;
    for(int i = 0; i < buildings.size(); ++i)
    {
        height.push_back({buildings[i][0], buildings[i][2]});
        height.push_back({buildings[i][1], buildings[i][2]});
    }
    sort(height.begin(), height.end());
    multiset<int> heap;
    heap.insert(0);
    vector<pair<int, int> > result;
    int previous = 0, current = 0;
    for(int i = 0; i < height.size(); ++i)
    {
        if(height[i].second < 0) 
            heap.insert(-height[i].second);
        else heap.erase(heap.find(height[i].second));
        current = *heap.rbegin();
        if(current != previous)
        {
            result.push_back({height[i].first, current});
            previous = current;
        }
    }
    return result;
}


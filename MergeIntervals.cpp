/*************************************************************************
	> File Name: MergeIntervals.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月10日 星期五 14时05分33秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval 
{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
};

bool operator<(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}

class Solution 
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        int size = intervals.size();
        if(size < 2) return intervals;
        vector<Interval> result;
        for(int i=1; i<size; ++i)
        {
            int preEnd = intervals[i-1].end;
            int currentStart = intervals[i].start;
            int currentEnd = intervals[i].end;
            if(currentStart > preEnd) result.push_back(intervals[i-1]);
            else 
            {
                intervals[i].start = intervals[i-1].start;
                intervals[i].end = max(intervals[i-1].end, intervals[i].end);
            }
            if(i == size-1) result.push_back(intervals[i]);
        }
        return result; 
    }
};

void print(const vector<Interval>& intervals)
{
    for(int i=0; i<intervals.size(); ++i)
        cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<" ";
    cout<<endl;
}

int main()
{
    Interval it1(1, 3);
    Interval it2(2, 6);
    Interval it3(8, 10);
    Interval it4(15, 18);
    vector<Interval> intervals;
    intervals.push_back(it1);
    intervals.push_back(it2);
    intervals.push_back(it3);
    intervals.push_back(it4);
    print(intervals);
    Solution sol;
    vector<Interval> result = sol.merge(intervals);
    print(result);

    return 0;
}


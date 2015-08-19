/*************************************************************************
	> File Name: InsertInterval.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月11日 星期六 12时07分12秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

bool operator<(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    if(intervals.empty()) 
    {
        intervals.push_back(newInterval);
        return intervals;
    }

    int start = -1;
    int end = -1;
    int size = intervals.size();
    int s = newInterval.start;
    int e = newInterval.end;
    bool findStart = false;
    sort(intervals.begin(), intervals.end());
    for(int i=0; i<size; ++i)
    {
        int tempStart = intervals[i].start;
        int tempEnd = intervals[i].end;
        if(!findStart && s<tempStart) 
        {
            start = 2*i;
            findStart = true;
        }
        if(e < tempStart) 
        {
            end = 2*i;
            break;
        }
        if(!findStart && s>=tempStart && s<=tempEnd)
        {
            start = 2*i+1;
            findStart = true;
        }
        if(e>=tempStart && e<=tempEnd) 
        {
            end = 2*i+1;
            break;
        }
    }
    cout<<"start:"<<start<<",end:"<<end<<endl;
    if(start==0 && end==0)
        intervals.insert(intervals.begin(), newInterval);
    else if(start==-1 && end==-1)
        intervals.push_back(newInterval);
    else if(start == end)
    {
        if((start&1) == 0)
        {
            int i = (start>>1);
            intervals.insert(intervals.begin()+i, newInterval);
        }
    }
    else 
    {
        int i = (start >> 1);
        int j = (end >> 1);
        newInterval.start = min(s, intervals[i].start);
        if(start!=-1 && end==-1)
        {
            newInterval.end = e;
            intervals.erase(intervals.begin()+i, intervals.end());
        }
        else if((end&1) == 0) // 特别注意& 和 ==的优先级
        {
            newInterval.end = e;
            intervals.erase(intervals.begin()+i, intervals.begin()+j);
        }
        else 
        {
            newInterval.end = intervals[j].end;
            intervals.erase(intervals.begin()+i, intervals.begin()+j+1);
        }
        intervals.insert(intervals.begin()+i, newInterval);
    }
    return intervals;
}

void print(const vector<Interval>& intervals)
{
    for(int i=0; i<intervals.size(); ++i)
        cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<" ";
    cout<<endl;
}

int main()
{
    Interval it1(0, 4);
    Interval it2(7, 12);
    Interval it3(6, 7);
    Interval it4(8, 10);
    Interval it5(12, 16);
    vector<Interval> intervals;
    intervals.push_back(it1);
    intervals.push_back(it2);
//    intervals.push_back(it3);
//    intervals.push_back(it4);
//    intervals.push_back(it5);
    print(intervals);

    Interval newInterval(0, 5);
    vector<Interval> result = insert(intervals, newInterval);
    print(result);

    return 0;
}


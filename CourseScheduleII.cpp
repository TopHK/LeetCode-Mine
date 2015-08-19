/*************************************************************************
	> File Name: CourseSchedule.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 09时59分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<queue>
using namespace std;

class Graph 
{
private:
    vector<int> indegree;
    queue<int> zeroIndegree;
    vector<vector<int> > nodes;
    vector<int> orderCourses;
public:
    Graph(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        indegree.resize(numCourses, 0);
        nodes.resize(numCourses);
        for(vector<pair<int, int> >::iterator it=prerequisites.begin(); it!=prerequisites.end(); ++it)
        {
            int course1 = it->first;
            int course2 = it->second;
            indegree[course1]++;
            nodes[course2].push_back(course1);
        }
        for(int i=0; i<numCourses; ++i)
            if(indegree[i] == 0) zeroIndegree.push(i);
    }
    vector<int> topologicalSort()
    {
        while(!zeroIndegree.empty())
        {
            int course = zeroIndegree.front();
            orderCourses.push_back(course);
            zeroIndegree.pop();
            for(int i=0; i<nodes[course].size(); ++i)
            {
                int tempCourse = nodes[course][i];
                indegree[tempCourse]--;
                if(indegree[tempCourse] == 0) zeroIndegree.push(tempCourse);
            }
        }
        for(int i=0; i<indegree.size(); ++i)
        {
            if(indegree[i] != 0) 
            {
                orderCourses.clear();
                break;
            }
        }
        return orderCourses;
    }
};

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        Graph graph(numCourses, prerequisites);
        return graph.topologicalSort();
    }
};

void print(const vector<int>& courses)
{
    for(int i=0; i<courses.size(); ++i)
        cout<<courses[i]<<" ";
    cout<<endl;
}

int main()
{
    pair<int,int> course1 = make_pair(1,0);
    pair<int,int> course2 = make_pair(0,1);
    pair<int,int> course3 = make_pair(0,2);

    vector<pair<int,int> > vec1;
    vec1.push_back(course1);
//    vec1.push_back(course2);
    Solution sol1;
    vector<int> result1 = sol1.findOrder(2,vec1);
    print(result1);

    Solution sol2;
    vector<pair<int,int> > vec2;
    vec2.push_back(course3);
    vector<int> result2 = sol2.findOrder(3,vec2);
    print(result2);
    return 0;
}

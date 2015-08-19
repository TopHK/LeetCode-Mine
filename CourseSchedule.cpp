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

/*
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
{
    if(prerequisites.empty()) return true;
    map<int, vector<int> > coursePair;
    map<int, bool> courses;
    for(int i=0; i<prerequisites.size(); ++i)
    {
        int firstCourse = prerequisites[i].first;
        int secondCourse = prerequisites[i].second;
        coursePair[firstCourse].push_back(secondCourse);
    }
    
    map<int, vector<int> >::iterator it = coursePair.begin();
    int currentKey = it->first;
    int secondCourse;
    while(!coursePair.empty())
    {
        courses[currentKey] = true;
        for(int i=0; i<coursePair[currentKey].size(); ++i)
        {
            int secondCourse = coursePair[currentKey][i];
            if(coursePair.find(secondCourse)==coursePair.end()) 
            {
                courses.clear();
                coursePair.erase(currentKey);
                if(coursePair.empty()) return true;
                it = coursePair.begin();
                currentKey = it->first; 
                break;
            }
            else 
            {
                if(courses.find(secondCourse) != courses.end()) return false;
                else courses[secondCourse] = true;
                currentKey = secondCourse;
                coursePair.erase(currentKey);
            }
        }
    }
    return true;
}
*/

class Graph 
{
private:
    vector<int> indegree;
    queue<int> zeroIndegree;
    vector<vector<int> > nodes;
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
    bool topologicalSort()
    {
        while(!zeroIndegree.empty())
        {
            int course = zeroIndegree.front();
            zeroIndegree.pop();
            for(int i=0; i<nodes[course].size(); ++i)
            {
                int tempCourse = nodes[course][i];
                indegree[tempCourse]--;
                if(indegree[tempCourse] == 0) zeroIndegree.push(tempCourse);
            }
        }
        for(int i=0; i<indegree.size(); ++i)
            if(indegree[i] != 0) return false;
        return true;
    }
};

class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
    {
        Graph graph(numCourses, prerequisites);
        return graph.topologicalSort();
    }
};

int main()
{
    pair<int,int> course1 = make_pair(1,0);
    pair<int,int> course2 = make_pair(0,1);
    pair<int,int> course3 = make_pair(0,2);

    vector<pair<int,int> > vec1;
    vec1.push_back(course1);
//    vec1.push_back(course2);
    Solution sol1;
    if(sol1.canFinish(2,vec1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    Solution sol2;
    vector<pair<int,int> > vec2;
    vec2.push_back(course3);
    if(sol2.canFinish(3,vec2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

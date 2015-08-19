/*************************************************************************
	> File Name: CloneGraph.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 21时16分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x):label(x){};
};

/*
class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(!node) return NULL;
        map<int, UndirectedGraphNode*> nodes;
        map<int, bool> nodesVisited;
        queue<UndirectedGraphNode*> nodesQueue;
        nodesQueue.push(node);

        while(!nodesQueue.empty())
        {
            UndirectedGraphNode *tempNode = nodesQueue.front();
            nodesQueue.pop();
            UndirectedGraphNode *newNode = new UndirectedGraphNode(tempNode->label);
            nodes[tempNode->label] = newNode;
            for(int i=0; i<(tempNode->neighbors).size(); ++i)
            {
                int tempLabel = (tempNode->neighbors)[i]->label;
                if(nodes.find(tempLabel) == nodes.end()) 
                    nodesQueue.push((tempNode->neighbors)[i]);
            }
        }

        nodesQueue.push(node);
        while(!nodesQueue.empty())
        {
            UndirectedGraphNode *tempNode = nodesQueue.front();
            nodesQueue.pop();
            int label = tempNode->label;
            nodesVisited[label] = true;
            for(int i=0; i<(tempNode->neighbors).size(); ++i)
            {
                int tempLabel = (tempNode->neighbors)[i]->label;
                (nodes[label]->neighbors).push_back(nodes[tempLabel]);
                if(nodesVisited.find(tempLabel) == nodesVisited.end()) 
                    nodesQueue.push((tempNode->neighbors)[i]);
            }
        }      
        return nodes[node->label];
    }
};
*/

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(!node) return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> nodesQueue;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        nodes[node] = newNode;
        nodesQueue.push(node);

        while(!nodesQueue.empty())
        {
            UndirectedGraphNode *currentNode = nodesQueue.front();
            nodesQueue.pop();
            int size = (currentNode->neighbors).size();
            for(int i=0; i<size; ++i)
            {
                UndirectedGraphNode *tempNode = (currentNode->neighbors)[i];
                if(nodes.count(tempNode) == 0)
                {
                    newNode = new UndirectedGraphNode(tempNode->label);
                    nodes[tempNode] = newNode;
                    (nodes[currentNode]->neighbors).push_back(newNode);
                    nodesQueue.push(tempNode);
                }
                else (nodes[currentNode]->neighbors).push_back(nodes[tempNode]);
            }
        }

        return nodes[node];
    }
};

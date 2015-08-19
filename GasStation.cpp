/*************************************************************************
	> File Name: GasStation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月28日 星期日 17时46分33秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*
class Solution
{
public:
    bool canCompleteCircuitCore(vector<int>& gas, vector<int>& cost, int start)
    {
        int N = gas.size();
        vector<int> currentGas(N, 0);
        currentGas[start] = gas[start];
        if(currentGas[start] < cost[start]) return false;

        for(int i=start+1; i<=N-1; ++i)
        {
            currentGas[i] = currentGas[i-1]-cost[i-1]+gas[i];
            if(currentGas[i] < cost[i]) return false;
        }
        if(start == 0) return true;

        currentGas[0] = currentGas[N-1]-cost[N-1]+gas[0];
        for(int i=1; i<=start-1; ++i)
        {
            currentGas[i] = currentGas[i-1]-cost[i-1]+gas[i];
            if(currentGas[i] < cost[i]) return false;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int N = gas.size();
        for(int start=0; start<=N-1; ++start)
        {
            if(canCompleteCircuitCore(gas, cost, start))
                return start;
        }
        return -1;
    }
};
*/

// Solution 2: greedy Solution
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    if(gas.empty()) return -1;
    int N = gas.size();
    if(N == 1) return (gas[0]>=cost[0] ? 0 : -1);
    vector<int> currentGas(N, 0);
    int start = 0;
    
    bool hasStarted = false;
    for(int i=0; i<=N-1; ++i)
    {
        if(!hasStarted)
        {
            if(gas[i] >= cost[i]) 
            {
                start = i;
                currentGas[i] = gas[i];
                hasStarted = true;
            }
            continue;
        }

        int tempGas = gas[i];
        int tempPreGas = currentGas[i-1]-cost[i-1]+gas[i];
        int maxGas = max(tempGas, tempPreGas);
        if(maxGas < cost[i])
            hasStarted = false;
        else 
        {
            currentGas[i] = maxGas;
            if(tempGas > tempPreGas) start = i;
        }
    }
    if(!hasStarted) return -1;

    currentGas.clear();
    currentGas.resize(N, 0);
    currentGas[start] = gas[start];
    vector<int> part1Gas(gas.begin(), gas.begin()+start);
    gas.insert(gas.end(), part1Gas.begin(), part1Gas.end());
    gas.erase(gas.begin(), gas.begin()+start);
    vector<int> part1Cost(cost.begin(), cost.begin()+start);
    cost.insert(cost.end(), part1Cost.begin(), part1Cost.end());
    cost.erase(cost.begin(), cost.begin()+start);
    
    currentGas[0] = gas[0];
    for(int i=1; i<N; ++i)
    {
        currentGas[i] = currentGas[i-1]-cost[i-1]+gas[i];
        if(currentGas[i] < cost[i]) return -1;
    }
    return start;

//    currentGas[0] = currentGas[N-1]-cost[N-1]+gas[0];
//    if(currentGas[0] < cost[0]) return -1;
//    for(int i=2; i<=start-1; ++i)
//    {
//        currentGas[i] = currentGas[i-1]-cost[i-1]+gas[i];
//        if(currentGas[i] < cost[i]) return -1;
//    }
//    return start;
}



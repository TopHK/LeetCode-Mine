/*************************************************************************
	> File Name: DeleteNodeInALinkedList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月15日 星期三 17时32分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

void deleteNode(ListNode* node)
{
    if(!node) return;
    ListNode* p = node->next;
    node->val = p->val;
    node->next = p->next;
    delete p;
}

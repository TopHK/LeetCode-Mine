/*************************************************************************
	> File Name: RemoveNthNodeFromEndOfList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 13时20分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(!head) return NULL;
    ListNode dummyNode(-1);
    ListNode* newHead = &dummyNode;
    newHead->next = head;
    ListNode* previous = newHead;
    ListNode* behind = newHead;

    while(n--) behind = behind->next;
    while(behind->next)
    {
        previous = previous->next;
        behind = behind->next;
    }
    ListNode* toBeDeleted = previous->next;
    previous->next = toBeDeleted->next;
    delete toBeDeleted;
    return newHead->next;
}

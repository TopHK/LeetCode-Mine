/*************************************************************************
	> File Name: RemoveLinkedListElements.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 19时36分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

ListNode* removeElements(ListNode* head, int val)
{
    if(!head) return NULL;
    ListNode dummy(-1);
    ListNode* newHead = &dummy;
    newHead->next = head;
    ListNode* previous = newHead;
    ListNode* behind = previous->next;

    while(behind)
    {
        if(behind->val == val)
        {
            previous->next = behind->next;
            delete behind;
            behind = previous->next;
        }
        else 
        {
            previous = behind;
            behind = behind->next;
        }
    }
    return newHead->next;
}

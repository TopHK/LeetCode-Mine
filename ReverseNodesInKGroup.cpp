/*************************************************************************
	> File Name: ReverseNodesInKGroup.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 08时50分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL) {}
};

class Solution
{
public:
    void reverseList(ListNode* head, ListNode** newHead, ListNode** newTail)
    {
        ListNode* tail = head;
        head = head->next;
        tail->next = NULL;
        *newTail = tail;
        ListNode* previous = head->next;

        while(previous)
        {
            head->next = tail;
            tail = head;
            head = previous;
            previous = previous->next;
        }
        head->next = tail;
        *newHead = head;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(k<=1 || !head || !head->next) return head;
        int size = 0;
        ListNode* p = head;
        while(p)
        {
            size++;
            p = p->next;
        }
        if(size < k) return head;
        int parts = size/k;
        ListNode dummy(-1);
        ListNode* dummyHead = &dummy;
        ListNode* tail = dummyHead;
        ListNode* head2 = head;
        ListNode* head3;
        
        for(int i=1; i<=parts; ++i)
        {
            p = head2;
            for(int j=1; j<k; ++j) p = p->next;
            head3 = p->next;
            p->next = NULL;
            ListNode *newHead2 = NULL;
            ListNode *newTail2 = NULL;
            reverseList(head2, &newHead2, &newTail2);
            tail->next = newHead2;
            tail = newTail2;
            head2 = head3;
            if(i == parts) tail->next = head2;
        }
        return dummyHead->next;
    }
};

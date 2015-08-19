/*************************************************************************
	> File Name: ReverseLinkedList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 22时51分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseList(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode* previous = head;
    ListNode* behind = head->next;
    previous->next = NULL;
    head = behind;

    while(behind->next)
    {
        head = behind->next;
        behind->next = previous;
        previous = behind;
        behind = head;
    }
    head->next = previous;
    return head;
}

ListNode* reverseList2(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode* previous = head;
    ListNode* behind = previous->next; 
    previous->next = NULL;
    head = reverseList2(behind);
    behind->next = previous;

    return head;
}

ListNode* head;
ListNode* createList(ListNode* head)
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    head = node1;
    ListNode* p = head;
    p->next = node2;
    return head;
}

void print(ListNode* head)
{
    ListNode* p = head;
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    head = createList(head);
    head = reverseList2(head);
    print(head);

    return 0;
}



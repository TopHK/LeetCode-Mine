/*************************************************************************
	> File Name: IntersectionOfTwoLinkedLists.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 18时35分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if(!headA || !headB) return NULL;
    int sizeOfListA = 0;
    int sizeOfListB = 0;
    ListNode* pOfListA = headA;
    while(pOfListA)
    {
        sizeOfListA++;
        pOfListA = pOfListA->next;
    }
    ListNode* pOfListB = headB;
    while(pOfListB)
    {
        sizeOfListB++;
        pOfListB = pOfListB->next;
    }

    int diffOfSize;
    if(sizeOfListA < sizeOfListB)
    {
        diffOfSize = sizeOfListB-sizeOfListA;
        pOfListB = headB;
        while(diffOfSize--)
            pOfListB = pOfListB->next;
        pOfListA = headA;
    }
    else if(sizeOfListA > sizeOfListB)
    {
        diffOfSize = sizeOfListA-sizeOfListB;
        pOfListA = headA;
        while(diffOfSize--)
            pOfListA = pOfListA->next;
        pOfListB = headB;
    }
    else 
    {
        pOfListA = headA;       
        pOfListB = headB;       
    }

    while(pOfListA && pOfListA!=pOfListB)
    {
        pOfListA = pOfListA->next;
        pOfListB = pOfListB->next;
    }
    return pOfListA;
}

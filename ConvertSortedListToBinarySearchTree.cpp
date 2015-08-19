/*************************************************************************
	> File Name: ConvertSortedListToBinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 17时56分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

TreeNode* convertCore(ListNode* head)
{
    if(!head) return NULL;
    TreeNode* root;
    if(!head->next)
    {
        root = new TreeNode(head->val);
        return root;
    }

    ListNode* p = head;
    ListNode* lastOfPart1;
    ListNode* q = head;

    while(q && q->next)
    {
        q = q->next->next;
        lastOfPart1 = p;
        p = p->next;
    }
    root = new TreeNode(p->val);
    lastOfPart1->next = NULL;
    root->left = convertCore(head);
    root->right = convertCore(p->next);
    delete p;
    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    TreeNode* root = convertCore(head);
    return root;
}

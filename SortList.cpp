/*************************************************************************
	> File Name: SortList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月02日 星期四 22时07分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution 
{
public:
    /*
    ListNode* forward(ListNode* head, int step)
    {
        ListNode* p = head;
        while(step--) p = p->next;
        return p;
    }

    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode dummyNode(-1);
        ListNode* newHead = &dummyNode;
        newHead->next = head;
        int left;
        ListNode* pLeft;
        int right;
        ListNode* pRight;
        int middle;
        ListNode* pMiddle;
        int current = 1;
        ListNode* currentNode = head->next;

        while(currentNode)
        {
            int currentVal = currentNode->val;
            ListNode* nextNode = currentNode->next;
            left = 0;
            pLeft = head;
            right = current-1;
            pRight = forward(head, right);

            while(left <= right)
            {
                middle = left+((right-left)>>1);
                pMiddle = forward(pLeft, middle-left);
                if(pMiddle->val > currentVal)
                {
                    right = middle-1;
                    if(left <= right) pRight = forward(pLeft, right-left);
                    else 
                    {
                        pLeft = forward(newHead, right+1);
                        break;
                    }
                }
                else if(pMiddle->val < currentVal)
                {
                    left = middle+1;
                    if(left <= right) pLeft = pMiddle->next; 
                    else break;
                }
                else break;
            }
            if(pLeft != currentNode)
            {
                ListNode* insertNode = forward(head, current-1);
                insertNode->next = nextNode;
                currentNode->next = pLeft->next;
                pLeft->next = currentNode;               
            }
            current++;
            currentNode = nextNode;
            head = newHead->next;
        }
        return newHead->next;
    }
    */

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(!head1) return head2;
        else if(!head2) return head1;
        ListNode dummyNode(-1);
        ListNode* newHead = &dummyNode;
        ListNode* current = newHead;
        ListNode* p = head1;
        ListNode* q = head2;

        while(p && q)
        {
            if(p->val <= q->val)
            {
                current->next = p;
                p = p->next;
            }
            else if(p->val > q->val)
            {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }
        if(p) current->next = p;
        else if(q) current->next = q;
        return newHead->next;
    }
    
    /*
    ListNode* mergeSort(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* p = head;
        ListNode* previous;
        ListNode* q = head;
        while(q && q->next)
        {
            previous = p;
            p = p->next;
            q = q->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = previous->next;
        previous->next = NULL;
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        head = merge(head1, head2);
        return head;
    }
    */

    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next) return head;       
        ListNode* p = head;
        ListNode* previous;
        ListNode* q = head;
        while(q && q->next)
        {
            previous = p;
            p = p->next;
            q = q->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = previous->next;
        previous->next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        head = merge(head1, head2);
        return head; 
    }
};

ListNode* createList(const vector<int>& nums)
{
    ListNode* head = NULL;
    if(nums.empty()) return head;
    head = new ListNode(nums[0]);
    ListNode* p = head;

    for(int i=1; i<nums.size(); ++i)
    {
        ListNode* temp = new ListNode(nums[i]);
        p->next = temp;
        p = temp;
    } 
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
    int arr[] = {3, 2, 4, 8, 10, 7, 5, 3, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    Solution sol;
    ListNode* head = createList(nums);
    head = sol.sortList(head);
    print(head);
    return 0;
}

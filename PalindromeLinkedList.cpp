/*************************************************************************
	> File Name: PalindromeLinkedList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月14日 星期二 09时12分43秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution 
{
public:
    int getSize(ListNode* head)
    {
        int size = 0;
        while(head)
        {
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* reverseList(ListNode* head)
    {
        if(!head->next) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        p1->next = NULL;
        ListNode* q = p2->next;
        ListNode* newHead;
        while(q)
        {
            p2->next = p1;
            p1 = p2;
            p2 = q;
            q = p2->next;
        }
        p2->next = p1;
        newHead = p2;
        return newHead;
    }
    bool isEqual(ListNode* head, ListNode* head2)
    {
        while(head)
        {
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head)
    {
        if(!head || !head->next) return true;
        int size = getSize(head);
        ListNode* p = head;
        ListNode* head2;
        for(int i=1; i<=(size>>1)-1; ++i) p = p->next;
        head2 = p->next;
        p->next = NULL;
        if(size & 1) head2 = head2->next;
        head2 = reverseList(head2);
        return isEqual(head, head2);
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
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

void print(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1, 2, 2, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    ListNode* head = createList(nums);
    print(head);
    Solution sol;
    cout<<sol.isPalindrome(head)<<endl;

    return 0;
}

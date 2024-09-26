// @algorithm @lc id=100164 lang=cpp 
// @title palindrome-linked-list-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2])=false
// @test([1,2,2,1])=true
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 先检测一下是否是空的，空的应该也是属于回文的
        if(head == nullptr) return true;
        // 快慢遍历
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 得到链表的中间
        ListNode* mid = slow;
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        // 当下一个不为空的时候
        // 做一次反过滤得到一个相反的。
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        //然后就可以从l1和来ad和l2head就双指针检测
        ListNode* l1 = head;
        ListNode* l2 = pre;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};
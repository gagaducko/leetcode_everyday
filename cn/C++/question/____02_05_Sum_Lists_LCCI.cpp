// @algorithm @lc id=100188 lang=cpp 
// @title sum-lists-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 先创建一个新链表
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        // 需要一个进位标志
        bool needAdd = false;
        // 遍历链表，但两个链表都不为空的时候
        while(l1 || l2){
            // 从head的下一个开始感觉会好一点
            head->next = new ListNode(0);
            head = head->next;
            int sum = 0;
            // l1有东西的话加上
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            // l2有东西的还加上
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            // 需要进位的还加上
            if(needAdd){
                sum += 1;
                needAdd = false;
            }
            // 如果最后的sum大于10了就设置一下进位符号
            if(sum >= 10){
                needAdd = true;
                sum -= 10;
            }
            head->val = sum;
        }
        // finally should check where need to add as well
        if(needAdd){
            head->next = new ListNode(0);
            head = head->next;
            head->val = 1;
        }
        return p->next;
    }
};
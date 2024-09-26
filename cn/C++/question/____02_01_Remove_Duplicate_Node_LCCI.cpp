// @algorithm @lc id=100163 lang=cpp 
// @title remove-duplicate-node-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,3,2,1])=[1,2,3]
// @test([1,1,1,1,2])=[1,2]
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        // 做个两次遍历就行了
        ListNode * h = head;
        while(h) {
            ListNode * p = h;
            while(p->next) {
                if(h->val == p->next->val) {
                    p->next = p->next->next;
                } else {
                    p = p->next;
                }
            }
            h = h->next;
        }
        return head;
    }
};
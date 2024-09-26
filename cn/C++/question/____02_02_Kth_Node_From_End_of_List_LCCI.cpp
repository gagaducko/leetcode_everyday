// @algorithm @lc id=1000007 lang=cpp 
// @title kth-node-from-end-of-list-lcci


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
    int kthToLast(ListNode* head, int k) {
        
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        while (p != NULL) {
            p = p->next;
            q = q->next;
        }
        return q->val;
    }
};
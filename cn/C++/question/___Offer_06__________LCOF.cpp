// @algorithm @lc id=100282 lang=cpp 
// @title cong-wei-dao-tou-da-yin-lian-biao-lcof


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
    vector<int> reversePrint(ListNode* head) {
        // 直接调vector的库
        // vector<int> ans;
        // while(head != NULL) {
        //     ans.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        vector<int> ans;
        while(head != NULL) {
            ans.insert(ans.begin(), head->val);
            head = head->next;
        }
        return ans;
    }
};
// @algorithm @lc id=3477 lang=cpp 
// @title minimum-operations-to-make-binary-array-elements-equal-to-one-ii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([0,1,1,0,1])=4
// @test([1,0,0,0])=1
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();
        // 初始化当前状态
        int currentState = 0; // 0表示目标状态为1，1表示目标状态为0
        for (int i = 0; i < n; ++i) {
            // 当前元素与目标状态不一致，需要反转
            if (nums[i] == currentState) {
                operations++;
                // 反转目标状态
                currentState ^= 1; // 切换状态
            }
        }
        return operations;
    }
};
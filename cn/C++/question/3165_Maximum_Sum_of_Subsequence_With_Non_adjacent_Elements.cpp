// @algorithm @lc id=3423 lang=cpp 
// @title maximum-sum-of-subsequence-with-non-adjacent-elements


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,5,9],[[1,-2],[0,-3]])=21
// @test([0,-1],[[0,-5]])=0
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Function to compute the maximum sum of non-adjacent elements
        auto computeMaxSum = [&](vector<int>& arr) {
            int n = arr.size();
            if (n == 0) return 0;

            vector<int> dp(n);
            dp[0] = max(0, arr[0]);  // 第一个元素的最大和
            if (n > 1) {
                dp[1] = max(dp[0], arr[1]);  // 前两个元素的最大和
            }

            // 计算每个位置的最大和
            for (int i = 2; i < n; i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
            }
            return dp[n - 1];  // 返回最后一个位置的最大和
        };

        long long totalSum = 0;  // 用于存储所有查询的答案之和
        int maxSum = computeMaxSum(nums);  // 初始的最大和

        // 处理每个查询
        for (const auto& query : queries) {
            int index = query[0];
            int newValue = query[1];
            if (index >= 0 && index < nums.size()) {
                nums[index] = newValue;  // 更新 nums 数组

                // 重新计算更新后的最大和
                maxSum = computeMaxSum(nums);
            }
            totalSum = (totalSum + maxSum) % MOD;  // 更新答案之和
        }

        return totalSum;  // 返回最终的答案
    }
};
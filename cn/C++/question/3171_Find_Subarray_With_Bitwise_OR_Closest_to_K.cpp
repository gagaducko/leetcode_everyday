// @algorithm @lc id=3436 lang=cpp 
// @title find-subarray-with-bitwise-or-closest-to-k


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,4,5],3)=0
// @test([1,3,1,3],2)=1
// @test([1],10)=9
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // 找到一个子数组，其按位或的结果与给定的整数k最接近
        int n = nums.size();
        // 初始化结果为最大整数，方便存储最小差值
        int ans = INT_MAX;
        // 双重循环遍历所有子数组
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                // 计算当前子数组的按位或结果
                cur |= nums[j];
                // 更新最小差值
                ans = min(ans, abs(cur - k));
            }
        }
        return ans;
    }
};
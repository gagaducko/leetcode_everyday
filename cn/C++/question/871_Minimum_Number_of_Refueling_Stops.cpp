// @algorithm @lc id=902 lang=cpp 
// @title minimum-number-of-refueling-stops


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(1,1,[])=0
// @test(100,1,[[10,100]])=-1
// @test(100,10,[[10,60],[20,30],[30,30],[60,40]])=2
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 这是一个典型的动态规划问题
        int n = stations.size();
        // dp[i] 表示加油 i 次能达到的最远距离
        vector<long> dp(n + 1);
        // 初始状态，没有加油时，最远能走 startFuel 的距离
        dp[0] = startFuel;
        // 遍历每一个加油站
        for (int i = 0; i < n; i++) {
            // 从后往前更新 dp 数组，防止重复加油
            // 如果加油 j 次能达到当前加油站
            for (int j = i; j >= 0 && dp[j] >= stations[i][0]; j--) {
                // 更新加油 j+1 次能达到的最远距离
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
        for (int i = 0; i <= n; i++) {
            // 检查 dp 数组，找到能够达到目标的最小加油次数
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};
// @algorithm @lc id=2031 lang=cpp 
// @title egg-drop-with-2-eggs-and-n-floors


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(2)=2
// @test(100)=14
class Solution {
public:
    int twoEggDrop(int n) {
        // 动态规划数组 dp[i] 表示 i 层楼需要的最小次数
        vector<int> dp(n + 1, 0);
        
        // 初始化dp，填充最坏情况
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;  // 最坏情况下用线性扫描
        }
        
        // 对于2个鸡蛋的情况，使用逆向推理
        for (int i = 2; i <= n; ++i) {
            for (int x = 1; x <= i; ++x) {
                dp[i] = min(dp[i], 1 + max(x - 1, dp[i - x]));
            }
        }
        
        return dp[n];
    }
};
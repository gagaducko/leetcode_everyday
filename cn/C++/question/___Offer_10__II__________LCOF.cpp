// @algorithm @lc id=100277 lang=cpp 
// @title qing-wa-tiao-tai-jie-wen-ti-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    int numWays(int n) {
        // 0的时候就是1种
        if (n == 0) return 1;
        // 1的时候也是1种
        if (n == 1) return 1;
        // 2的时候就是两种，可以两个1步，可以一次两步
        if (n == 2) return 2;
        // 之后可以在前一次的基础上，来进行动态规划
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
};
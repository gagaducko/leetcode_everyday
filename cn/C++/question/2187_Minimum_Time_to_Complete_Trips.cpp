// @algorithm @lc id=2294 lang=cpp 
// @title minimum-time-to-complete-trips


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3],5)=3
// @test([2],1)=2
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // 利用二分查找来寻找满足条件的最小时间
        // 通过计算每辆车在给定时间内能完成的旅行次数来逐步缩小时间范围
        long long left = 1, right = 1e14;
        // 二分查找
        while (left < right) {
            // 计算中间值
            // 计算可以完成的旅行次数
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for (auto t : time) {
                trips += mid / t;
            }
            if (trips >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
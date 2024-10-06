// @algorithm @lc id=134 lang=cpp 
// @title gas-station


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,4,5],[3,4,5,1,2])=3
// @test([2,3,4],[3,4,3])=-1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int current = 0;
        int start = 0;
        // 开始便利
        for (int i = 0; i < gas.size(); i++) {
            // 计算当前油量
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];
            // 如果当前油量小于0，则重新计算起点
            if (current < 0) {
                start = i + 1;
                current = 0;
            }
        }
        // 如果总油量小于0，则无法完成一圈，返回-1
        // 如果总油量大于等于0，则从起点开始可以完成一圈，返回起点
        return total >= 0 ? start : -1;
    }
};
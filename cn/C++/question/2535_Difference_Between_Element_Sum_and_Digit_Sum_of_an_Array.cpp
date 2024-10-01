// @algorithm @lc id=2624 lang=cpp 
// @title difference-between-element-sum-and-digit-sum-of-an-array


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,15,6,3])=9
// @test([1,2,3,4])=0
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;
        for (auto & num : nums) {
            elementSum += num;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};
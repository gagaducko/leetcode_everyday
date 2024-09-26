// @algorithm @lc id=100275 lang=cpp 
// @title shu-zu-zhong-zhong-fu-de-shu-zi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // use hash table
        // 貌似对于这一类要找重复的数字之类的，都可以用hashtable可以很快的找，就往桶里塞
        vector<int> hash(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = hash[nums[i]] + 1;
            if (hash[nums[i]] == 2) {
                return nums[i];
            }
        }
    }
};
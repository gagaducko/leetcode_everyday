// @algorithm @lc id=3444 lang=cpp 
// @title find-the-number-of-good-pairs-ii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,3,4],[1,3,4],1)=5
// @test([1,2,4,12],[2,4],3)=2
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] % (nums2[j] * k) == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @algorithm @lc id=100184 lang=cpp 
// @title palindrome-permutation-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("tactcoa")=true
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        vector<int> cnt(128, 0);
        for (auto c : s) {
            cnt[c]++;
        }
        int i = 0;
        for(auto c : cnt) {
            if (c % 2 == 1) {
                i++;
            }
        }
        if(i > 1) {
            return false;
        }
        return true;
    }
};
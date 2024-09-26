// @algorithm @lc id=100159 lang=cpp 
// @title check-permutation-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("abc","bca")=true
// @test("abc","bad")=false
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        // 1. 长度不同
        if(s1.size()!=s2.size()) {
            return false;
        }

        int n =s1.size();
        vector<int> cnt(26,0);
        // 就用一个桶其实就行
        // 一边加一边减少
        for(int i = 0; i < n; i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]!=0) {
                return false;
            }
        }
        return true;
    }
};
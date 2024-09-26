// @algorithm @lc id=100158 lang=cpp 
// @title is-unique-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("leetcode")=false
// @test("abc")=true
class Solution {
public:
    bool isUnique(string astr) {
        vector<int> flag(26, 0);
        for(int i = 0; i < astr.length(); i++) {
            flag[astr[i]-'a']++;
            if(flag[astr[i]-'a'] == 2) {
                return false;
            }
        }
        return true;
    }
};
// @algorithm @lc id=100162 lang=cpp 
// @title string-rotation-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("abcd","acdb")=false
class Solution {
public:
    bool contains(string a, string b) {
        if (b.size() > a.size()) {
            return false;
        }
        for (size_t i = 0; i <= a.size() - b.size(); ++i) {
            if (a.substr(i, b.size()) == b) {
                return true;
            }
        }
        return false;
    }
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        if (s1.empty()) {
            return;
        }
        string combine = s2+ s2;
        if (contains(combine, s1)) {
            return true;
        }
        return false;
    }
};
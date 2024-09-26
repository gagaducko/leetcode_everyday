// @algorithm @lc id=100161 lang=cpp 
// @title compress-string-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("aabcccccaaa")="a2b1c5a3"
// @test("abbccd")="abbccd"
class Solution {
public:
    string compressString(string S) {
        string res;
        int n = S.size();
        int cnt = 1;
        int i = 0;
        while (i < n)  {
            for (int j = i + 1; j < n; j++) {
                if (S[j] != S[j - 1]) {
                    break;  
                }
                cnt++;
            }
            res += S[i];
            res += to_string(cnt);
            i = i + cnt;
            cnt = 1;
        }
        return res.size() < n ? res : S;
    }
};
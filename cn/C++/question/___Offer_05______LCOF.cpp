// @algorithm @lc id=100280 lang=cpp 
// @title ti-huan-kong-ge-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        // append可以追加多个字符
        // push_back只能追加一个
        string snew = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                snew.push_back(s[i]);
            } else {
                snew.append("%20");
            }
        }
        return snew;
    }
};
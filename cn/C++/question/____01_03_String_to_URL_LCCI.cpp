// @algorithm @lc id=100160 lang=cpp 
// @title string-to-url-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("Mr John Smith ",13)="Mr%20John%20Smith"
// @test("               ",5)="%20%20%20%20%20"
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        for(int i = 0; i < length; i++)
        {
            if(S[i]==' ') {
                res+="%20";
            } else {
                res+=S[i];
            }
        }
        return res;
    }
};
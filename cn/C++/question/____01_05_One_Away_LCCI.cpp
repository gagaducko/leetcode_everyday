// @algorithm @lc id=1000006 lang=cpp 
// @title one-away-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("a","b")=true
// @test("ab","ac")=true
class Solution {
public:
    bool oneEditAway(string first, string second) {
        // 首先是两个size一样的情况下，那就只能是替换
        if(first.size() == second.size()){
            int count = 0;
            for(int i = 0; i < first.size(); i++){
                if(first[i] != second[i]){
                    count++;
                }
                if(count > 1){
                    return false;
                    break;
                }
            }
            // 只要不是大于1也就是说只要不同的字符数只有一个，那么就是可以替换的
            return true;
        }
        //当头一个比后一个要大1的时候，这个情况下就需要靠减少一个了
        else if(first.size() - second.size() == 1){
            int count = 0;
            int j = 0;
            for(int i = 0; i < second.size(); i++){
                if(first[i + j] != second[i]){
                    count++;
                    j++;
                    i--;
                }
                if(count > 1){
                    return false;
                    break;
                }
            }
            return true;
        }
        else if(second.size() - first.size() == 1){
            int count = 0;
            int j = 0;
            for(int i = 0; i < first.size(); i++){
                if(first[i] != second[i + j]){
                    count++;
                    j++;
                    i--;
                }
                if(count > 1){
                    return false;
                    break;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};
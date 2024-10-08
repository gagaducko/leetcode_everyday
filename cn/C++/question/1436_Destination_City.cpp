// @algorithm @lc id=1547 lang=cpp 
// @title destination-city


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <unordered_set>
using namespace std;
// @test([["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]])="Sao Paulo"
// @test([["B","C"],["D","B"],["C","A"]])="A"
// @test([["A","Z"]])="Z"
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCities; // 用于存储所有起点城市
        for (auto& path : paths) {
            startCities.insert(path[0]); // 将起点城市插入到startCities中
        }
        for (auto& path : paths) {
            if (startCities.find(path[1]) == startCities.end()) { // 如果终点城市不在startCities中
                // 也就是说，这个终点城市是做不了起点的，那么它就是完全的终点城市
                return path[1]; // 返回终点城市
            }
        }
        return ""; // 如果没有找到终点城市，返回空字符串
    }
};
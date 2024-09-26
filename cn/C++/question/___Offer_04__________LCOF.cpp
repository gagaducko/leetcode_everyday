// @algorithm @lc id=100276 lang=cpp 
// @title er-wei-shu-zu-zhong-de-cha-zhao-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 直接从后往前翻吧
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) row--;
            else col++;
        }
        return false;
    }
};
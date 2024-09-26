// @algorithm @lc id=100186 lang=cpp 
// @title zero-matrix-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([[1,1,1],[1,0,1],[1,1,1]])=[[1,0,1],[0,0,0],[1,0,1]]
// @test([[0,1,2,0],[3,4,5,2],[1,3,1,5]])=[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 先靠遍历来做一个小的判断
        vector<bool> row(m, false), col(n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // 如果说出现了0，那就先将这个0所在的row和col先给置为true
                    row[i] = col[j] = true;
                }
            }
        }
        // 最后就可以看，只要是有true的，那就将原本的矩阵的东西变为0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};
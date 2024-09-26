// @algorithm @lc id=100279 lang=cpp 
// @title ju-zhen-zhong-de-lu-jing-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 得到m与n
        int m = board.size();
        int n = board[0].size();
        // 创建一个visited的数组矩阵来存放是否有过该点，避免重复
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 然后就可以开始深度优先遍历，能遍历到就返回true
                if (dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int
        j, int k) {
        // 深度优先的遍历就靠着这个word、board、visited的引用一级级的递归
        // 如果都归完了还是没有找到，那就是false
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || word[k] != board[i][j]) {
            return false;
        }
        // 如果找到了，就返回true
        if (k == word.size() - 1) {
            return true;
        }
        // 然后就是正常的深度优先遍历
        visited[i][j] = true;
        // 递归看向上还是向下还是向左还是向右，反正能归到就行
        bool res = dfs(board, visited, word, i + 1, j, k + 1) 
        || dfs(board, visited, word, i - 1, j, k + 1) 
        || dfs(board, visited, word, i, j + 1, k + 1) 
        || dfs(board, visited, word, i,j - 1, k + 1);
        visited[i][j] = false;
        return res;
    }
};
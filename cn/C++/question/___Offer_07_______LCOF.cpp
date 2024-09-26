// @algorithm @lc id=100283 lang=cpp 
// @title zhong-jian-er-cha-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 需要注意的是要判断关于empty的情况，也就是null的时候。
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        // 先找到根节点，也就是先序的第一个
        TreeNode* root = new TreeNode(preorder[0]);
        // 遍历inorder，找到和preorder[0]相同的，对preorder和inorder进行分割，就能得到左子树和右子树，并递归该过程
        int i;
        for (i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                break;
            }
        }
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
        vector<int> right_preorder(preorder.begin() + i + 1, preorder.end());
        vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};
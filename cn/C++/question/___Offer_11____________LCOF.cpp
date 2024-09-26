// @algorithm @lc id=100278 lang=cpp 
// @title xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size = numbers.size();
        int l = 0, r = size - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 进行二分查找，直接看中间的数字和最右边的数字有没有一个降序关系。
            // 如果说有一个降序关系，那么说明还在旋转的地方，直接把l调整到mid+1
            // 如果说是一个升序关系，那么就说明这个mid已经在正常的范围里了，直接把r给调整为mid
            // 如果说两个相等却还没有跳出这个循环的话，那就r--直到能跳出循环。
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]) {
                r = mid;
            } else {
                r--;
            }
        }
        return numbers[l];
    }
};
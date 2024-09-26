// @algorithm @lc id=100274 lang=cpp 
// @title fei-bo-na-qi-shu-lie-lcof


#include <iostream>
#include <vector>
#include <string>
// #include "algm/algm.h"
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int fib0 = 0;
        int  fib1 = 1;
        for (int i = 2; i <= n; ++i) {
            int fibtemp = fib1;
            fib1 = (fib0 + fib1) % 1000000007;
            fib0 = fibtemp;
        }
        return (fib1 % 1000000007);
    }
};
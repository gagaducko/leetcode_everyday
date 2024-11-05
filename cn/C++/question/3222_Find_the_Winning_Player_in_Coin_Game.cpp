// @algorithm @lc id=3511 lang=cpp 
// @title find-the-winning-player-in-coin-game


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(2,7)="Alice"
// @test(4,11)="Bob"
class Solution {
public:
    string losingPlayer(int x, int y) {
        while (true) {
            // Alice 的回合
            if (x > 0 && y >= 4) {
                x -= 1;  // 拿一枚75的硬币
                y -= 4;  // 拿四枚10的硬币
            } else if (y >= 11) {
                y -= 11; // 只拿十个10的硬币
            } else {
                return "Bob";  // Bob 无法继续操作，Bob 赢
            }

            // Bob 的回合
            if (x > 0 && y >= 4) {
                x -= 1;  // 拿一枚75的硬币
                y -= 4;  // 拿四枚10的硬币
            } else if (y >= 11) {
                y -= 11; // 只拿十个10的硬币
            } else {
                return "Alice";  // Alice 无法继续操作，Alice 赢
            }
        }
    }
};
// @algorithm @lc id=100169 lang=cpp 
// @title min-stack-lcci
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push_back(x);
        if (min.empty() || x <= min.back()) {
            min.push_back(x);
        } else {
            min.push_back(min.back());
        }
    }
    
    void pop() {
        min.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min.back();
    }
};
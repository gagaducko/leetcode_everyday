// @algorithm @lc id=100195 lang=cpp 
// @title stack-of-plates-lcci
#include <iostream>
#include <vector>
using namespace std;

class StackOfPlates {
private:
    vector<vector<int>> stacks;
    int cap;
public:
    StackOfPlates(int cap) {
        this->cap = cap;
    }
    
    void push(int val) {
        if (cap == 0) {
            return;
        }
        if (stacks.empty() || stacks.back().size() == cap) 
            stacks.push_back({});
        stacks.back().push_back(val);

    }
    
    int pop() {
        if (stacks.empty()) {
            return -1;
        }
        int val = stacks.back().back();
        stacks.back().pop_back();
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        return val;
    }
    
    int popAt(int index) {
        if (index < 0 || index >= stacks.size()) {
            return -1;
        }
        int val = stacks[index].back();
        stacks[index].pop_back();
        if (stacks[index].empty()) {
            stacks.erase(stacks.begin() + index);
        }
        return val;
    }
};
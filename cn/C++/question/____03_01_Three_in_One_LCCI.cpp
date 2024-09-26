// @algorithm @lc id=100172 lang=cpp 
// @title three-in-one-lcci
#include <iostream>
#include <vector>
using namespace std;

class TripleInOne {
private:
    vector<int> data;
    int size_stack[3];
    int size;
public:
    TripleInOne(int stackSize) {
        data.resize(stackSize * 3);
        size = stackSize;
        size_stack[0] = size_stack[1] =size_stack[2] = 0;
    }
    
    void push(int stackNum, int value) {
        size_stack[stackNum]++;
        data[stackNum * size + size_stack[stackNum] - 1] = value;
        return;
    }
    
    int pop(int stackNum) {
        if(size_stack[stackNum] == 0)
            return -1;
        size_stack[stackNum]--;
        return data[stackNum * size + size_stack[stackNum]];
    }
    
    int peek(int stackNum) {
        if(size_stack[stackNum] == 0)
            return -1;
        return data[stackNum * size + size_stack[stackNum] - 1];
    }
    
    bool isEmpty(int stackNum) {
        return size_stack[stackNum] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
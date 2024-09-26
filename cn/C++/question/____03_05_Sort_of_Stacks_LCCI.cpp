// @algorithm @lc id=100173 lang=cpp 
// @title sort-of-stacks-lcci
#include <iostream>
#include <stack>
using namespace std;

class SortedStack {
private:
    stack<int> s, t;

public:
    SortedStack() {

    }
    
    void push(int val) {
        if(s.empty() || val <= s.top()) {
            s.push(val);
        } else {
            while(!s.empty() && val > s.top()) {
                t.push(s.top());
                s.pop();
            }
            s.push(val);
            while(!t.empty()) {
                s.push(t.top());
                t.pop();
            }
        }
    }
    
    void pop() {
        if(!s.empty()) {
            s.pop();
        }
    }
    
    int peek() {
        if(!s.empty()) {
            return s.top();
        }
        return -1;
    }
    
    bool isEmpty() {
        if(s.empty()) {
            return true;
        }
        return false;
    }
};
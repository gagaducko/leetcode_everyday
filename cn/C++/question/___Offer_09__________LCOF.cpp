// @algorithm @lc id=100273 lang=cpp 
// @title yong-liang-ge-zhan-shi-xian-dui-lie-lcof
#include <stack>
using namespace std;

class CQueue {
private:
    // 两个stack，一个是inStack，一个是outStack
    stack<int> inStack, outStack;
    // 增加一个inforout的函数
    // 当inStack非空的时候呢，就push其top到outStack里面去，并对其进行pop。
    // 这个样子相当于就把整个数组给倒过来了
    void inForout() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    CQueue() {
    }
    

    // 要往队列尾部插入，那就直接给inStack插入就行
    void appendTail(int value) {
        inStack.push(value);
    }
    
    // 要把队列头部删除，那就先从inStack搞个outStack出来，就直接看是不是empty就行
    // 因为如果说不是empty的话，那就说明前面的还没有pop完
    // 而如果说，前面的pop完了，那就从instack里面pop过来最新的
    // 如果说在这个情况下inStack里面都没有东西，说明队列是空的，就没法pop了
    int deleteHead() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                return -1;
            }
            inForout();
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
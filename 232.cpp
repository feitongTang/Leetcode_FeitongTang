/*
    link: https://leetcode.com/problems/implement-queue-using-stacks/
*/

/*
    comment:
    the first stack is only used as a temp buffer when pushed
    the other stack simulates the FIFO order
*/

/*
    status:
    Runtime: 18.95%
    Memory Usage: 13.01%
*/

#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!mainStack.empty()) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        tempStack.push(x);
        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
    }
    
    int pop() {
        int temp = mainStack.top();
        mainStack.pop();
        return temp;
    }
    
    int peek() {
        return mainStack.top();
    }
    
    bool empty() {
        return mainStack.empty();
    }
    
    stack<int> tempStack;
    stack<int> mainStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
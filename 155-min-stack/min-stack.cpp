#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {}

    stack<long long> ap;  
    long long mini = LLONG_MAX;
    long long x;

    void push(int val) {
        if(ap.empty()) {
            mini = val;
            ap.push(val);
        } else {
            if(val >= mini) {
                ap.push(val);
            } else {
                ap.push((2LL * val) - mini); 
                mini = val;
            }
        }
    }

    void pop() {
        if(ap.empty()) return;
        x = ap.top();
        ap.pop();
        if(x < mini) {
            mini = (2LL * mini - x); // restore previous min
        }
    }

    int top() {
        if(ap.empty()) return -1;
        x = ap.top();
        if(x >= mini) return (int)x;
        return (int)mini; 
    }

    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

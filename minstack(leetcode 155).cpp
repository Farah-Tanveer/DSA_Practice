//minstack using one stack
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> minst;

    void push(int val) {
        s.push(val);
        if(minst.empty() || val <= minst.top())
            minst.push(val);
    }

    void pop() {
        if(s.empty()) return;

        if(!minst.empty() && s.top() == minst.top())
            minst.pop();

        s.pop();
    }

    int top() {
        if(s.empty()) return -1;  // or throw error
        return s.top();
    }

    int getMin() {
        if(minst.empty()) return -1;
        return minst.top();
    }
};
// using one stack
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minVal = val;
        }
        else if(val >= minVal) {
            st.push(val);
        }
        else {
            long long encoded = 2LL * val - minVal;
            st.push(encoded);
            minVal = val;
        }
    }

    void pop() {
        if(st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if(topVal < minVal) {
            minVal = 2LL * minVal - topVal;
        }
    }

    int top() {
        if(st.empty()) return -1;

        long long topVal = st.top();

        if(topVal < minVal)
            return minVal;

        return topVal;
    }

    int getMin() {
        if(st.empty()) return -1;
        return minVal;
    }
};

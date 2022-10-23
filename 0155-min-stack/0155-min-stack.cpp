class MinStack {
public:
    int a[300001];
    int x;
    MinStack() {
        x = 0;
    }
    
    void push(int val) {
        a[x++] = val;
    }
    
    void pop() {
        x--;
    }
    
    int top() {
        return a[x - 1];
    }
    
    int getMin() {
        int mn = INT_MAX;
        for(int i=0; i<x; i++) {
            mn = min(mn, a[i]);
        }
        return mn;
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
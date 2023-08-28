// Question Link - https://leetcode.com/problems/implement-stack-using-queues/

// Solution - 

class MyStack {
public:
    queue<int> q1, q2;
    int ttop;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        ttop = x;
    }
    
    int pop() {
        
        while((int)q1.size() != 1){
            ttop = q1.front();
            q2.push(ttop);
            q1.pop();
            
        }
        
        int ans = q1.front();
        q1 = q2;
        queue<int>emp;
        swap(q2, emp);
        
        return ans;
    }
    
    int top() {
        return ttop;
    }
    
    bool empty() {
        return q1.empty();
    }
};

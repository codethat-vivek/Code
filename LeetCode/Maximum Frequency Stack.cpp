// Question Link - https://leetcode.com/problems/maximum-frequency-stack/

// Solution - 

class Container{
    public:
    int freq, position, val;
    Container(int f, int p, int v){
        freq = f;
        position = p;
        val = v;
    }
};

bool operator < (Container const &c1, Container const &c2){
    if(c1.freq < c2.freq)
        return true;
    if(c1.freq == c2.freq)
        return c1.position < c2.position;
    return false;
    
}

class FreqStack {
public:
    unordered_map<int, int>um;
    priority_queue<Container>pq;
    int pos;
    FreqStack() {
        pos = 0;
        
    }
    
    void push(int val) {
        pos++;
        um[val]++;
        Container c(um[val], pos, val);
        pq.push(c);
    }
    
    int pop() {
        Container topMost = pq.top();
        pq.pop();
        um[topMost.val] --;
        return topMost.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

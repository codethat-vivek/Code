// Question Link - https://leetcode.com/problems/find-median-from-data-stream/

// Solution - 
 
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int>mx;
    priority_queue<int, vector<int>, greater<int>> mm;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (mx.empty() || mx.top() > num)
            mx.push(num);
        else
            mm.push(num);
        
        if(mx.size() > mm.size() + 1){
            mm.push(mx.top());
            mx.pop();
        }
        else if(mm.size() > mx.size() + 1){
            mx.push(mm.top());
            mm.pop();
        }
        
    }
    
    double findMedian() {
        if (mx.size() == mm.size())
            return (mm.top() + mx.top())/2.0;
        else{
            if(mx.size() > mm.size())
                return mx.top();
            else
                return mm.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

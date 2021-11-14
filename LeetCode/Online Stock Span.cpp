// Question Link - https://leetcode.com/problems/online-stock-span/

// Solution - 

class StockSpanner {
    stack<pair<int, int>>st;
    vector<int>idx;
    int i;
public:
    StockSpanner() {
        i = 0;
        idx.clear();
    }
    
    int helper(int price){
        if(st.empty())
            idx.push_back(-1);
        else if(st.top().first > price)
            idx.push_back(st.top().second);
        else{
            while(!st.empty() && st.top().first <= price)
                st.pop();
            if(st.empty())
                idx.push_back(-1);
            else
                idx.push_back(st.top().second);
        }
        st.push({price, i});
        return i-idx[idx.size()-1];
    }
    
    int next(int price) {
        int t = helper(price);
        i += 1;
        return t;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

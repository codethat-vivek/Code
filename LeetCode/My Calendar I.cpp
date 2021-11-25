// Question Link - https://leetcode.com/problems/my-calendar-i/

// Solution - 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define pii pair<int, int>

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
 
class MyCalendar {
    ordered_set intervals;
public:
    MyCalendar() {
        
    }
    bool intersection(pair<int, int> p, pair<int, int>q){
        if(q.first < p.second)return true;
        return false;
    }
    
    bool book(int start, int end) {
        if(intervals.size() == 0){
            intervals.insert({start, end});
            return true;
        }
        int idx = intervals.order_of_key({start, end});
        if(idx == 0){
            pair<int, int>next = *(intervals.find_by_order(idx));
            if(intersection({start, end}, next))return false;
            intervals.insert({start, end});
            return true;
        }
        if(idx == intervals.size()){
            pair<int, int>prev = *(intervals.find_by_order(idx-1));
            if(intersection(prev, {start, end}))return false;
            intervals.insert({start, end});
            return true;
        }
        pair<int, int>prev = *(intervals.find_by_order(idx-1));
        pair<int, int>next = *(intervals.find_by_order(idx));
        if(intersection(prev, {start, end}) || intersection({start, end}, next))
            return false;
        intervals.insert({start, end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

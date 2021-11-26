// Question Link - https://leetcode.com/problems/my-calendar-ii/

// Solution - 


#define pii pair<int, int>
class MyCalendarTwo {
    set<pii> intervals, twotimes;
public:
    MyCalendarTwo() {
        
    }
    bool intersection(pii p, pii q){
        if(max(p.first, q.first) < min(p.second, q.second))return true;
        return false;
    }
    bool book(int start, int end) {
        pii given = {start, end};
        for(auto it = twotimes.begin(); it != twotimes.end(); ++it){
            if(intersection(*it, given))return false;
        }
        for(auto it = intervals.begin(); it != intervals.end(); ++it){
            if(intersection(*it, given))
                twotimes.insert({max(it->first, given.first), min(it->second, given.second)});
        }
        intervals.insert(given);
        return true;
    }
};

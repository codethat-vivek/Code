// Question Link - https://leetcode.com/problems/seat-reservation-manager/

// Solution - 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class SeatManager {
public:
    ordered_set o_set;
    SeatManager(int n) {
        for(int i=1; i<=n; i++)
            o_set.insert(i);
    }
    
    int reserve() {  
        int t = *(o_set.find_by_order(0));
        o_set.erase(o_set.find(t));
        return t;
    }
    
    void unreserve(int seatNumber) {
        o_set.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

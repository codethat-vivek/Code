// Question Link - https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

// Solution - 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set_string tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int n = orders.size();
        ordered_set_string foods;
        
        for(auto each : orders)
            foods.insert(each[2]);
        
        int food_size = (int)foods.size();
        unordered_map<string, vector<int>>mp;
        
        for(auto each : orders){
            int idx = foods.order_of_key(each[2]);
            if(mp.find(each[1]) == mp.end()){
                vector<int>t(food_size, 0);
                mp[each[1]] = t;
            }
            ++mp[each[1]][idx];
            
        }
        // organizing my first row as asked in the question -> ["Table","Beef Burrito","Ceviche","Fried Chicken","Water"....]
        vector<vector<string>>ans;
        vector<string>vs;
        vs.push_back("Table");
        for(auto food : foods)
            vs.push_back(food);
        ans.push_back(vs);
        
        unordered_map<string, vector<int>>::iterator itr;
        vector<vector<int>>sorted_temp;
        for(itr = mp.begin(); itr != mp.end(); ++itr){
            vector<int>temp;
            temp.push_back(stoi(itr -> first));
            for(int i=0; i<(int)itr->second.size(); i++)
                temp.push_back(itr->second[i]);
            sorted_temp.push_back(temp);
        }
        sort(sorted_temp.begin(), sorted_temp.end());
        vector<vector<string>>sorted_temp_string;
        for(auto each : sorted_temp){
            sorted_temp_string.push_back({});
            for(auto ele : each)
                sorted_temp_string[sorted_temp_string.size()-1].push_back(to_string(ele));
            
        }
        for(auto each : sorted_temp_string)
            ans.push_back(each);
        return ans;
        
    }
};

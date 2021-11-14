// Question Link - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

// Solution - 


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stock price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       
       // nearest greater in left direction
       stack<pair<int, int>>st;
       vector<int>ans;
       for(int i=0; i<n; i++){
          if(st.empty())
              ans.push_back(-1);
          
          else if(st.top().first > price[i])
              ans.push_back(st.top().second);
          
          else{
                while(!st.empty() && st.top().first <= price[i])
                    st.pop();
                if(st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top().second);
          }
        
          st.push({price[i], i});
       }
       for(int i=0; i<n; i++){
           ans[i] = i-ans[i];
       }
       return ans;
    }
};


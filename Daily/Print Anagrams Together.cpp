/*
Question - Print Anagrams Together
  Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. 
  Look at the sample case for clarification.
  
  For example : 
  N = 5
  words[] = {act,god,cat,dog,tac}
  Output: 
  god dog
  act cat tac
  Explanation:
  There are 2 groups of
  anagrams "god", "dog" make group 1.
  "act", "cat", "tac" make group 2.
*/

// SOLUTION - 

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

//User function Template for C++
vector<vector<string> > Anagrams(vector<string>& s) 
{
    // Your Code Here
  
    // sorting would do the trick
    map <string, vector<string> > mp;
    for(int i=0; i<s.size(); i++){
        string x = s[i];
        sort(x.begin(), x.end());
        mp[x].push_back(s[i]);
    }
    int j = 0;
    vector<vector<string> > ans(mp.size());
    for(auto x : mp){
        auto v = x.second;
        for(int i=0; i<v.size(); i++){
            ans[j].push_back(v[i]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

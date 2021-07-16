/*
Given a string S, find the length of the longest substring without repeating characters.
For Example -
Input:
S = "geeksforgeeks"
Output: 7
Explanation: Longest substring is
"eksforg".
*/

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        unordered_set <char> mySet;
        int leftPointer = 0;
        int rightPointer = 0;
        int ans = 0;
        
        while(rightPointer != S.length()){
            if(mySet.find(S[rightPointer]) == mySet.end()){ // Not found condition
                mySet.insert(S[rightPointer]);
                rightPointer ++;
                // Need to know why this line is not getting compiled 
                // ans = max(mySet.size(), ans);
                if (mySet.size() >= ans)
                    ans = mySet.size();
            }
            else{
                mySet.erase(S[leftPointer]);
                leftPointer++;
            }
        }
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
} 

/*
You are given a vector V of size n. The vector hold pair of integers. 
Example V={(1,2),(3,4)...}. Now, you need to sum the second elements.
For Example -
Input:
1
5
1 2 3 4 5 6 7 8 9 10
Output:
30
*/

// SOLUTION -

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sum(vector<pair<int,int>>v);

void sum(vector<pair<int,int>>v)
{
    long long sum=0;
    //Your code here
    
    for(int i=0; i<v.size(); i++){
        sum += v[i].second;
    }
    
    cout<<sum;
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<pair<int,int>>v; //Making a vector that holds pairs
	    for(int i=0;i<n;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        v.push_back(make_pair(x,y)); //Pushing a pair in the vector
	    } 
	    
	   sum(v); //The sum function
	   
	}
	return 0;
}

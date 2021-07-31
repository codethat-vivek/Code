// Question Link - https://www.codechef.com/problems/FRGTNLNG

// Solution - 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, k;
	while(t--){
	    cin >> n >> k;
	    string arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int ele;
	    string x;
	    set<string>s;
	    for(int i=0; i<k; i++){
	        cin >> ele;
	        for(int j=0; j<ele; j++){
	            cin >> x;
	            s.insert(x);
	        }
	    }
	    for(int i=0; i<n; i++){
	        if(s.find(arr[i]) != s.end())
	            cout << "YES ";
	        else
	            cout << "NO ";
	    }
	    cout << endl;
	}
	return 0;
}

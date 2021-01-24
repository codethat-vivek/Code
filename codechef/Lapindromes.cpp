// Question Link - https://www.codechef.com/problems/LAPIN

// Solution Link - https://www.codechef.com/viewsolution/36702132

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int n = s.length();
	    int left[26] = {0}, right[26] = {0};
	    bool var = true;
	    
	    for(int i=0; i<n/2; i++){
	        left[s[i] - 'a'] ++;
	    }
	    for(int i=(n+1)/2; i<n; i++){
	        right[s[i] - 'a'] ++;
	    }
	    
	    for(int i=0; i<26; i++){
	        if(left[i] != right[i]){
	            var = false;
	            break;
	        }
	    }
	    
	    if(var)
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	    
	}
	return 0;
}

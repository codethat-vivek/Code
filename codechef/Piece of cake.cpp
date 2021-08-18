// Question Link - https://www.codechef.com/problems/LCH15JAB

// Solution - 

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string s;
	while(t--){
	    cin >> s;
	    int arr[26] = {0};
	    for(int i=0; i<s.length(); i++){
	        arr[s[i]-'a'] ++;
	    }
	    sort(arr, arr+26);
	    int x = 0;
	    for(int i=0; i<26; i++){
	        if(i != 25)
	            x += arr[i];
	    }
	    if(x == arr[25])
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	}
	return 0;
}

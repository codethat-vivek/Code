// Question Link - https://www.codechef.com/problems/CHN09

// Solution - 

#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string s;
	while(t--){
	    cin >> s;
	    int cnt_a = 0, cnt_b = 0;
	    int i;
	    for(i=0; s[i] != '\0'; i++){
	        if(s[i] == 'a')
	            cnt_a ++;
	        else
	            cnt_b ++;
	    }
	    cout << min(cnt_a, cnt_b) << "\n";
	}
	return 0;
}

// Question Link - 
// https://www.codechef.com/problems/HS08TEST


// Solution link - https://www.codechef.com/viewsolution/31757442
// SOLUTION -

#include <iostream>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <sstream>

using namespace std;

int main() {
	
	int x;
	float bal;
	cin >> x >> bal;
	
	if(x % 5 == 0){
		
		if((x+0.5) < bal){
			bal = bal - (x+0.5);			
			cout << bal;
		}
		else{
			cout << bal;
		}
		
	}
	else{
		cout << bal;
	}
	
	return 0;
	
}

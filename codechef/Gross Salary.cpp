// Question Link - https://www.codechef.com/problems/FLOW011

// Solution Link - https://www.codechef.com/viewsolution/36702876

// SOLUTION - 

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	double salary, hra, da, gross_salary;
	while(t--){
	    cin >> salary;
	    if(salary < 1500){
	        hra = 0.1*salary;
	        da = 0.9*salary;
	    }
	    else{
	        hra = 500;
	        da = 0.98*salary;
	    }
	    
	    gross_salary = salary + hra + da;
	    
	    cout << setprecision(2) << fixed << gross_salary << "\n";
	    
	}
	return 0;
}

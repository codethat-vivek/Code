// Question Link - https://www.codechef.com/problems/CANDY123

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a, b;
	while(t--){
	    cin >> a >> b;
	    int i=1, j=2;
	    int chance = 1;
	    while(a >= 0 && b >= 0){
            if(chance == 1){
                a -= i;
                i += 2;
                chance = 2;
            }
            else if(chance == 2){
                b -= j;
                j += 2;
                chance = 1;
            }
	    }
	    if(chance == 1)
            cout << "Limak" << endl;
        else if(chance == 2)
            cout << "Bob" << endl;

	}
	return 0;
}

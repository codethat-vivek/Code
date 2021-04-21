// Question Link - https://www.codechef.com/COOK128B/problems/OROFAND

// SOLUTION - 


#include <bits/stdc++.h>
using namespace std;

#define ll long long

// ll stringToInt(string s){
//     ll ans = 0;
//     ll i = 0;
    
//     ll power = 1;
//     while (i < s.length()){
//         if(s[i] == '1'){
//             ans += power;
//         }
//         power *= 2;
//         i++;
//     }
//     return ans;
// }

// ll calculate(ll arr[], ll n){
//     // any Ai will have maximum of n bits
//     string s = "";
//     for(ll i=0; i<32; i++){
//         bool done = false;
//         for(ll j=0; j<n; j++){
            
//             ll x = arr[j] & (1 << i);
        
//             if(x > 0){
                
//                 s += to_string(1);
                
//                 done = true;
//                 break;
//             }
//         }
//         if (!done)
//             s += to_string(0);
//     }
    
    
//     ll ans = stringToInt(s);
//     return ans;
    
// }




// IDEA -
// Clearly first calculating AND of all the subarrays and then the OR of all the scores is same as the OR of every element.




int main()
{
    ll t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        ll arr[n];
        ll bit[32] = {0}; // Bit Array
	    for(ll i=0; i<n; i++){
	        cin >> arr[i];
	        for(ll j=0; j<31; j++){
	            ll x = arr[i] & (1 << j);
	            if(x > 0)
	                bit[j]++;
	        }
	    }
	    
	    // converting to decimal
	    
	    ll ans = 0;
	    for(ll i=0; i<31; i++){
	        if(bit[i])
	            ans += (1 << i);
	    }
        
        cout << ans << endl;

        while(q--){
            ll idx, val;
            cin >> idx >> val;
            
            // removing the element to be replaced 
            for(ll i=0; i<31; i++){
                ll x = arr[idx-1] & (1 << i);
                if(x > 0)
                    bit[i]--;
            }
            
            // adding the new value 
            for(ll i=0; i<31; i++){
                ll x = val & (1<<i);
                if (x > 0)
                    bit[i]++;
            }
            
            arr[idx-1] = val; 
            
            // converting to decimal
            ll ans = 0 ;
            for(ll i=0; i<31; i++){
                if(bit[i])
                    ans += (1 << i);
            }
            cout << ans << endl;
            
        }        
        
    }
    
}

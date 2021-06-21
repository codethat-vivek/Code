// Question Link - https://www.codechef.com/COOK130B/problems/WAV2
// June Cook Off
// Solution - 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const long long inf = 1e9+7;

int main()
{
    int n, q;
    int each;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //int neg = 0;
    for(int i=0; i<q; i++)
    {
        cin >> each;
        
        int lb = lower_bound(arr.begin(), arr.end(), each)-arr.begin();
        if(lb == n)
            cout << "POSITIVE" << endl;
        else if(arr[lb] == each)
            cout << "0" << endl;
        else if(n % 2 == 0 and lb % 2 == 0)
            cout << "POSITIVE" << endl;
        else
            cout << "NEGATIVE" << endl;
        
    }
    
    return 0;
}

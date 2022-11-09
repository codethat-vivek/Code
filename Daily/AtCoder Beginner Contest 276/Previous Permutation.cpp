// Question Link - https://atcoder.jp/contests/abc276/tasks/abc276_c

// Solution - 

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin >> v[i];
    
    int pos=0;
    for(int i=n-2; i>=0; i--){
        if(v[i] > v[i+1]){
            pos = i;
            break;
        }
    }
    //cout << "pos = " << pos << endl;
    if(pos == -1){
        reverse(v.begin(), v.end());
    }
    else{
        int i=pos+1;
        while(i < n && v[i] < v[pos])
            i++;
        //cout << "i = " << i << endl;
        swap(v[pos], v[i-1]);
        reverse(v.begin()+pos+1, v.end());
        
    }
    
    for(auto e : v)
        cout << e << " ";
    
}

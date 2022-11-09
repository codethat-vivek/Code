// Question Link - https://atcoder.jp/contests/abc276/tasks/abc276_b

// Solution - 

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    set<int> arr[n+1];
    
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    
    for(int i=1; i<n+1; i++){
        cout << (int)arr[i].size();
        vector<int>t(arr[i].begin(), arr[i].end());
        for(auto &e : t)
            cout << " " << e;
        cout << "\n";
    }
 
    return 0;
}

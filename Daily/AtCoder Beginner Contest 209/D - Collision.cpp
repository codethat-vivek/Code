// Question Link - https://atcoder.jp/contests/abc209/tasks/abc209_d

// Solution - 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int>arr[100001];

int main()
{
    
    int n, q, u, v;
    cin >> n >> q;
    
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    vector<int>dis(n+1, -1);
    
    queue<int>qq;
    qq.push(1);
    dis[1] = 0;
    while(!qq.empty()){
        int get = qq.front();
        qq.pop();
        for(int child : arr[get]){
            if(dis[child] == -1){
                dis[child] = dis[get]+1;
                qq.push(child);
            }
        }
    }
    
    for(int i=0; i<q; i++){
        cin >> u >> v;
        if(abs(dis[u]-dis[v]) % 2 == 0)
            cout << "Town" << endl;
        else
            cout << "Road" << endl;
    }
    
    return 0;
}

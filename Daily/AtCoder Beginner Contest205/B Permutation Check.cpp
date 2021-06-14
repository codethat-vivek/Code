// Question Link - https://atcoder.jp/contests/abc205/tasks/abc205_b

// Solution - 

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int v[n];
  string ans = "Yes";
  int arr[n] = {0};

  for(int i=0; i<n; i++){
    cin >> v[i];
    arr[v[i]-1]++;
  }
  for(int i=0; i<n; i++){
    if(arr[i] != 1)
    {
      ans = "No";
      break;
    }
  }

  cout << ans << endl;

}
